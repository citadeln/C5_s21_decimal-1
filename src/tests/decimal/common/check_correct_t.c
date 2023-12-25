#include <check.h>

#include "./../../../lib/decimal/common/s21_dec_common.h"

START_TEST(right_zero_bits) {
  s21_decimal num = {0};
  int need_result = false;

  for (int i = 0; i <= 15; i++) {
    num.bits[3] = (1 << i);
    int result = s21_decimal_check_correct(&num);
    ck_assert_int_eq(result, need_result);
  }
}
END_TEST

START_TEST(exp_bits) {
  s21_decimal num = {0};
  int need_result = true;

  for (int i = 16; i <= 23; i++) {
    num.bits[3] = (1 << i);
    int result = s21_decimal_check_correct(&num);
    ck_assert_int_eq(result, need_result);
  }
}
END_TEST

START_TEST(left_zero_bits) {
  s21_decimal num = {0};
  int need_result = false;

  for (int i = 24; i <= 30; i++) {
    num.bits[3] = (1 << i);
    int result = s21_decimal_check_correct(&num);
    ck_assert_int_eq(result, need_result);
  }
}
END_TEST

START_TEST(sign) {
  s21_decimal num = {0};
  num.bits[3] = (int)(1U << 31);
  int need_result = true;

  int result = s21_decimal_check_correct(&num);
  ck_assert_int_eq(result, need_result);
}
END_TEST

TCase *check_correct_tc(void) {
  TCase *tc = tcase_create("s21_decimal_check_correct");
  tcase_add_test(tc, right_zero_bits);
  tcase_add_test(tc, exp_bits);
  tcase_add_test(tc, left_zero_bits);
  tcase_add_test(tc, sign);
  return tc;
}
