#include <check.h>

#include "./../../../lib/ldecimal/private/s21_ldec_private.h"

START_TEST(t1) {
  // arrange
  s21_ldecimal num = {.bits = {1}};

  int need_result = false;

  // act
  int result = s21_dec_has_overflow(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_ldecimal num = {.bits = {0, 1}};

  int need_result = false;

  // act
  int result = s21_dec_has_overflow(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_ldecimal num = {.bits = {0, 0, 1}};

  int need_result = false;

  // act
  int result = s21_dec_has_overflow(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  s21_ldecimal num = {.bits = {0, 0, 0, 1}};

  int need_result = true;

  // act
  int result = s21_dec_has_overflow(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  s21_ldecimal num = {.bits = {0, 0, 0, 0, 1}};

  int need_result = true;

  // act
  int result = s21_dec_has_overflow(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  s21_ldecimal num = {.bits = {0, 0, 0, 0, 0, 1}};

  int need_result = true;

  // act
  int result = s21_dec_has_overflow(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  s21_ldecimal num = {.bits = {0, 0, 0, 0, 0, 0, 1}};

  int need_result = true;

  // act
  int result = s21_dec_has_overflow(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *dec_has_overflow_tc(void) {
  TCase *tc = tcase_create("s21_dec_has_overflow");

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);
  tcase_add_test(tc, t3);
  tcase_add_test(tc, t4);
  tcase_add_test(tc, t5);
  tcase_add_test(tc, t6);
  tcase_add_test(tc, t7);

  return tc;
}
