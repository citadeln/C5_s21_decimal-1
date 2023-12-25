#include "../common/s21_dec_common.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (!dst) return S21_CONVERT_ERROR;

  int sign = S21_SIGN_PLUS;
  if (src < 0) {
    sign = S21_SIGN_MINUS;
    src *= -1;
  }

  dst->bits[0] = src;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;

  s21_decimal_set_sign(dst, sign);

  return S21_RESULT_OK;
}
