#include "./../s21_ldecimal.h"

// ***************** //
// *** Прототипы *** //
// ***************** //
static uint32_t shift_left(s21_ldecimal *src);

/**
 * @brief Сдвигает на один порядок влево (умножение на 10, например 12 => 120),
 * увеличивая экспоненту
 *
 * @param num Число для сдвига
 * @param cnt На сколько порядков сдвинуть
 * @return Переполнение, 0 = переполнения нет, иначе возвращает то что
 * переполнилось
 */
uint32_t s21_ldec_shift_left(s21_ldecimal *num, int cnt) {
  uint32_t result = 0;

  for (int i = 0; i < cnt && !result; i++) {
    result = shift_left(num);
    num->exp++;
  }

  return result;
}

// **************************//
// *** Приватные функции *** //
// **************************//
static uint32_t shift_left(s21_ldecimal *src) {
  for (int i = 0; i < S21_LDEC_BITS_CNT; i++) {
    src->bits[i] *= 10;
  }
  return s21_ldec_overflow_handler(src);
}
