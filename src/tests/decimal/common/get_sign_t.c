#include <check.h>

#include "./../../../lib/decimal/common/s21_dec_common.h"
#include "common_t.h"

START_TEST(get_plus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_PLUS)}};
  int need_result = S21_SIGN_PLUS;

  // act
  int result = s21_decimal_get_sign(&num);

  // assert
  ck_assert_int_eq(result, need_result);

  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], S21_MAKE_EXP(0xFF, S21_SIGN_PLUS));
}
END_TEST

START_TEST(get_minus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_MINUS)}};
  int need_result = S21_SIGN_MINUS;

  // act
  int result = s21_decimal_get_sign(&num);

  // assert
  ck_assert_int_eq(result, need_result);

  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], S21_MAKE_EXP(0xFF, S21_SIGN_MINUS));
}
END_TEST

TCase *get_sign_tc(void) {
  TCase *tc = tcase_create("get_sign");
  tcase_add_test(tc, get_plus);
  tcase_add_test(tc, get_minus);
  return tc;
}
