#include <stdbool.h>

#include "./../common/s21_ldec_type.h"

/**
 * @brief Проверяет что число это ноль
 *
 * @return true Число это ноль
 * @return false Число это не ноль
 */
bool s21_ldec_is_zero(const s21_ldecimal *num) {
  if (!num) return false;
  bool result = true;

  for (int i = 0; i < S21_LDEC_BITS_CNT; i++) {
    if (num->bits[i] != 0) {
      result = false;
      i = S21_LDEC_BITS_CNT;  // break
    }
  }

  return result;
}
