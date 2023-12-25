#include <check.h>

#include "./../../../lib/decimal/common/s21_dec_common.h"
#include "common_t.h"

START_TEST(t1) {
  // arrange
  s21_decimal num = {.bits = {11, 0, 0, S21_MAKE_EXP(1, 0)}};

  s21_decimal need_result_num = {.bits = {1}};
  int need_result = 1;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(bits1_to_bits0) {
  // 12345678912
  // arrange
  s21_decimal num = {
      .bits = {(int)0xDFDC1C40, (int)0x2, 0, S21_MAKE_EXP(1, 0)}};

  s21_decimal need_result_num = {.bits = {
                                     (int)0x499602D3,
                                 }};
  int need_result = 2;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bits2_to_bits1) {
  // 123456789123456789123
  // arrange
  s21_decimal num = {
      .bits = {(int)0x0DF36A83, (int)0xB14E9F9B, (int)0x6, S21_MAKE_EXP(1, 0)}};

  s21_decimal need_result_num = {.bits = {(int)0x81652440, (int)0xAB54A98F}};
  int need_result = 3;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(bits0) {
  // arrange
  // 1234567891
  s21_decimal num = {.bits = {(int)0x499602D3, 0, 0, S21_MAKE_EXP(1, 0)}};

  s21_decimal need_result_num = {.bits = {(int)0x75BCD15}};
  int need_result = 1;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bits1) {
  // arrange
  // 12345678912345678912
  s21_decimal num = {
      .bits = {(int)0x81652440, (int)0xAB54A98F, 0, S21_MAKE_EXP(1, 0)}};

  s21_decimal need_result_num = {.bits = {(int)0xC023B6D3, (int)0x112210F4, 0}};
  int need_result = 2;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bits2) {
  // arrange
  // 12345678912345678912345678919
  s21_decimal num = {.bits = {(int)0x71B52447, (int)0xE0F1624C, (int)0x27E41B32,
                              S21_MAKE_EXP(1, 0)}};

  s21_decimal need_result_num = {
      .bits = {(int)0xD82BB6D3, (int)0x7CE4F03A, (int)0x3FD35EB, 0}};
  int need_result = 9;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  s21_decimal num = {.bits = {13, 0, 0, S21_MAKE_EXP(2, 1)}};

  s21_decimal need_result_num = {.bits = {1, 0, 0, S21_MAKE_EXP(1, 1)}};
  int need_result = 3;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  s21_decimal num = {.bits = {17, 0, 0, S21_MAKE_EXP(1, 1)}};

  s21_decimal need_result_num = {.bits = {1, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = 7;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(zero) {
  // arrange
  s21_decimal num = {.bits = {0}};

  s21_decimal need_result_num = {.bits = {0}};
  int need_result = 0;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(to_zero) {
  // arrange
  s21_decimal num = {.bits = {5}};

  s21_decimal need_result_num = {.bits = {0}};
  int need_result = 5;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(exp_1) {
  // arrange
  s21_decimal num = {.bits = {56, 0, 0, S21_MAKE_EXP(0, 0)}};

  s21_decimal need_result_num = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 0)}};
  int need_result = 6;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(exp_2) {
  // arrange
  s21_decimal num = {.bits = {57, 0, 0, S21_MAKE_EXP(15, 0)}};

  s21_decimal need_result_num = {.bits = {5, 0, 0, S21_MAKE_EXP(14, 0)}};
  int need_result = 7;

  // act
  int result = s21_decimal_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

TCase *dec_shift_right_tc(void) {
  TCase *tc = tcase_create("s21_dec_shift_right");

  tcase_add_test(tc, t1);

  tcase_add_test(tc, bits1_to_bits0);
  tcase_add_test(tc, bits2_to_bits1);

  tcase_add_test(tc, bits0);
  tcase_add_test(tc, bits1);
  tcase_add_test(tc, bits2);

  tcase_add_test(tc, sign1);
  tcase_add_test(tc, sign2);

  tcase_add_test(tc, zero);
  tcase_add_test(tc, to_zero);

  tcase_add_test(tc, exp_1);
  tcase_add_test(tc, exp_2);

  return tc;
}
