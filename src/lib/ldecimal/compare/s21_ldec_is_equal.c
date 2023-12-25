#include "./../private/s21_ldec_private.h"
#include "./../s21_ldecimal.h"

bool s21_ldec_is_equal(s21_ldecimal *num1, s21_ldecimal *num2) {
  if ((!num1) || (!num2)) return false;
  bool result = true;

  if ((num1->exp != num2->exp) || (num1->sign != num2->sign)) {
    result = false;
  }

  if (result) {
    for (int i = 0; i < S21_LDEC_BITS_CNT; i++) {
      if (num1->bits[i] != num2->bits[i]) {
        result = false;
        i = S21_LDEC_BITS_CNT;  // break
      }
    }
  }

  return result;
}
