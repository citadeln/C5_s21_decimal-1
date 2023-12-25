#include "./../common/s21_dec_common.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (!result) return S21_CONVERT_ERROR;
  int res = S21_RESULT_OK;
  s21_clear_num(result);

  if (s21_decimal_check_correct(&value)) {
    int sign = s21_decimal_get_sign(&value);
    for (int i = 0; i < S21_DEC_ARR_CNT; i++) {
      result->bits[i] = value.bits[i];
    }
    s21_decimal_set_sign(result, !sign);
  } else {
    res = S21_CONVERT_ERROR;
  }

  return res;
}
