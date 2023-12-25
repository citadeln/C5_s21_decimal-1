#ifndef S21_LDECIMAL_H
#define S21_LDECIMAL_H

#include <stdbool.h>

#include "./../../s21_decimal.h"
#include "./common/s21_ldec_type.h"

// Math
bool s21_ldec_add(s21_ldecimal *num1, s21_ldecimal *num2, s21_ldecimal *result);
bool s21_ldec_sub(s21_ldecimal *num1, s21_ldecimal *num2, s21_ldecimal *result);
bool s21_ldec_mul(s21_ldecimal *num1, s21_ldecimal *num2, s21_ldecimal *result);
bool s21_ldec_div(s21_ldecimal *num1, s21_ldecimal *num2, s21_ldecimal *result);

// Convertors
s21_ldecimal s21_dec_to_ldec(const s21_decimal *src);
int s21_ldec_to_dec(s21_ldecimal *src, s21_decimal *dst);

// Compare
bool s21_ldec_is_greater(s21_ldecimal *value_1, s21_ldecimal *value_2);
bool s21_ldec_is_greater_or_equal(s21_ldecimal *num1, s21_ldecimal *num2);
bool s21_ldec_is_equal(s21_ldecimal *num1, s21_ldecimal *num2);
bool s21_ldec_is_zero(const s21_ldecimal *num);

// Common
uint32_t s21_ldec_overflow_handler(s21_ldecimal *src);
uint32_t s21_ldec_shift_left(s21_ldecimal *num, int cnt);
uint32_t s21_ldec_shift_right(s21_ldecimal *num);
bool s21_ldec_make_exp_equal(s21_ldecimal *num1, s21_ldecimal *num2);

#endif
