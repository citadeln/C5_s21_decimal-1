#include <check.h>
#include <stdbool.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(exp_not_equal1) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {123}};
  value_2.bits[3] = S21_MAKE_EXP(2, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_not_equal2) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {123}};
  value_2.bits[3] = S21_MAKE_EXP(3, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_not_equal3) {
  // arrange
  s21_decimal value_1 = {.bits = {123}};
  value_1.bits[3] = S21_MAKE_EXP(2, 0);
  s21_decimal value_2 = {.bits = {1}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_not_equal4) {
  // arrange
  s21_decimal value_1 = {.bits = {123}};
  value_1.bits[3] = S21_MAKE_EXP(3, 0);
  s21_decimal value_2 = {.bits = {1}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(exp_equal1) {
  // arrange
  s21_decimal value_1 = {.bits = {123}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {123}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_equal2) {
  // arrange
  s21_decimal value_1 = {.bits = {123}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {1}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_equal3) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {123}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_equal4) {
  // arrange
  s21_decimal value_1 = {.bits = {123}};
  value_1.bits[3] = S21_MAKE_EXP(28, 0);
  s21_decimal value_2 = {.bits = {123}};
  value_2.bits[3] = S21_MAKE_EXP(28, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_equal5) {
  // arrange
  s21_decimal value_1 = {.bits = {123}};
  value_1.bits[3] = S21_MAKE_EXP(28, 0);
  s21_decimal value_2 = {.bits = {12}};
  value_2.bits[3] = S21_MAKE_EXP(28, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits1_1) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT, 123}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {S21_MAX_INT, 122}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1_2) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT, 122}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {S21_MAX_INT, 122}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1_3) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT, 121}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {S21_MAX_INT, 122}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits2_1) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, 123}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {S21_MAX_INT, S21_MAX_INT, 122}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2_2) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, 122}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {S21_MAX_INT, S21_MAX_INT, 122}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2_3) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, 121}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {S21_MAX_INT, S21_MAX_INT, 122}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign_minus_plus1) {
  // -10 >= 5 ? false
  // arrange
  s21_decimal value_1 = {.bits = {10}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_minus_plus2) {
  // -5 >= 10 ? false
  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {10}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_minus_plus3) {
  // -5 >= 5 ? false

  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_plus_minus1) {
  // 10 >= -5 ? true

  // arrange
  s21_decimal value_1 = {.bits = {10}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_plus_minus2) {
  // 5 >= -10 ? true

  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {10}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_plus_minus3) {
  // 5 >= -5 ? true

  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign_minus_minus1) {
  // -5 >= -10 ? true

  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {10}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_minus_minus2) {
  // -10 >= -5 ? false

  // arrange
  s21_decimal value_1 = {.bits = {10}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_minus_minus3) {
  // -5 >= -5 ? true

  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(not_correct_num1) {
  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = 1;
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(not_correct_num2) {
  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = (1 << 27);
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(not_correct_num3) {
  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = 1;

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(not_correct_num4) {
  // arrange
  s21_decimal value_1 = {.bits = {5}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {5}};
  value_2.bits[3] = (1 << 14);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(min_max1) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {9}};
  value_2.bits[3] = S21_MAKE_EXP(29, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(min_max2) {
  // arrange
  s21_decimal value_1 = {.bits = {9}};
  value_1.bits[3] = S21_MAKE_EXP(29, 0);
  s21_decimal value_2 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(zero1) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {0}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero2) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {0}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero3) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  value_1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal value_2 = {.bits = {0}};
  value_2.bits[3] = S21_MAKE_EXP(0, 1);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero4) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {0}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero5) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  value_1.bits[3] = S21_MAKE_EXP(4, 0);
  s21_decimal value_2 = {.bits = {0}};
  value_2.bits[3] = S21_MAKE_EXP(20, 1);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero6) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {1}};
  value_2.bits[3] = S21_MAKE_EXP(1, 0);

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero7) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  value_1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal value_2 = {.bits = {0}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(maxexp1) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  value_1.bits[3] = (int)0x80FF0000;
  s21_decimal value_2 = {.bits = {0}};
  value_2.bits[3] = S21_MAKE_EXP(0, 0);

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(maxexp2) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {0}};
  value_2.bits[3] = (int)0x80FF0000;

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(maxexp3) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  value_1.bits[3] = (int)0x80FF0000;
  s21_decimal value_2 = {.bits = {1}};
  value_2.bits[3] = (int)0x80FF0000;

  int need_result = true;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(maxexp4) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  value_1.bits[3] = (int)0x80FF0000;
  s21_decimal value_2 = {.bits = {1}};

  int need_result = false;

  // act
  int result = s21_is_greater_or_equal(value_1, value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

Suite *is_greater_or_equal_sc(void) {
  Suite *suite = suite_create("s21_is_greater_or_equal");
  TCase *tc = tcase_create("s21_is_greater_or_equal");

  tcase_add_test(tc, exp_not_equal1);
  tcase_add_test(tc, exp_not_equal2);
  tcase_add_test(tc, exp_not_equal3);
  tcase_add_test(tc, exp_not_equal4);

  tcase_add_test(tc, exp_equal1);
  tcase_add_test(tc, exp_equal2);
  tcase_add_test(tc, exp_equal3);
  tcase_add_test(tc, exp_equal4);
  tcase_add_test(tc, exp_equal5);

  tcase_add_test(tc, bits1_1);
  tcase_add_test(tc, bits1_2);
  tcase_add_test(tc, bits1_3);

  tcase_add_test(tc, bits2_1);
  tcase_add_test(tc, bits2_2);
  tcase_add_test(tc, bits2_3);

  tcase_add_test(tc, sign_minus_plus1);
  tcase_add_test(tc, sign_minus_plus2);
  tcase_add_test(tc, sign_minus_plus3);

  tcase_add_test(tc, sign_plus_minus1);
  tcase_add_test(tc, sign_plus_minus2);
  tcase_add_test(tc, sign_plus_minus3);

  tcase_add_test(tc, sign_minus_minus1);
  tcase_add_test(tc, sign_minus_minus2);
  tcase_add_test(tc, sign_minus_minus3);

  tcase_add_test(tc, not_correct_num1);
  tcase_add_test(tc, not_correct_num2);
  tcase_add_test(tc, not_correct_num3);
  tcase_add_test(tc, not_correct_num4);

  tcase_add_test(tc, min_max1);
  tcase_add_test(tc, min_max2);

  tcase_add_test(tc, zero1);
  tcase_add_test(tc, zero2);
  tcase_add_test(tc, zero3);
  tcase_add_test(tc, zero4);
  tcase_add_test(tc, zero5);
  tcase_add_test(tc, zero6);
  tcase_add_test(tc, zero7);

  tcase_add_test(tc, maxexp1);
  tcase_add_test(tc, maxexp2);
  tcase_add_test(tc, maxexp3);
  tcase_add_test(tc, maxexp4);

  suite_add_tcase(suite, tc);

  return suite;
}

MAKE_TEST(is_greater_or_equal)
