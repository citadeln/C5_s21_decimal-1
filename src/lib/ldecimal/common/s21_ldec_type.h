#ifndef S21_LDEC_TYPE_H
#define S21_LDEC_TYPE_H

#include <stdint.h>

#define S21_LDEC_BITS_CNT 7

typedef struct {
  uint64_t bits[S21_LDEC_BITS_CNT];
  uint32_t exp;
  uint32_t sign;
} s21_ldecimal;

#endif
