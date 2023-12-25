#include <stdbool.h>

#include "./../../../s21_decimal.h"
#include "./../common/s21_ldec_type.h"

/**
 * @brief Проверяет переполнение decimal тех элементов массива, которые не
 * входят в long decimal.
 */
bool s21_dec_has_overflow(s21_ldecimal *num) {
  bool result = false;
  for (int i = S21_DEC_BITS_CNT; i < S21_LDEC_BITS_CNT; i++) {
    if (num->bits[i] != 0) result = true;
  }
  return result;
}
