#include "./../common/s21_ldec_common.h"
#include "./../s21_ldecimal.h"
#include "s21_ldec_private.h"

/**
 * @brief Структура для хранения результата "обрезки" части, которая не входит в
 * decimal.
 * @param remain_dig Последняя(левая)/текущая цифра из остатка
 * @param remain_len Количество отброшенных цифр
 */
typedef struct {
  s21_ldecimal *num;
  uint32_t remain_dig;
  uint32_t remain_len;
} cuts;

static cuts cut_num(s21_ldecimal *num);
static void round_num(cuts *cut);

/**
 * @brief Подготавливает ldecimal к конвертации, для соответствия числа типу
 * decimal. Обрезает лишнюю дробную часть до 28 знаков, и округляет ее по
 * правилам банковского округления. И нормализует его (удаляет лишнии нули).
 *
 * @return int = Возвращает код ошибки:
 * 0: OK;
 * 1: Число слишком велико или равно бесконечности;
 * 2: Число слишком мало или равно отрицательной бесконечности;
 */
int s21_ldec_convert_prepare(s21_ldecimal *num) {
  int result = 0;

  cuts cut = cut_num(num);
  round_num(&cut);
  norm_res nr = s21_ldec_normalize(num);

  if (nr != nrIsZero && s21_dec_has_overflow(num)) {
    if (num->sign == 0)
      result = 1;
    else
      result = 2;
  }

  return result;
}

/**
 * @brief Обрезает дробную часть числа lond decimal, пока оно не
 * вместится в decimal. Сдвигаем вправо (отбрасываем последнюю цифру),
 * пока есть переполнение, и число отброшенных цифр не больше экспоненты (то
 * есть не переходим на целую часть). И пока экспонента больше 28.
 */
static cuts cut_num(s21_ldecimal *src) {
  cuts result = {.num = src};
  bool overflow = s21_dec_has_overflow(src);
  uint32_t remlen = src->exp;

  while ((result.remain_len < remlen && overflow) || result.num->exp > 28) {
    result.remain_dig = s21_ldec_shift_right(result.num);
    result.remain_len++;
    if (result.num->exp > 0) {
      overflow = s21_dec_has_overflow(result.num);
    } else
      remlen = 0;  // break
  }

  return result;
}

/**
 * @brief Банковское округление: Если последняя отброшенная цифра (остаток)
 * больше 5, округляем всегда. Если 5, и в остатке были еще цифры (не
 * только эта), то округляем. Если в остатке больше не было отброшенных цифр,
 * то округляем только если округляемая цифра нечетная.
 * remainder_len > 1 = отброшенных цифр больше 1;
 * rounded_digital & 1 = проверяем что округляемое нечетное;
 */
static void round_num(cuts *cut) {
  if (cut->remain_dig > 5 || (cut->remain_dig == 5 &&
                              (cut->remain_len > 1 || cut->num->bits[0] & 1))) {
    cut->num->bits[0]++;
    s21_ldec_overflow_handler(cut->num);
  }
}
