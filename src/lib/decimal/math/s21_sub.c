#include "./../../ldecimal/s21_ldecimal.h"
#include "./../common/s21_dec_common.h"

/**
 * @brief Вычитание двух чисел decimal
 *
 * @return 0 - OK;
 * @return 1 - число слишком велико или равно бесконечности;
 * @return 2 - число слишком мало или равно отрицательной бесконечности;
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!result) return S21_RESULT_ERROR;
  int res = S21_RESULT_ERROR;
  s21_clear_num(result);

  if (s21_decimal_check_correct(&value_1) &&
      s21_decimal_check_correct(&value_2)) {
    int v1exp = s21_decimal_get_exp(&value_1);
    int v2exp = s21_decimal_get_exp(&value_2);

    s21_ldecimal num1 = {0};
    if (v1exp < 57) num1 = s21_dec_to_ldec(&value_1);

    s21_ldecimal num2 = {0};
    if (v2exp < 57) num2 = s21_dec_to_ldec(&value_2);

    s21_ldecimal ldres = {0};

    s21_ldec_sub(&num1, &num2, &ldres);

    res = s21_ldec_to_dec(&ldres, result);
  }

  return res;
}
