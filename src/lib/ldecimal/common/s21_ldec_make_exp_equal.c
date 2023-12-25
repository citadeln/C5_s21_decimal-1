#include "./../s21_ldecimal.h"

/**
 * @brief Выравнивает экспоненты у двух long double, для дальнейших операций,
 * которые требуют одинаковых экспонент(сложение, вычитание и тд).
 * Пример: 12345 (exp 4) и 2 (exp 0) => 12345 (exp 4) и 20000 (exp 4)
 *
 * @return true Ок, удалось выравнять
 * @return false Экспоненты слишком большие, произошло переполнение
 */
bool s21_ldec_make_exp_equal(s21_ldecimal *num1, s21_ldecimal *num2) {
  if (num1->exp == num2->exp) return true;
  int result = true;

  if (num1->exp > num2->exp) {
    result = !s21_ldec_shift_left(num2, (int)(num1->exp - num2->exp));
  } else {
    result = !s21_ldec_shift_left(num1, (int)(num2->exp - num1->exp));
  }

  return result;
}
