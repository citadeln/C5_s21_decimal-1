#include <check.h>

#include "./../../../lib/decimal/common/s21_dec_common.h"
#include "common_t.h"

START_TEST(get_exp_0) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  num.bits[3] = S21_MAKE_EXP(0, S21_SIGN_MINUS);
  int need_result = 0;

  // act
  int result = s21_decimal_get_exp(&num);

  // assert
  ck_assert_int_eq(result, need_result);

  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], S21_MAKE_EXP(0, S21_SIGN_MINUS));
}
END_TEST

START_TEST(get_exp_15) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(15, S21_SIGN_MINUS)}};
  int need_result = 15;

  // act
  int result = s21_decimal_get_exp(&num);

  // assert
  ck_assert_int_eq(result, need_result);

  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], S21_MAKE_EXP(15, S21_SIGN_MINUS));
}
END_TEST

START_TEST(get_exp_28) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(28, S21_SIGN_MINUS)}};
  int need_result = 28;

  // act
  int result = s21_decimal_get_exp(&num);

  // assert
  ck_assert_int_eq(result, need_result);

  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], S21_MAKE_EXP(28, S21_SIGN_MINUS));
}
END_TEST

TCase *get_exp_tc(void) {
  TCase *tc = tcase_create("s21_decimal_get_exp");
  tcase_add_test(tc, get_exp_0);
  tcase_add_test(tc, get_exp_15);
  tcase_add_test(tc, get_exp_28);
  return tc;
}
