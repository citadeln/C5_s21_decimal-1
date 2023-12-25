#include "s21_dec_common.h"

#define ZERO_BITS_MASK 0x7F00FFFF  // 01111111000000001111111111111111
#define EXP_MASK 0x00FF0000        // 00000000 11111111 00000000 00000000
#define SIGN_MASK 0x80000000       // 10000000 00000000 00000000 00000000

#define S21_MAKE_EXP(x) ((unsigned int)x & EXP_MASK)
#define GET_SIGN(x) ((unsigned int)x & SIGN_MASK)

void s21_decimal_set_sign(s21_decimal *num, int sign) {
  unsigned int exp = S21_MAKE_EXP(num->bits[3]);
  num->bits[3] = (int)(exp | ((unsigned int)sign << 31));
}

int s21_decimal_get_sign(const s21_decimal *num) {
  return (GET_SIGN(num->bits[3]) >> 31);
}

void s21_decimal_set_exp(s21_decimal *num, int exp) {
  unsigned int sign = GET_SIGN(num->bits[3]);
  num->bits[3] = (int)(((unsigned int)exp << 16) | sign);
}

int s21_decimal_get_exp(const s21_decimal *num) {
  int exp = S21_MAKE_EXP(num->bits[3]);
  return exp >> 16;
}

void s21_clear_num(s21_decimal *num) {
  for (int i = 0; i < S21_DEC_ARR_CNT; i++) {
    num->bits[i] = 0;
  }
}

bool s21_decimal_check_correct(const s21_decimal *num) {
  bool result = true;
  if ((unsigned int)num->bits[3] & ZERO_BITS_MASK) {
    result = false;
  }
  return result;
}
