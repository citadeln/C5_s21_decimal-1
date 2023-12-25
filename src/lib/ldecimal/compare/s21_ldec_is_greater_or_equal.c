#include "./../private/s21_ldec_private.h"
#include "./../s21_ldecimal.h"

bool s21_ldec_is_greater_or_equal(s21_ldecimal *num1, s21_ldecimal *num2) {
  if (!num1 || !num2) return false;

  s21_ldec_make_exp_equal(num1, num2);

  bool result;

  if (num1->sign == num2->sign) {
    if (num1->sign == S21_SIGN_PLUS) {
      result = !s21_ldec_is_greater_raw(num2, num1);
    } else {
      result = !s21_ldec_is_greater_raw(num1, num2);
    }
  } else {
    if (num1->sign)
      result = false;
    else
      result = true;
  }

  return result;
}
