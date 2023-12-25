#define MAIN_CNT 0

#if MAIN_CNT == 1

#include <stdio.h>

#include "./../s21_decimal.h"

#define S21_MAKE_EXP(exp, sign) \
  ((int)(((unsigned int)(sign) << 31U) | ((unsigned int)(exp) << 16U)))

void s21_decimal_print(s21_decimal num) {
  for (int i = 3; i >= 0; i--) {
    for (int j = 0; j < 32; j++) {
      printf("%d", !!((unsigned int)num.bits[i] & 0x80000000));
      num.bits[i] <<= 1;
    }
    printf(" ");
  }
  printf("\n");
}

int main(void) {
  s21_decimal src = {.bits = {1}};
  src.bits[3] = S21_MAKE_EXP(10, 1);
  float dst = 0.0F;
  s21_from_decimal_to_float(src, &dst);
  s21_decimal_print(src);
  printf("\n%g\n", dst);
  return 0;
}

#endif
