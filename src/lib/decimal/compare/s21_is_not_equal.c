#include "./../../ldecimal/s21_ldecimal.h"
#include "./../common/s21_dec_common.h"

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  if (!s21_decimal_check_correct(&value_1)) return false;
  if (!s21_decimal_check_correct(&value_2)) return false;

  s21_ldecimal lnum1 = s21_dec_to_ldec(&value_1);
  s21_ldecimal lnum2 = s21_dec_to_ldec(&value_2);

  return !s21_ldec_is_equal(&lnum1, &lnum2);
}
