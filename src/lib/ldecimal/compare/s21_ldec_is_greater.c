#include "./../private/s21_ldec_private.h"
#include "./../s21_ldecimal.h"

bool s21_ldec_is_greater(s21_ldecimal *value_1, s21_ldecimal *value_2) {
  if (!value_1 || !value_2) return false;

  s21_ldec_make_exp_equal(value_1, value_2);

  bool result;

  if (value_1->sign == value_2->sign && value_1->sign == S21_SIGN_MINUS) {
    result = s21_ldec_is_greater_raw(value_2, value_1);
  } else {
    result = s21_ldec_is_greater_raw(value_1, value_2);

    if (result) {
      if (value_1->sign) result = false;
    } else {
      if (value_2->sign) result = true;
    }
  }

  return result;
}
