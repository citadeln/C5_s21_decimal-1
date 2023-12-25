#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(t1) {
  // arrange
  s21_ldecimal num1 = {.bits = {3247}, .exp = 2};
  s21_ldecimal num2 = {.bits = {3247}, .exp = 3};
  int need_result = false;

  // act
  int result = s21_ldec_is_equal(&num1, &num2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(null1) {
  // arrange
  s21_ldecimal num = {0};
  int need_result = false;

  // act
  int result = s21_ldec_is_equal(NULL, &num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null2) {
  // arrange
  s21_ldecimal num = {0};
  int need_result = false;

  // act
  int result = s21_ldec_is_equal(&num, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *ldec_is_equal_tc(void) {
  TCase *tc = tcase_create("s21_ldec_is_equal");

  tcase_add_test(tc, t1);

  tcase_add_test(tc, null1);
  tcase_add_test(tc, null2);

  return tc;
}
