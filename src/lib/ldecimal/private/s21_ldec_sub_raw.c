#include "s21_ldec_private.h"

/**
 * @brief Вычитает второе число (num2) из первого (num1) без предварительной
 * подготовки, игнорируя экспоненту и знаки, и никак их не меняя. И записывает
 * результат в result. Первое число должно быть больше или равно второму.
 *
 * @param num1 Число из которого нужно вычесть
 * @param num2 Число которое вычитаем
 * @param result Куда сохраняем результат
 * @return true - Все ок;
 * @return false - Первое число меньше второго.
 */
bool s21_ldec_sub_raw(const s21_ldecimal *num1, const s21_ldecimal *num2,
                      s21_ldecimal *result) {
  uint64_t overflow = 0;
  for (int i = 0; i < S21_LDEC_BITS_CNT; i++) {
    result->bits[i] = (num1->bits[i] - overflow) - num2->bits[i];

    overflow = CHECK_OVERFLOW(result->bits[i]);
    result->bits[i] = result->bits[i] & LOW_BITS_MASK;
  }
  return !overflow;
}
