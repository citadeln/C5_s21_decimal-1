#include "./../../decimal/common/s21_dec_common.h"
#include "./../private/s21_ldec_private.h"

/**
 * @brief Конвертация из типа s21_decimal в тип s21_ldecimal (в long)
 */
s21_ldecimal s21_dec_to_ldec(const s21_decimal *src) {
  s21_ldecimal result = {0};

  if (src) {
    result.sign = (uint32_t)s21_decimal_get_sign(src);
    result.exp = (uint32_t)s21_decimal_get_exp(src);

    for (int i = 0; i < S21_DEC_BITS_CNT; i++) {
      result.bits[i] = (unsigned int)src->bits[i];
    }
    s21_ldec_convert_prepare(&result);
  }

  return result;
}
