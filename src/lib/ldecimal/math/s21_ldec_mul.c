#include "./../common/s21_ldec_common.h"
#include "./../s21_ldecimal.h"

/**
 * @brief Структура для передачи аргументов во внутренние функции
 *
 * n1, n2 - числа для умножения
 * res - результат умножения
 * len - длина чисел в элементах массива, которые нужны для хранения этих чисел
 */
typedef struct {
  s21_ldecimal *n1;
  int n1_len;

  s21_ldecimal *n2;
  int n2_len;

  s21_ldecimal *res;
  int res_len;
} args;

static void get_nums_len(args *a);
static void mult(args *a);
static void set_sign(args *a);
static void fill_result(args *a);

/**
 * @brief Умножение двух чисел long decimal
 *
 * @param num1 Первое число для умножения
 * @param num2 Второе число для умножения
 * @param result Результат умножения
 * @return true = ok;
 * @return false = число по модулю очень большое, и long decimal переполняется;
 */
bool s21_ldec_mul(s21_ldecimal *num1, s21_ldecimal *num2,
                  s21_ldecimal *result) {
  if (!num1 || !num2 || !result) return false;
  int res = true;
  args a = {.n1 = num1, .n2 = num2, .res = result};

  get_nums_len(&a);

  if (a.res_len <= S21_LDEC_BITS_CNT) {
    if (a.n1_len != 0 && a.n2_len != 0) mult(&a);

    set_sign(&a);
    s21_ldec_normalize(result);
  } else {
    fill_result(&a);
    res = false;
  }

  return res;
}

/**
 * @brief Вычисляем длину чисел для умножения. Для более эффективного умножения.
 * Чтобы не проходить каждый раз пустые части массивов. Так же считаем общую
 * длину, и таким образом узнаем сколько элементов массива нужно под результат
 * умножения.
 *
 * Начинаем с последнего элемента массива числа, если не ноль, тогда мы нашли
 * искомую длину. Если дошли до конца, значит элементы пустые.
 */
static void get_nums_len(args *a) {
  a->n1_len = a->n2_len = S21_LDEC_BITS_CNT;

  for (; a->n1_len > 0 && a->n1->bits[a->n1_len - 1] == 0; a->n1_len--)
    ;
  for (; a->n2_len > 0 && a->n2->bits[a->n2_len - 1] == 0; a->n2_len--)
    ;

  a->res_len = a->n1_len + a->n2_len;
}

/**
 * @brief Умножаем два числа, и устанавливаем экспоненту результата умножения,
 * путем складывания.
 * Например: 10.001 * 0.001 = 0.010001 (у первого 3 знака после запятой, у
 * второго 3 знака после запятой, значит в итоге будет 6 знаков)
 *
 * Проходим по очереди по всем элементов первого числа, и перемножаем их на все
 * элементы второго числа. После перемножения каждого элемента первого числа, на
 * все элементы второго. Нужно обработать переполнения, и перекинуть, если
 * таковые имеются, в элементы следующего массива.
 */
static void mult(args *a) {
  for (int i = 0; i < a->n1_len; i++) {
    for (int j = 0; j < a->n2_len; j++) {
      a->res->bits[i + j] += a->n1->bits[i] * a->n2->bits[j];
    }
    s21_ldec_overflow_handler(a->res);
  }
  a->res->exp = a->n1->exp + a->n2->exp;
}

/**
 * @brief Устанавливаем знак для результата. Если у чисел для умножения были
 * одинаковые знаки, то результат будет всегда положительным. Если знаки были
 * разные, то результат всегда будет отрицательным.
 *
 * Например:
 * -5 * -5 = 25
 *  5 *  5 = 25
 * -5 *  5 = -25
 *  5 * -5 = -25
 */
static void set_sign(args *a) {
  if (a->n1->sign == a->n2->sign)
    a->res->sign = 0;
  else
    a->res->sign = 1;
}

/**
 * @brief Заполнение всех битов (32 битов) числа единицами. На случай
 * переполнения числа.
 */
static void fill_result(args *a) {
  for (int i = 0; i < S21_LDEC_BITS_CNT; i++) {
    a->res->bits[i] = UINT32_MAX;
  }
}
