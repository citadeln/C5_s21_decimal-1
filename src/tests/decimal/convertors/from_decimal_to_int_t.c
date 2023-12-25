#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  s21_decimal src = {.bits = {1}};
  int dst = 0;

  int need_dst = 1;
  int need_result = 0;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_decimal src = {.bits = {123456}};
  src.bits[3] = S21_MAKE_EXP(3, S21_SIGN_MINUS);
  int dst = 0;

  int need_dst = -123;
  int need_result = 0;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_decimal src = {.bits = {123456}};
  src.bits[3] = S21_MAKE_EXP(6, S21_SIGN_MINUS);
  int dst = 0;

  int need_dst = -0;
  int need_result = 0;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  s21_decimal src = {.bits = {0x7FFFFFFF}};
  int dst = 0;

  int need_dst = 0x7FFFFFFF;
  int need_result = 0;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(overflow1) {
  // arrange
  s21_decimal src = {.bits = {S21_MAX_INT}};
  src.bits[3] = S21_MAKE_EXP(0, 0);
  int dst = 0;

  int need_dst = 0;
  int need_result = 1;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow2) {
  // arrange
  s21_decimal src = {.bits = {(int)0x5FDC1C40, (int)0x2}};
  src.bits[3] = S21_MAKE_EXP(0, 0);
  int dst = 0;

  int need_dst = 0;
  int need_result = 1;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(zero1) {
  // arrange
  s21_decimal src = {.bits = {0}};
  src.bits[3] = S21_MAKE_EXP(0, 0);
  int dst = 0;

  int need_dst = 0;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(zero2) {
  // arrange
  s21_decimal src = {.bits = {0}};
  src.bits[3] = S21_MAKE_EXP(0, 1);
  int dst = 0;

  int need_dst = 0;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(zero3) {
  // arrange
  s21_decimal src = {.bits = {0}};
  src.bits[3] = S21_MAKE_EXP(28, 0);
  int dst = 0;

  int need_dst = 0;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(zero4) {
  // arrange
  s21_decimal src = {.bits = {1}};
  src.bits[3] = S21_MAKE_EXP(100, 0);
  int dst = 0;

  int need_dst = 0;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(error1) {
  // arrange
  s21_decimal src = {.bits = {1}};
  src.bits[3] = (1 << 30);
  int dst = 0;

  int need_dst = 0;
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(error2) {
  // arrange
  s21_decimal src = {0};

  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_decimal_to_int(src, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(not_init) {
  // arrange
  s21_decimal src = {.bits = {0}};
  src.bits[3] = S21_MAKE_EXP(0, 0);
  int dst = S21_MAX_INT;

  int need_dst = 0;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(null) {
  // arrange
  s21_decimal src = {0};

  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_decimal_to_int(src, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(convert_error) {
  // arrange
  s21_decimal src = {0};
  src.bits[3] = 1;
  int dst = 0;
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(maxexp1) {
  // arrange
  s21_decimal src = {0};
  src.bits[3] = (int)0x80FF0000;
  int dst = 0;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(maxexp2) {
  // arrange
  s21_decimal src = {.bits = {1}};
  src.bits[3] = (int)0x80FF0000;
  int dst = 0;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(maxexp3) {
  // arrange
  s21_decimal src = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  src.bits[3] = (int)0x80FF0000;
  int dst = 0;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_int(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST

Suite *from_decimal_to_int_sc(void) {
  Suite *suite = suite_create("s21_from_decimal_to_int");

  TCase *t_tc = tcase_create("s21_from_decimal_to_int");

  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);

  tcase_add_test(t_tc, overflow1);
  tcase_add_test(t_tc, overflow2);

  tcase_add_test(t_tc, zero1);
  tcase_add_test(t_tc, zero2);
  tcase_add_test(t_tc, zero2);
  tcase_add_test(t_tc, zero3);
  tcase_add_test(t_tc, zero4);

  tcase_add_test(t_tc, error1);
  tcase_add_test(t_tc, error2);

  tcase_add_test(t_tc, not_init);
  tcase_add_test(t_tc, null);
  tcase_add_test(t_tc, convert_error);

  tcase_add_test(t_tc, maxexp1);
  tcase_add_test(t_tc, maxexp2);
  tcase_add_test(t_tc, maxexp3);

  suite_add_tcase(suite, t_tc);

  return suite;
}

MAKE_TEST(from_decimal_to_int)
