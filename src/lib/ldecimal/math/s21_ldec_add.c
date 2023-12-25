#include "./../common/s21_ldec_common.h"
#include "./../private/s21_ldec_private.h"
#include "./../s21_ldecimal.h"

static bool add(const s21_ldecimal *num1, const s21_ldecimal *num2,
                s21_ldecimal *result);
static bool sub(const s21_ldecimal *num1, const s21_ldecimal *num2,
                s21_ldecimal *result);

/**
 * @brief Сложение двух чисел long decimal.
 * Выравнивает экспоненты двух чисел, чтобы точка оказалась под точкой.
 * Производит сложение. И нормализует результат.
 *
 * @return true = ок;
 * @return false = ошибка, или результат не вмещается в long decimal, или
 * произошло переполнение при выравнивании экспонент;
 */
bool s21_ldec_add(s21_ldecimal *num1, s21_ldecimal *num2,
                  s21_ldecimal *result) {
  if (!num1 || !num2 || !result) return false;

  bool res = s21_ldec_make_exp_equal(num1, num2);

  if (res) res = add(num1, num2, result);

  if (res) {
    result->exp = num1->exp;
    s21_ldec_normalize(result);
  }

  return res;
}

/**
 * @brief Если знаки равны, то в результате знак сохранится, а модуль результата
 * получится из сложения модулей двух чисел. Если знаки разные то считаем через
 * вычитание.
 * Например:
 * "-5 + (-10) = -5 - 10 = -15";
 * "5 + 10 = 15"
 */
static bool add(const s21_ldecimal *num1, const s21_ldecimal *num2,
                s21_ldecimal *result) {
  bool res;

  if (num1->sign == num2->sign) {
    result->sign = num1->sign;
    res = s21_ldec_add_raw(num1, num2, result);
  } else {
    res = sub(num1, num2, result);
  }

  return res;
}

/**
 * @brief Делаем сложение с разными знаками через вычитание модулей. Вычитаем
 * большее из меньшего. Знак сохранится большего числа.
 * Например:
 * "-10 + 5 = - (10 - 5) = -5";
 * "-5 + 10 = + (10 - 5) = -5";
 * "5 + (-10) = - (10 - 5) = -5"
 * "5 + (-5) = 5 - 5 = 0"
 */
static bool sub(const s21_ldecimal *num1, const s21_ldecimal *num2,
                s21_ldecimal *result) {
  bool res;

  if (s21_ldec_is_greater_raw(num2, num1)) {
    result->sign = num2->sign;
    res = s21_ldec_sub_raw(num2, num1, result);
  } else {
    result->sign = num1->sign;
    res = s21_ldec_sub_raw(num1, num2, result);
  }

  return res;
}
