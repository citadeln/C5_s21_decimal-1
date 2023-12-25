#include <stdint.h>

#include "s21_dec_common.h"

static int shift_right(s21_decimal *num);

/**
 * @brief Сдвиг вправо, в десятичном виде (т.е. деление на 10). Уменьшает
 * экспоненту на 1, если экспонента больше 0, иначе экспонента остается 0.
 *
 * @return Возвращает отброшенную цифру.
 */
int s21_decimal_shift_right(s21_decimal *num) {
  int result = 0;

  int exp = s21_decimal_get_exp(num);

  result = shift_right(num);
  if (exp > 0) exp--;

  s21_decimal_set_exp(num, exp);

  return result;
}

/**
 * @brief Проходим по всем элементам массива, от старшего к младшему. Если
 * элемент пустой, пропускаем его. Дальше берем остаток от предыдущей операции,
 * добавляем его к текущему элементу. Для этого используем сдвиг влево (чтобы
 * выравнять число), и побитовую операцию ИЛИ, для склейки двух чисел. Дальше
 * делим число на 10, и сохраняем остаток от деления.
 *
 * @return Возвращает остаток от деления на 10 (т.е. последнюю цифру числа).
 */
static int shift_right(s21_decimal *num) {
  uint64_t remainder = 0;

  for (int cnt = S21_DEC_BITS_CNT - 1; cnt >= 0; cnt--) {
    if (!num->bits[cnt]) continue;

    remainder <<= 32;
    remainder = (unsigned int)num->bits[cnt] | remainder;

    num->bits[cnt] = (int)(remainder / 10UL);
    remainder = remainder % 10UL;
  }

  return (int)remainder;
}
