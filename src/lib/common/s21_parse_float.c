#include "s21_parse_float.h"

#include <stdbool.h>

// Нужны для проверки числа на бесконечность и NaN (не число).
#define INF_POS (1.0 / 0.0)
#define IS_INF(x) (x == INF_POS)
#define IS_NAN(x) (x != x)

#define FLOAT_DIG_CNT 7  // Сколько значащих цифр нам нужно получить
#define MIN_FLOAT 3.4e-38F
#define MAX_FLOAT 3.4e+38F

/**
 * @brief Структура для хранения переменных между функциями.
 *
 * num - число для парсинга (float переведенный в double, для лучшей точности)
 * remain - остаток от числа, которое распарсили
 * precision - точность, ограничение на количество знаков в дробной части,
 * должно быть в отрицательном виде
 */
typedef struct {
  s21_fparse_t* fp;

  double src;
  double remain;
  int precision;
} args;

static bool has_overflow(float num);
static void errors_handler(s21_fparse_t* fp);
static void prepare_result(s21_fparse_t* result);

static void parse_int_part(args* ar);
static void parse_float_part(args* ar);
static int skip_zero_digits(args* ar);
static int round_num(int num, double remain);

static int trail_zero(int* num);
static int count_digs(int num);

/**
 * @brief Парсинг числа float, берет первые 7 значимых чисел, остальные
 * откидывает и округляет. В итоге получаем значимые числа, и экспоненту. Если
 * экспонента положительная - это сколько раз нужно умножить число на 10
 * (сколько нулей нужно добавить после числа). Если экспонента отрицательная,
 * сколько раз нужно поделить на 10.
 *
 * @return s21_fparse_t структура для хранения результата парсинга числа float
 */
s21_fparse_t s21_parse_float(float num, int precision) {
  s21_fparse_t result = {0};
  if (num == 0.0) return result;

  if (num < 0.0) {
    num = -num;
    result.sign = 1;
  }
  args ar = {.fp = &result, .src = num, .precision = -precision};

  if (has_overflow(num)) result.error = 1;

  if (!result.error) {
    parse_int_part(&ar);
    parse_float_part(&ar);
    errors_handler(&result);
  }

  if (!result.error) {
    prepare_result(&result);
  }

  return result;
}

/**
 * @brief Проверяет переполнение числа. Если число - бесконечность, или NaN (not
 * a number), то возвращаем true, т.е. число переполнено. И если число выходит
 * за рамки допустимых значений float.
 *
 * @param num
 * @return true
 * @return false
 */
static bool has_overflow(float num) {
  if (IS_INF(num) || IS_NAN(num)) return true;
  if (num > MAX_FLOAT || num < MIN_FLOAT) return true;
  return false;
}

/**
 * @brief Обработчик (handler) ошибок. Если число очень маленькое, и не входит в
 * нужную точность, то это ошибка конвертации.
 */
static void errors_handler(s21_fparse_t* fp) {
  if (fp->num == 0) {
    fp->error = 1;
    fp->exp = 0;
    fp->sign = 0;
    fp->cnt_digs = 0;
  }
}

/**
 * @brief Подготовка результата парсинга, к конечному виду. Удаляем лишние нули,
 * и добавляем количество удаленных нулей к экспоненте. Считаем и сохраняем
 * количество цифр, в итоговом числе.
 */
static void prepare_result(s21_fparse_t* result) {
  int cnt_zero = trail_zero(&result->num);
  result->exp += cnt_zero;
  result->cnt_digs = count_digs(result->num);
}

/**
 * @brief Парсинг целой части числа. Делим число на 10 до тех пор, пока оно не
 * станет меньше 1e7. То есть в итоге остается 7 цифр числа. Увеличивая
 * экспоненту каждый раз. Если остались цифры, которые не входят, то итоговое
 * число округляем. Оставшуюся часть числа сохраняем.
 */
static void parse_int_part(args* ar) {
  ar->fp->exp = 0;
  ar->remain = ar->src;
  for (; ar->remain > 1e7L; ar->fp->exp++) {
    ar->remain /= 10;
  }
  ar->fp->num = (int)ar->remain;
  ar->remain -= ar->fp->num;

  if (ar->fp->exp > 0) {
    ar->fp->num = round_num(ar->fp->num, ar->remain);
    ar->remain = 0.0L;
  }
}

/**
 * @brief Парсинг дробной части числа. Для начала пропускаем все нули, и
 * получаем сколько чисел нам осталось получить. Затем начинаем умножать на 10 и
 * наше итоговое число, чтобы выделить место под цифру, и остаток, чтобы
 * получить следующею цифру, далее через приведение к инту отбрасываем остаток,
 * и получаем нужную цифру. Прибавляем эту цифру к итоговому числу, а из остатка
 * убираем ее. И в конце округляем число.
 */
static void parse_float_part(args* ar) {
  if (ar->remain == 0.0L) return;

  int need_receive_digits = skip_zero_digits(ar);

  for (int i = 0; (i < need_receive_digits) && (ar->fp->exp > ar->precision);
       i++) {
    ar->remain *= 10.0;
    ar->fp->num *= 10;

    int digit = (int)ar->remain;
    ar->fp->num += digit;
    ar->remain -= digit;

    ar->fp->exp--;
  }

  ar->fp->num = round_num(ar->fp->num, ar->remain);
}

/**
 * Если целая часть числа 0, тогда пропускаем лишние нули (например 0.00001 =>
 * 0.1), т.к. нам нужно только 7 значащих цифр, и в этом случае нули не
 * учитываются. Если в целой части уже есть цифры, значит нам не надо пропускать
 * нули, а нужно получить недостающие цифры (например если уже есть 2 цифры,
 * осталось получить 5 цифр).
 *
 * @return Возвращает сколько значащих цифр осталось получить из дробной части.
 */
static int skip_zero_digits(args* ar) {
  int need_receive_digits = FLOAT_DIG_CNT;
  if (ar->fp->num == 0) {
    ar->fp->exp = 0;
    for (; (ar->remain < 0.1L) && (ar->fp->exp > ar->precision);
         ar->fp->exp--) {
      ar->remain *= 10.0;
    }
  } else {
    need_receive_digits -= count_digs(ar->fp->num);
  }
  return need_receive_digits;
}

/**
 * @brief Банковское кругление числа, получает само число, и остаток, для
 * округления.
 *
 * Домножаем остаток на 10. Чтобы взять последнюю цифру в остатке (например 0.23
 * берем 2). А из остатка удаляем ее. Дальше проверяем если последняя цифра в
 * остатке 5, тогда нам нужно понять нужно ли округлять. Если в остатке еще есть
 * цифры, тогда округляем, если цифр нет, то смотрим от четности числа, если
 * четное не округляем, если нечетное округляем.
 */
static int round_num(int num, double remain) {
  remain *= 10;
  int last_num = num % 10;
  int first_remain_num = (int)remain;

  bool need_round = false;
  if (first_remain_num == 5) {
    remain -= first_remain_num;
    bool has_remain = remain > 0.0L;
    if (has_remain || (last_num & 1)) first_remain_num++;
  }

  if (first_remain_num > 5) need_round = true;
  if (need_round) num++;

  return num;
}

/**
 * @brief Удаляем нули справа из числа, и увеличиваем экспоненту
 */
static int trail_zero(int* num) {
  int cnt = 0;
  for (; ((*num) % 10) == 0; cnt++) {
    *num /= 10;
  }
  return cnt;
}

/**
 * @brief Считаем количество цифр в числе
 */
static int count_digs(int num) {
  int result = 0;
  for (; num > 0; result++) {
    num /= 10;
  }
  return result;
}
