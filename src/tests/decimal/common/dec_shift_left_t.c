#include <check.h>

#include "./../../../lib/decimal/common/s21_dec_common.h"
#include "common_t.h"

START_TEST(t1) {
  // arrange
  s21_decimal num = {.bits = {1, 0, 0, 0}};

  s21_decimal need_result_num = {.bits = {10, 0, 0, S21_MAKE_EXP(1, 0)}};
  int need_result = true;

  // act
  int result = s21_decimal_shift_left(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(bits0_to_bits1) {
  // 1234567891

  // arrange
  s21_decimal num = {.bits = {(int)0x499602D3, 0, 0, 0}};

  s21_decimal need_result_num = {
      .bits = {(int)0xDFDC1C3E, (int)0x2, 0, S21_MAKE_EXP(1, 0)}};
  int need_result = true;

  // act
  int result = s21_decimal_shift_left(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bits1_to_bits2) {
  // 12345678912345678912

  // arrange
  s21_decimal num = {.bits = {(int)0x81652440, (int)0xAB54A98F, 0, 0}};

  s21_decimal need_result_num = {
      .bits = {(int)0x0DF36A80, (int)0xB14E9F9B, (int)0x6, S21_MAKE_EXP(1, 0)}};
  int need_result = true;

  // act
  int result = s21_decimal_shift_left(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(bits0) {
  // arrange
  s21_decimal num = {.bits = {(int)0x75BCD15, 0, 0, 0}};

  s21_decimal need_result_num = {
      .bits = {(int)0x499602D2, 0, 0, S21_MAKE_EXP(1, 0)}};
  int need_result = true;

  // act
  int result = s21_decimal_shift_left(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bits1) {
  // arrange
  // 1234567891234567891
  s21_decimal num = {.bits = {(int)0xC023B6D3, (int)0x112210F4, 0}};

  s21_decimal need_result_num = {
      .bits = {(int)0x8165243E, (int)0xAB54A98F, 0, S21_MAKE_EXP(1, 0)}};
  int need_result = true;

  // act
  int result = s21_decimal_shift_left(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bits2) {
  // arrange
  s21_decimal num = {
      .bits = {(int)0xD82BB6D3, (int)0x7CE4F03A, (int)0x3FD35EB, 0}};

  s21_decimal need_result_num = {.bits = {(int)0x71B5243E, (int)0xE0F1624C,
                                          (int)0x27E41B32, S21_MAKE_EXP(1, 0)}};
  int need_result = true;

  // act
  int result = s21_decimal_shift_left(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(overflow) {
  // arrange
  s21_decimal num = {
      .bits = {(int)0x71B52440, (int)0xE0F1624C, (int)0x27E41B32, 0}};

  s21_decimal need_result_num = {.bits = {(int)0x71136A80, (int)0xC96DD6FC,
                                          (int)0x8EE90FFC, S21_MAKE_EXP(1, 0)}};
  int need_result = false;

  // act
  int result = s21_decimal_shift_left(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  s21_decimal num = {.bits = {111, 0, 0, S21_MAKE_EXP(10, 1)}};

  s21_decimal need_result_num = {.bits = {1110, 0, 0, S21_MAKE_EXP(11, 1)}};
  int need_result = true;

  // act
  int result = s21_decimal_shift_left(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  s21_decimal num = {.bits = {111, 0, 0, S21_MAKE_EXP(0, 1)}};

  s21_decimal need_result_num = {.bits = {1110, 0, 0, S21_MAKE_EXP(1, 1)}};
  int need_result = true;

  // act
  int result = s21_decimal_shift_left(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

TCase *dec_shift_left_tc(void) {
  TCase *tc = tcase_create("s21_dec_shift_left");

  tcase_add_test(tc, t1);

  tcase_add_test(tc, bits0_to_bits1);
  tcase_add_test(tc, bits1_to_bits2);

  tcase_add_test(tc, bits0);
  tcase_add_test(tc, bits1);
  tcase_add_test(tc, bits2);

  tcase_add_test(tc, overflow);

  tcase_add_test(tc, sign1);
  tcase_add_test(tc, sign2);

  return tc;
}
