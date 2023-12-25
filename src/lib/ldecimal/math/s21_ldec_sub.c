#include "./../common/s21_ldec_common.h"
#include "./../private/s21_ldec_private.h"
#include "./../s21_ldecimal.h"

static bool sub_module(s21_ldecimal *num1, s21_ldecimal *num2,
                       s21_ldecimal *result, int num2_is_greater);
static uint32_t get_sign(s21_ldecimal *num1, s21_ldecimal *num2,
                         int num2_is_greater);

/**
 * @brief Производит вычитание второго числа из первого.
 *
 * @param num1 Уменьшаемое
 * @param num2 Вычитаемое
 * @return true - OK;
 * @return false - переполнение числа по модулю;
 */
bool s21_ldec_sub(s21_ldecimal *num1, s21_ldecimal *num2,
                  s21_ldecimal *result) {
  if (!num1 || !num2 || !result) return false;

  s21_ldec_make_exp_equal(num1, num2);

  int num2_is_greater = s21_ldec_is_greater_raw(num2, num1);

  bool res = sub_module(num1, num2, result, num2_is_greater);

  result->exp = num1->exp;
  result->sign = get_sign(num1, num2, num2_is_greater);

  s21_ldec_normalize(result);

  return res;
}

/**
 * @brief  Получаем модуль числа, от вычитания. Все операции идут только с
 * модулями чисел и не учитывая экспонент. Если знаки равны, тогда вычитаем
 * большее из меньшего. Иначе складываем. При сложении, какое число больше, не
 * имеет значения.
 * Например:
 * "-5 - -10 = -5 или |10| - |5| = |5|";
 * "-10 - -5 = -5 или |10| - |5| = |15|";
 * "  5 - 10 = -5 или |10| - |5| = |5|";
 * "-5 - 10 = -15 или |5| + |10| = |15|";
 * "5 - -10 =  15 или |5| + |10| = |15|";
 */
static bool sub_module(s21_ldecimal *num1, s21_ldecimal *num2,
                       s21_ldecimal *result, int num2_is_greater) {
  bool res = true;

  if (num1->sign == num2->sign) {
    if (num2_is_greater)
      s21_ldec_sub_raw(num2, num1, result);
    else
      s21_ldec_sub_raw(num1, num2, result);
  } else {
    res = s21_ldec_add_raw(num1, num2, result);
  }

  return res;
}

/**
 * @brief Получаем итоговый знак результата. Итоговый знак всегда смотрится по
 * большему числу. Но если большее число стоит на втором месте (т.е. это число
 * которое вычитают), то в результате будет  обратный знак этого числа.
 * Например:
 * -5 - 10 = -10 (минус, обратный знак 10, т.к. большее и на втором месте)
 *  5 - 10 = -5  (минус, обратный знак 10, т.к. больше и на втором месте)
 * -10 - 5 = -10 (минус, знак 10, т.к. больше и на первом месте)
 *  10 - 5 =  5  (плюс, знак 10, т.к. больше и на первом месте)
 */
static uint32_t get_sign(s21_ldecimal *num1, s21_ldecimal *num2,
                         int num2_is_greater) {
  uint32_t res;
  if (num2_is_greater) {
    res = !num2->sign;
  } else {
    res = num1->sign;
  }
  return res;
}
