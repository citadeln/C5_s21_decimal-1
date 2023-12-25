#include "./../common/s21_ldec_common.h"
#include "./../private/s21_ldec_private.h"
#include "./../s21_ldecimal.h"

// Получаем бит в элементе по индексу, через сдвиг единицы вправо на нужное
// количество (index), и побитовую операцию И
#define GET_BIT(num_elem, index) (num_elem & (1U << index))

// Включаем (устанавливаем в 1) самый правый бит в элементе, через побитовую
// операцию ИЛИ
#define SET_BIT(num_elem) (num_elem |= 1)

/**
 * @brief Служебная структура, для передачи в параметры внутренних функций
 *
 * @param dividend - делимое (то число, которое делим)
 * @param divisor - делитель (то число, на которое делим)
 * @param remainder - временная переменная для хранения остатка от деления
 * @param int_result - результат целочисленного деления
 * @param result - итоговый результат
 * @param start_bit_idx - индекс первого, слева, не пустого бита (начало
 * числа).
 * @param curr_idx - текущий индекс элемента массива
 */
typedef struct {
  s21_ldecimal *dividend;
  s21_ldecimal *divisor;
  s21_ldecimal *remainder;
  s21_ldecimal *int_result;
  s21_ldecimal *result;

  int start_bit_idx;
  int curr_idx;
} args;

static void div(s21_ldecimal *num1, s21_ldecimal *num2, s21_ldecimal *result);
static void div_int(args *a);
static void div_bits(args *ar);
static void div_remains(args *a);
static void get_dividend_indexes(args *ar);
static void shift_left_one_bit(s21_ldecimal *value);
static void swap_nums(args *ar);
static void clear_num(s21_ldecimal *num);
static void set_result_sign(args *ar);

/**
 * @brief Деление двух чисел.
 *
 * @param num1 Первое число для деления
 * @param num2 Второе число для деления
 * @param result Результат деления
 * @return true - ок
 * @return false - ошибка (деление на ноль)
 */
bool s21_ldec_div(s21_ldecimal *num1, s21_ldecimal *num2,
                  s21_ldecimal *result) {
  if (!num1 || !num2 || !result) return false;
  int res = true;

  if (s21_ldec_is_zero(num2)) {
    clear_num(result);
    res = false;
  } else if (s21_ldec_is_zero(num1)) {
    clear_num(result);
  } else {
    div(num1, num2, result);
  }

  return res;
}

/**
 * @brief Главный алгоритм обработки деления. С начала устанавливаем знак для
 * результата. Потом выравниваем экспонента чисел, чтобы точка была под точкой.
 * (например 10 / 0.2 = 100 / 2 = 50). Производим целочисленное деление. Затем
 * работаем с остатком от деления, для получения дробной части. В конце
 * нормализуем числа, для удаления лишних нулей из дробной части результата.
 *
 * @param num1
 * @param num2
 * @param result
 */
static void div(s21_ldecimal *num1, s21_ldecimal *num2, s21_ldecimal *result) {
  s21_ldecimal int_result;
  s21_ldecimal remainder;
  args ar = {.dividend = num1,
             .divisor = num2,
             .remainder = &remainder,
             .int_result = &int_result,
             .result = result};

  set_result_sign(&ar);
  s21_ldec_make_exp_equal(num1, num2);

  div_int(&ar);
  div_remains(&ar);

  s21_ldec_normalize(result);
}

/**
 * @brief Целочисленное деление двух чисел. Для начала очищаем переменные с
 * остатком, и для хранения целочисленного деления (от предыдущий операций).
 * Затем получаем текущие индексы, от куда начинается наше число которое мы
 * делим. Индекс элемента массива, и индекс первого, не пустого, бита этого
 * элемента. Это нужно, чтобы в циклах начинать сразу с нужных мест, и не
 * выполнять лишних действий, что улучшает скорость. С начала обрабатываем один
 * элемент, самый левый, до начала цикла, и начинам с нужного бита. Затем в
 * цикле проходим оставшиеся элементы, но уже начиная каждый раз с 31 бита
 * (самого левого). И прибавляем результат целочисленного деления в итоговый
 * результат.
 *
 * @param ar
 */
static void div_int(args *ar) {
  clear_num(ar->remainder);
  clear_num(ar->int_result);

  //--- Оптимизация
  get_dividend_indexes(ar);
  div_bits(ar);
  ar->curr_idx--;
  ar->start_bit_idx = 31;
  //--- Конец оптимизации

  for (; ar->curr_idx >= 0; ar->curr_idx--) {
    div_bits(ar);
  }
  s21_ldec_add_raw(ar->result, ar->int_result, ar->result);
}

/**
 * @brief Деление одного элемента массива (bits). С начала сдвигаем остаток и
 * текущий результат деления влево, на один бит. Тем самым добавляя по биту 0
 * справа. Проверяем что текущий бит числа, которое мы делим, единица, если так,
 * то устанавливаем остаток в единицу. Получается, что если там была 1 то мы
 * устанавливаем 1, но если был 0, то т.к. мы сдвинули число, то остается ноль.
 * Получается перенос числа из делимого, в остаток, до тех пор, пока остаток не
 * станет больше или равен делителю. Когда мы добились что остаток стал больше
 * делителя, то вычитаем из остатка делитель, и записываем обратно в остаток.
 * Так идем по всем битам элемента.
 *
 * По своей сути, это обычный алгоритм деления в столбик.
 * Например 10001 (число 17) | 11 (число 3) => remainder 1 => 10 => 100 (теперь
 * 100 больше 11) Записываем в результат 1, и вычитаем 100 - 11 = 1. Двигаем
 * Результат 10, остаток 10 (меньше делителя) => результат 100, остаток 101
 * больше делителя. Записываем в результат 1 => 101, и вычитаем 101 - 11 = 10.
 * Результат 101 (число 5), остаток 10 (число 2).
 */
static void div_bits(args *ar) {
  for (int i = ar->start_bit_idx; i >= 0; i--) {
    shift_left_one_bit(ar->remainder);
    shift_left_one_bit(ar->int_result);

    if (GET_BIT(ar->dividend->bits[ar->curr_idx], i)) {
      SET_BIT(ar->remainder->bits[0]);
    }

    if (!s21_ldec_is_greater_raw(ar->divisor, ar->remainder)) {
      SET_BIT(ar->int_result->bits[0]);
      s21_ldec_sub_raw(ar->remainder, ar->divisor, ar->remainder);
    }
  }
}
/**
 * @brief Деление остатка. Сначала умножаем на 10 (десятичная) остаток и
 * результат (сдвиг влево), пока остаток не станет больше делителя. Затем делаем
 * замену переменных (swap) => остаток числом, которое будем делить (делимым
 * dividend), а изначальное число нам больше не нужно, используем его для
 * хранения остатка. И снова производим целочисленное деление. И так до тех пор
 * пока не пройдем нужно количество циклов, или пока остаток не станет 0. Делим
 * остаток только если он не ноль. Если число выходит за границы, то делим его
 * 10 (возвращаем в рамки) и прерываем цикл.
 */
static void div_remains(args *ar) {
  const int max_remain_len = 35;
  for (int i = 0; i < max_remain_len && !s21_ldec_is_zero(ar->remainder); i++) {
    s21_ldec_shift_left(ar->remainder, 1);
    s21_ldec_shift_left(ar->result, 1);

    if (!s21_ldec_is_greater_raw(ar->divisor, ar->remainder)) {
      swap_nums(ar);
      div_int(ar);
    }

    if (ar->result->bits[S21_LDEC_BITS_CNT - 1]) {
      s21_ldec_shift_right(ar->result);
      i = 36;  // break
    }
  }
}

/**
 * @brief Получение индекса первого, не пустого, элемента делимого. И первого,
 * не пустого, бита. Для того, чтобы знать, от куда начинается значимая часть
 * числа.
 */
static void get_dividend_indexes(args *ar) {
  int i = S21_LDEC_BITS_CNT - 1;
  for (; i > 0 && ar->dividend->bits[i] == 0; i--) {
  }
  int j = 31;
  for (; j > 0 && GET_BIT(ar->dividend->bits[i], j) == 0; j--) {
  }

  ar->curr_idx = i;
  ar->start_bit_idx = j;
}

/**
 * @brief Сдвиг на один бит влево всех элементов числа, в конце переносим
 * переполнения, то что не влезло.
 */
static void shift_left_one_bit(s21_ldecimal *value) {
  for (int i = 0; i < S21_LDEC_BITS_CNT; i++) {
    value->bits[i] <<= 1;
  }
  s21_ldec_overflow_handler(value);
}

/**
 * @brief Обнуление числа. Всех его элементов, экспоненты, и знака.
 */
static void clear_num(s21_ldecimal *num) {
  for (int i = 0; i < S21_LDEC_BITS_CNT; i++) {
    num->bits[i] = 0;
  }
  num->exp = 0;
  num->sign = 0;
}

/**
 * @brief Обмен двух ldecimal - остатка и делимого, через замену указателей.
 * Это нужно, если мы хотим поделить остаток, в таком случае он становится
 * делимым, а число которое до этого было делимым станет на его место, и будет
 * использовано для хранения остатка, от этого деления (а перед этим будет
 * занулено).
 */
static void swap_nums(args *ar) {
  s21_ldecimal *t;
  t = ar->dividend;
  ar->dividend = ar->remainder;
  ar->remainder = t;
}

/**
 * @brief Устанавливаем знак для результирующего числа. Если знаки равны то
 * результат всегда будет положительным. Если знаки разные, то результат всегда
 * будет отрицательным.
 *
 * Например:
 * -25 / -5 =  5
 *  25 /  5 =  25
 * -25 /  5 = -25
 *  25 / -5 = -25
 */
static void set_result_sign(args *ar) {
  if (ar->dividend->sign == ar->divisor->sign) {
    ar->result->sign = 0;
  } else {
    ar->result->sign = 1;
  }
}
