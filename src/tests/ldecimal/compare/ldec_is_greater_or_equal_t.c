#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(null1) {
  // arrange
  s21_ldecimal num1 = {0};
  int need_result = false;

  // act
  int result = s21_ldec_is_greater_or_equal(&num1, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null2) {
  // arrange
  s21_ldecimal num1 = {0};
  int need_result = false;

  // act
  int result = s21_ldec_is_greater_or_equal(NULL, &num1);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null3) {
  // arrange
  int need_result = false;

  // act
  int result = s21_ldec_is_greater_or_equal(NULL, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *ldec_is_greater_or_equal_tc(void) {
  TCase *tc = tcase_create("s21_ldec_is_greater_or_equal");

  tcase_add_test(tc, null1);
  tcase_add_test(tc, null2);
  tcase_add_test(tc, null3);

  return tc;
}
