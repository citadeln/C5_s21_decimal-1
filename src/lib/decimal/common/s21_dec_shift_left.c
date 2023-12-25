#include <stdint.h>

#include "s21_dec_common.h"

#define LOW_BITS_MASK 0xffffffff

static bool shift_left(s21_decimal *num);

/**
 * @brief Сдвиг влево, в десятичном виде (т.е. умножение на 10). Увеличивает
 * экспоненту на 1.
 *
 * @return true - ок
 * @return false - переполнение
 */
bool s21_decimal_shift_left(s21_decimal *num) {
  bool result = true;
  int exp = s21_decimal_get_exp(num);

  result = shift_left(num);
  exp++;

  s21_decimal_set_exp(num, exp);

  return result;
}

/**
 * @brief Умножаем на 10 по очереди, начиная с 0, все элементы массива. Если
 * остаются элементы которые не вмещаются в int (32 бита), то есть число
 * получается более 32 бит, то переносим биты, которые переполняются в старший
 * элемент массива. Для этого сохраняем на каждом шаге переполнение, а на
 * следующим прибавляем его к числу, используя побитовую операцию И, и операцию
 * сдвига вправо. В конце, если элемент который мы остановились, это старший
 * элемент массива, и у нас осталось переполнение. Значит итоговое число не
 * вместилось, и это ошибка. Если это был не последний элемент, добавляем
 * переполнение к элементу.
 *
 * @param num
 * @return true
 * @return false
 */
static bool shift_left(s21_decimal *num) {
  bool result = true;

  uint64_t overflow = 0;
  int cnt = 0;
  for (; cnt < S21_DEC_BITS_CNT && num->bits[cnt]; cnt++) {
    overflow = ((unsigned int)num->bits[cnt] * 10UL) + overflow;
    num->bits[cnt] = (int)(overflow & LOW_BITS_MASK);
    overflow >>= 32;
  }
  if (cnt == S21_DEC_BITS_CNT && overflow)
    result = false;
  else
    num->bits[cnt] += overflow;

  return result;
}
