#include <check.h>

#include "./../../../lib/decimal/common/s21_dec_common.h"
#include "common_t.h"

START_TEST(set_plus_to_minus_exp_filled) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_PLUS)}};
  int sign = S21_SIGN_MINUS;

  // act
  s21_decimal_set_sign(&num, sign);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], S21_MAKE_EXP(0xFF, S21_SIGN_MINUS));
}
END_TEST

START_TEST(set_minus_to_plus_exp_filled) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_MINUS)}};
  int sign = S21_SIGN_PLUS;

  // act
  s21_decimal_set_sign(&num, sign);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], S21_MAKE_EXP(0xFF, S21_SIGN_PLUS));
}
END_TEST

START_TEST(set_plus_to_minus_exp_zero) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0, S21_SIGN_PLUS)}};
  int sign = S21_SIGN_MINUS;

  // act
  s21_decimal_set_sign(&num, sign);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], S21_MAKE_EXP(0, S21_SIGN_MINUS));
}
END_TEST

START_TEST(set_minus_to_plus_exp_zero) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0, S21_SIGN_MINUS)}};
  int sign = S21_SIGN_PLUS;

  // act
  s21_decimal_set_sign(&num, sign);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], S21_MAKE_EXP(0, S21_SIGN_PLUS));
}
END_TEST

TCase *set_sign_tc(void) {
  TCase *tc = tcase_create("s21_decimal_set_sign");
  tcase_add_test(tc, set_plus_to_minus_exp_filled);
  tcase_add_test(tc, set_minus_to_plus_exp_filled);
  tcase_add_test(tc, set_plus_to_minus_exp_zero);
  tcase_add_test(tc, set_minus_to_plus_exp_zero);
  return tc;
}
