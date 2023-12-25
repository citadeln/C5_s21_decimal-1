#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

// Return
#define S21_RESULT_OK 0
#define S21_CONVERT_ERROR 1
#define S21_BIG_NUM_ERROR 1
#define S21_SMALL_NUM_ERROR 2
#define S21_DIV_ZERO_ERROR 3
#define S21_RESULT_ERROR 4

// Sign
#define S21_SIGN_PLUS 0
#define S21_SIGN_MINUS 1

// float
#define S21_MIN_DECIMAL 1e-29
#define S21_MAX_DECIMAL 7.922816e28F

// Decimal struct
#define S21_DEC_BITS_CNT 3
#define S21_DEC_ARR_CNT 4

typedef struct {
  int bits[4];
} s21_decimal;

// Math
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Compare
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// Convertors
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Other
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif
