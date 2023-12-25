#include "s21_ldec_private.h"

/**
 * @brief Сравнивает два числа, в "сыром" виде, без предварительной подготовки
 * этих чисел к сравнению. Т.е. игнорируя знак, и экспоненту.
 *
 * @return true - num1 больше num2;
 * @return false - num1 меньше num2;
 */
bool s21_ldec_is_greater_raw(const s21_ldecimal *num1,
                             const s21_ldecimal *num2) {
  bool result = false;

  for (int i = S21_LDEC_BITS_CNT - 1; i >= 0; i--) {
    if (num1->bits[i] == num2->bits[i]) continue;

    if (num1->bits[i] > num2->bits[i]) {
      result = true;
    }
    i = 0;  // break
  }

  return result;
}
