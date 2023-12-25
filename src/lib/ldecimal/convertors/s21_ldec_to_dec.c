#include "./../../decimal/common/s21_dec_common.h"
#include "./../private/s21_ldec_private.h"

static void copy_num(s21_ldecimal *src, s21_decimal *dst);
/**
 * @brief Конвертирует s21_ldecimal в s21_decimal
 *
 * @param src (source) Что конвертируем
 * @param dst (destination) Куда конвертируем
 * @return int = Возвращает код ошибки:
 * 0: OK;
 * 1: Число слишком велико или равно бесконечности;
 * 2: Число слишком мало или равно отрицательной бесконечности;
 * 4: Null reference
 */
int s21_ldec_to_dec(s21_ldecimal *src, s21_decimal *dst) {
  if (!src || !dst) return S21_RESULT_ERROR;

  int result = s21_ldec_convert_prepare(src);
  copy_num(src, dst);

  return result;
}

/**
 * @brief Копируем те элементы массива long decimal, которые входят в decimal.
 * Устанавливаем экспоненту, и знак.
 */
static void copy_num(s21_ldecimal *src, s21_decimal *dst) {
  for (int i = 0; i < S21_DEC_BITS_CNT; i++) {
    dst->bits[i] = (int)src->bits[i];
  }
  dst->bits[3] = 0;
  s21_decimal_set_exp(dst, (int)src->exp);
  s21_decimal_set_sign(dst, (int)src->sign);
}
