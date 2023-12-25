#include "./../s21_ldecimal.h"

static int get_first_not_zero_bits(s21_ldecimal *num);
static uint32_t shift(s21_ldecimal *num, int start_from_bit);

/**
 * @brief Сдвигает на порядок вправо (деление на 10, например 123 => 12).
 * В случае если при сдвиге значащих цифр не остается, т.е. число стало нулем,
 * тогда зануляет экспоненту и знак.
 *
 * @param num Число для сдвига
 * @return Отброшенный остаток (одна цифра)
 */
uint32_t s21_ldec_shift_right(s21_ldecimal *num) {
  uint32_t remainder = 0;

  int index = get_first_not_zero_bits(num);

  if (index >= 0) {
    remainder = shift(num, index);
  } else {
    num->exp = 0;
    num->sign = 0;
  }

  return remainder;
}

/**
 * @brief Берем старший элемент массива long decimal (bits), который имеет
 * значащие цифры (не заполнен нулями, т.е. не ноль).
 */
static int get_first_not_zero_bits(s21_ldecimal *num) {
  int cnt = S21_LDEC_BITS_CNT - 1;
  for (; cnt >= 0 && num->bits[cnt] == 0; cnt--) {
  }
  return cnt;
}

/**
 * @brief Сдвиг вправо и возврат следующей цифры из остатка (путем деления на 10
 * и взятия остатка от 10). Уменьшает экспоненту на 1.
 */
static uint32_t shift(s21_ldecimal *num, int start_from_bit) {
  uint64_t remainder = 0;

  for (int i = start_from_bit; i >= 0; i--) {
    remainder <<= 32;
    num->bits[i] |= remainder;
    remainder = num->bits[i] % 10UL;

    num->bits[i] /= 10UL;
  }
  if (num->exp > 0) num->exp--;

  return (uint32_t)remainder;
}
