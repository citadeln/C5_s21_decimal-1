#ifndef S21_DECIMAL_COMMON
#define S21_DECIMAL_COMMON

#include <stdbool.h>

#include "./../../../s21_decimal.h"

void s21_decimal_set_sign(s21_decimal *num, int sign);
int s21_decimal_get_sign(const s21_decimal *num);
void s21_decimal_set_exp(s21_decimal *num, int exp);
int s21_decimal_get_exp(const s21_decimal *num);

bool s21_decimal_check_correct(const s21_decimal *num);

bool s21_decimal_shift_left(s21_decimal *num);
int s21_decimal_shift_right(s21_decimal *num);

void s21_clear_num(s21_decimal *num);

#endif
