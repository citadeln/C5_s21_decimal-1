#include "s21_ldec_private.h"

/**
 * @brief Складывает два числа без предварительной
 * подготовки, игнорируя экспоненту и знаки, и никак их не меняя. И записывает
 * результат в result.
 *
 * @param num1 Первое число для сложения
 * @param num2 Второе число для сложения
 * @param result Куда сохраняем результат
 * @return true - Все ок;
 * @return false - Результат сложения не вмещается в тип long decimal;
 */
bool s21_ldec_add_raw(const s21_ldecimal *num1, const s21_ldecimal *num2,
                      s21_ldecimal *result) {
  uint64_t overflow = 0;
  for (int i = 0; i < S21_LDEC_BITS_CNT; i++) {
    result->bits[i] = num1->bits[i] + overflow + num2->bits[i];

    overflow = CHECK_OVERFLOW(result->bits[i]);
    result->bits[i] = result->bits[i] & LOW_BITS_MASK;
  }
  return !overflow;
}
