#include "./../s21_ldecimal.h"
#include "s21_ldec_common.h"

static void normalize(s21_ldecimal *num);
static void return_to_num(s21_ldecimal *num, uint32_t dig);

/**
 * @brief Нормализует число, т.е. удаляет лишние незначащие нули из дробной
 * части числа, и уменьшает экспоненту на количество удаленных нулей (т.к. число
 * стало "короче").
 *
 * @return nrIsZero Число для нормализации это ноль;
 * @return nrOk Все ок;
 *
 */
norm_res s21_ldec_normalize(s21_ldecimal *num) {
  norm_res result = nrOk;

  if (s21_ldec_is_zero(num)) {
    num->exp = 0;
    num->sign = 0;
    result = nrIsZero;
  } else {
    normalize(num);
  }

  return result;
}

static void normalize(s21_ldecimal *num) {
  int exp = (int)num->exp;
  for (int i = 0; i < exp; i++) {
    uint32_t remainder = s21_ldec_shift_right(num);
    if (remainder != 0) {
      return_to_num(num, remainder);
      i = exp;  // break
    }
  }
}

static void return_to_num(s21_ldecimal *num, uint32_t dig) {
  s21_ldec_shift_left(num, 1);
  num->bits[0] += (uint64_t)dig;
  s21_ldec_overflow_handler(num);
}
