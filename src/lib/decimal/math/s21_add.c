#include "./../../ldecimal/s21_ldecimal.h"
#include "./../common/s21_dec_common.h"

/**
 * @brief Сложение двух чисел decimal
 *
 * @return 0 - OK;
 * @return 1 - число слишком велико или равно бесконечности;
 * @return 2 - число слишком мало или равно отрицательной бесконечности;
 * @return 4 - другая ошибка (null reference или ошибка конвертации)
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!result) return S21_RESULT_ERROR;
  int res = S21_RESULT_ERROR;
  s21_clear_num(result);

  if (s21_decimal_check_correct(&value_1) &&
      s21_decimal_check_correct(&value_2)) {
    s21_ldecimal num1 = s21_dec_to_ldec(&value_1);
    s21_ldecimal num2 = s21_dec_to_ldec(&value_2);
    s21_ldecimal ldres = {0};

    s21_ldec_add(&num1, &num2, &ldres);

    res = s21_ldec_to_dec(&ldres, result);
  }

  return res;
}
