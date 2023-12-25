#include "./../common/s21_dec_common.h"

static int convert(s21_decimal *src, int *dst);
static void truncate(s21_decimal *src, int exp);
static bool has_overflow(s21_decimal *src);

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (!dst) return S21_CONVERT_ERROR;
  int res = S21_RESULT_OK;
  *dst = 0;

  if (s21_decimal_check_correct(&src)) {
    res = convert(&src, dst);
  } else {
    res = S21_CONVERT_ERROR;
  }

  return res;
}

static int convert(s21_decimal *src, int *dst) {
  int result = 0;

  int exp = s21_decimal_get_exp(src);
  truncate(src, exp);

  if (has_overflow(src)) {
    result = S21_CONVERT_ERROR;
  } else {
    int sign = s21_decimal_get_sign(src);
    *dst = src->bits[0];
    if (sign) *dst = -(*dst);
  }

  return result;
}

static void truncate(s21_decimal *src, int exp) {
  for (int i = 0; i < exp; i++) {
    s21_decimal_shift_right(src);
  }
}

static bool has_overflow(s21_decimal *src) {
  bool result = false;
  for (int i = 1; i < S21_DEC_BITS_CNT; i++) {
    if (src->bits[i] != 0) {
      result = true;
      i = S21_DEC_BITS_CNT;  // break
    }
  }
  if (src->bits[0] < 0) result = true;
  return result;
}
