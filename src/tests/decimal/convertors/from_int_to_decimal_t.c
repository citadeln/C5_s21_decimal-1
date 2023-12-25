#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t_NULL) {
  // arrange
  int src = -123;
  int need_result = 1;

  // act
  int result = s21_from_int_to_decimal(src, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(t1) {
  // arrange
  int src = 123;
  s21_decimal dst = {0};

  int need_bits0 = 123;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = 0;
  int need_result = 0;

  // act
  int result = s21_from_int_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

START_TEST(t2) {
  // arrange
  int src = -123;
  s21_decimal dst = {0};

  int need_bits0 = 123;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = S21_MAKE_EXP(0, S21_SIGN_MINUS);
  int need_result = 0;

  // act
  int result = s21_from_int_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

START_TEST(t3) {
  // arrange
  int src = 0;
  s21_decimal dst = {0};

  int need_bits0 = 0;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = 0;
  int need_result = 0;

  // act
  int result = s21_from_int_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

START_TEST(t4) {
  // arrange
  int src = 1;
  s21_decimal dst = {0};

  int need_bits0 = 1;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = 0;
  int need_result = 0;

  // act
  int result = s21_from_int_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

START_TEST(t5) {
  // arrange
  int src = -1;
  s21_decimal dst = {0};

  int need_bits0 = 1;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = S21_MAKE_EXP(0, S21_SIGN_MINUS);
  int need_result = 0;

  // act
  int result = s21_from_int_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

START_TEST(t6) {
  // arrange
  int src = 0x7F;  // Max int
  s21_decimal dst = {0};

  int need_bits0 = 0x7F;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = 0;
  int need_result = 0;

  // act
  int result = s21_from_int_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

START_TEST(t7) {
  // arrange
  int src = -0x80;  // Min int
  s21_decimal dst = {0};

  int need_bits0 = 0x80;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = S21_MAKE_EXP(0, S21_SIGN_MINUS);
  int need_result = 0;

  // act
  int result = s21_from_int_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

START_TEST(t8) {
  // arrange
  int src = 0;
  s21_decimal dst = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT,
                              S21_MAKE_EXP(0xFF, S21_SIGN_MINUS)}};

  int need_bits0 = 0;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = 0;
  int need_result = 0;

  // act
  int result = s21_from_int_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

START_TEST(null) {
  // arrange
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_int_to_decimal(0, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(not_init) {
  // arrange
  int src = 123;
  s21_decimal dst = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  int need_bits0 = 123;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = 0;
  int need_result = 0;

  // act
  int result = s21_from_int_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

Suite *from_int_to_decimal_sc(void) {
  Suite *suite = suite_create("s21_from_int_to_decimal");

  TCase *t_tc = tcase_create("s21_from_int_to_decimal");
  tcase_add_test(t_tc, t_NULL);
  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);
  tcase_add_test(t_tc, t5);
  tcase_add_test(t_tc, t6);
  tcase_add_test(t_tc, t7);
  tcase_add_test(t_tc, t8);

  tcase_add_test(t_tc, null);
  tcase_add_test(t_tc, not_init);

  suite_add_tcase(suite, t_tc);

  return suite;
}

MAKE_TEST(from_int_to_decimal)
