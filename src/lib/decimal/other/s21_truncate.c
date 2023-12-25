#include "../common/s21_dec_common.h"

/**
 * @brief Отбрасывает любые дробные цифры, включая конечные нули
 *
 * @param value Исходное число
 * @param result Результат отбрасывания дробной части
 *
 * @return Возвращает код ошибки (0 в случае успеха)
 */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (!result) return S21_CONVERT_ERROR;
  int res = S21_RESULT_OK;
  s21_clear_num(result);

  if (s21_decimal_check_correct(&value)) {
    // Копирование значений из value в result
    for (int i = 0; i < S21_DEC_ARR_CNT; i++) {
      result->bits[i] = value.bits[i];
    }

    // Получение экспоненты числа
    int exp = s21_decimal_get_exp(&value);

    // Cдвиг числа вправо на экспоненту раз
    for (int i = 0; i < exp; i++) {
      s21_decimal_shift_right(result);
    }
  } else {
    res = S21_CONVERT_ERROR;
  }

  return res;
}
