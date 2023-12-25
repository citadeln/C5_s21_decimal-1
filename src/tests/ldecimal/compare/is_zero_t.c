#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(t1) {
  // arrange
  const s21_ldecimal num = {.bits = {1}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_zero(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  // 10000000000000000000000000000000000000000000000000000000000000000000
  const s21_ldecimal num = {
      .bits = {0x00000000, 0x00000000, 0xB6891BE8, 0x8E5F518B, 0x1EA97776,
               0x21E86476, 0x5EF4A747},
      .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_zero(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  // 10000000000000000000000000000000000000000000000000000000000000000000
  const s21_ldecimal num = {
      .bits = {0x00000000, 0x00000000, 0xB6891BE8, 0x8E5F518B, 0x1EA97776,
               0x21E86476, 0x5EF4A747},
      .exp = 67};

  int need_result = false;

  // act
  int result = s21_ldec_is_zero(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  const s21_ldecimal num = {.bits = {1}, .exp = 67, .sign = 1};

  int need_result = false;

  // act
  int result = s21_ldec_is_zero(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  const s21_ldecimal num = {.bits = {1}, .exp = 0, .sign = 1};

  int need_result = false;

  // act
  int result = s21_ldec_is_zero(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  const s21_ldecimal num = {.bits = {0}};

  int need_result = true;

  // act
  int result = s21_ldec_is_zero(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  const s21_ldecimal num = {.bits = {0}, .exp = 67};

  int need_result = true;

  // act
  int result = s21_ldec_is_zero(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t8) {
  // arrange
  const s21_ldecimal num = {.bits = {0}, .exp = 67, .sign = 1};

  int need_result = true;

  // act
  int result = s21_ldec_is_zero(&num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(null) {
  // arrange
  int need_result = false;

  // act
  int result = s21_ldec_is_zero(NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *is_zero_tc(void) {
  TCase *tc = tcase_create("s21_ldec_is_zero");

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);
  tcase_add_test(tc, t3);
  tcase_add_test(tc, t4);
  tcase_add_test(tc, t5);
  tcase_add_test(tc, t6);
  tcase_add_test(tc, t7);
  tcase_add_test(tc, t8);

  tcase_add_test(tc, null);

  return tc;
}
