#include "./../../ldecimal/s21_ldecimal.h"
#include "./../common/s21_dec_common.h"

/**
 * @brief Деление двух чисел decimal
 *
 * @return 0 - OK;
 * @return 1 - число слишком велико или равно бесконечности;
 * @return 2 - число слишком мало или равно отрицательной бесконечности;
 * @return 3 - деление на ноль;
 * @return 4 - другая ошибка (null reference или ошибка конвертации)
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!result) return S21_RESULT_ERROR;
  int res = S21_RESULT_ERROR;
  s21_clear_num(result);

  if (s21_decimal_check_correct(&value_1) &&
      s21_decimal_check_correct(&value_2)) {
    s21_ldecimal num1 = s21_dec_to_ldec(&value_1);
    s21_ldecimal num2 = s21_dec_to_ldec(&value_2);
    s21_ldecimal ldres = {0};

    bool res_div = s21_ldec_div(&num1, &num2, &ldres);
    res = s21_ldec_to_dec(&ldres, result);

    if (!res_div) res = 3;
  }

  return res;
}
