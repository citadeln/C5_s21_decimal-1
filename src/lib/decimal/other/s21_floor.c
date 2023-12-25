#include <stdint.h>

#include "./../../ldecimal/s21_ldecimal.h"
#include "./../common/s21_dec_common.h"

static void floor_num(s21_ldecimal *val);

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!result) return S21_CONVERT_ERROR;
  int res = S21_RESULT_OK;
  s21_clear_num(result);

  if (s21_decimal_check_correct(&value)) {
    s21_ldecimal lval = s21_dec_to_ldec(&value);

    floor_num(&lval);

    s21_ldec_to_dec(&lval, result);
  } else {
    res = S21_CONVERT_ERROR;
  }

  return res;
}

static void floor_num(s21_ldecimal *val) {
  uint32_t exp = val->exp;
  uint32_t sign = val->sign;

  while (val->exp > 0) {
    s21_ldec_shift_right(val);
  }

  if (exp > 0 && sign == S21_SIGN_MINUS) {
    val->bits[0]++;
    s21_ldec_overflow_handler(val);
    val->sign = S21_SIGN_MINUS;
  }
}
