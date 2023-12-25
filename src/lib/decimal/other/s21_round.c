#include "./../../ldecimal/s21_ldecimal.h"
#include "./../common/s21_dec_common.h"

#define NEED_BANK_ROUND(num, last_dig, exp) \
  (last_dig > 5 || (last_dig == 5 && (exp > 1 || num & 1)))

static void round_num(s21_ldecimal *val);

int s21_round(s21_decimal value, s21_decimal *result) {
  if (!result) return S21_CONVERT_ERROR;
  int res = S21_RESULT_OK;
  s21_clear_num(result);

  if (s21_decimal_check_correct(&value)) {
    s21_ldecimal lval = s21_dec_to_ldec(&value);

    round_num(&lval);

    s21_ldec_to_dec(&lval, result);
  } else {
    res = S21_CONVERT_ERROR;
  }

  return res;
}

static void round_num(s21_ldecimal *val) {
  uint32_t exp = val->exp;
  uint32_t last_dig = 0;

  for (uint32_t i = 0; i < exp; i++) {
    last_dig = s21_ldec_shift_right(val);
  }

  if (NEED_BANK_ROUND(val->bits[0], last_dig, exp)) {
    val->bits[0]++;
    s21_ldec_overflow_handler(val);
  }
}
