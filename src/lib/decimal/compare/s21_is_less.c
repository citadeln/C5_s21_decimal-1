#include "./../../ldecimal/s21_ldecimal.h"
#include "./../common/s21_dec_common.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  bool result = false;

  if (s21_decimal_check_correct(&value_1) &&
      s21_decimal_check_correct(&value_2)) {
    s21_ldecimal a = s21_dec_to_ldec(&value_1);
    s21_ldecimal b = s21_dec_to_ldec(&value_2);
    if (s21_ldec_is_greater(&b, &a)) result = true;
  }

  return result;
}
