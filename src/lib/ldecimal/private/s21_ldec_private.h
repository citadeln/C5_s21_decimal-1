#ifndef S21_LDEC_PRIVATE_H
#define S21_LDEC_PRIVATE_H

#include <stdbool.h>

#include "./../common/s21_ldec_type.h"

#define LOW_BITS_MASK 0xffffffff
#define OVERFLOW_MASK 0xffffffff00000000
#define CHECK_OVERFLOW(x) ((result->bits[i] & OVERFLOW_MASK) ? 1 : 0)

bool s21_ldec_is_greater_raw(const s21_ldecimal *num1,
                             const s21_ldecimal *num2);
bool s21_ldec_sub_raw(const s21_ldecimal *num1, const s21_ldecimal *num2,
                      s21_ldecimal *result);
bool s21_ldec_add_raw(const s21_ldecimal *num1, const s21_ldecimal *num2,
                      s21_ldecimal *result);

int s21_ldec_convert_prepare(s21_ldecimal *num);
bool s21_dec_has_overflow(s21_ldecimal *num);

#endif
