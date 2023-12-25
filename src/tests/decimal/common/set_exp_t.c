#include <check.h>

#include "./../../../lib/decimal/common/s21_dec_common.h"
#include "common_t.h"

// Set exp to 0
START_TEST(set_exp_0_exp_filled_sign_plus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_PLUS)}};
  int exp = 0;

  int need_bits3 = 0x0;

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST
START_TEST(set_exp_0_exp_filled_sign_minus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_MINUS)}};
  int exp = 0;

  int need_bits3 = S21_MAKE_EXP(0, S21_SIGN_MINUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST
START_TEST(set_exp_0_exp_zero_sign_plus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0, S21_SIGN_PLUS)}};
  int exp = 0;

  int need_bits3 = 0x0;

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST
START_TEST(set_exp_0_exp_zero_sign_minus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0, S21_SIGN_MINUS)}};
  int exp = 0;

  int need_bits3 = S21_MAKE_EXP(0, S21_SIGN_MINUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST

// Set exp to 15
START_TEST(set_exp_15_exp_filled_sign_plus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_PLUS)}};
  int exp = 15;

  // 00000000000000000000111100000000 = 0000000000000000 00001111 0000000 0
  // exp = 15, sign = plus
  int need_bits3 = S21_MAKE_EXP(15, S21_SIGN_PLUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST
START_TEST(set_exp_15_exp_filled_sign_minus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_MINUS)}};
  int exp = 15;

  // 00000000000000000000111100000001 = 0000000000000000 00001111 0000000 1
  // exp = 15, sign = minus
  int need_bits3 = S21_MAKE_EXP(15, S21_SIGN_MINUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST
START_TEST(set_exp_15_exp_zero_sign_plus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0, S21_SIGN_PLUS)}};
  int exp = 15;

  int need_bits3 = S21_MAKE_EXP(15, S21_SIGN_PLUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST
START_TEST(set_exp_15_exp_zero_sign_minus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0, S21_SIGN_MINUS)}};
  int exp = 15;

  int need_bits3 = S21_MAKE_EXP(15, S21_SIGN_MINUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST

// Set exp to 28
START_TEST(set_exp_28_exp_filled_sign_plus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_PLUS)}};
  int exp = 28;

  // 00000000000000000001110000000000 = 0000000000000000 00011100 0000000 0
  // exp = 28, sign = plus
  int need_bits3 = S21_MAKE_EXP(28, S21_SIGN_PLUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST
START_TEST(set_exp_28_exp_filled_sign_minus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_MINUS)}};
  int exp = 28;

  int need_bits3 = S21_MAKE_EXP(28, S21_SIGN_MINUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST
START_TEST(set_exp_28_exp_zero_sign_plus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0, S21_SIGN_PLUS)}};
  int exp = 28;

  int need_bits3 = S21_MAKE_EXP(28, S21_SIGN_PLUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST
START_TEST(set_exp_28_exp_zero_sign_minus) {
  // arrange
  s21_decimal num = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0, S21_SIGN_MINUS)}};
  int exp = 28;

  int need_bits3 = S21_MAKE_EXP(28, S21_SIGN_MINUS);

  // act
  s21_decimal_set_exp(&num, exp);

  // assert
  ck_assert_int_eq(num.bits[0], S21_MAX_INT);
  ck_assert_int_eq(num.bits[1], S21_MAX_INT);
  ck_assert_int_eq(num.bits[2], S21_MAX_INT);
  ck_assert_int_eq(num.bits[3], need_bits3);
}
END_TEST

TCase *set_exp_tc(void) {
  TCase *tc = tcase_create("s21_decimal_set_exp");
  tcase_add_test(tc, set_exp_0_exp_filled_sign_plus);
  tcase_add_test(tc, set_exp_0_exp_filled_sign_minus);
  tcase_add_test(tc, set_exp_0_exp_zero_sign_plus);
  tcase_add_test(tc, set_exp_0_exp_zero_sign_minus);

  tcase_add_test(tc, set_exp_15_exp_filled_sign_plus);
  tcase_add_test(tc, set_exp_15_exp_filled_sign_minus);
  tcase_add_test(tc, set_exp_15_exp_zero_sign_plus);
  tcase_add_test(tc, set_exp_15_exp_zero_sign_minus);

  tcase_add_test(tc, set_exp_28_exp_filled_sign_plus);
  tcase_add_test(tc, set_exp_28_exp_filled_sign_minus);
  tcase_add_test(tc, set_exp_28_exp_zero_sign_plus);
  tcase_add_test(tc, set_exp_28_exp_zero_sign_minus);
  return tc;
}
