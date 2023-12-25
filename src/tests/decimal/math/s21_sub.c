#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  s21_decimal num1 = {.bits = {1}};
  s21_decimal num2 = {.bits = {1}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_decimal num1 = {.bits = {0, 1}};
  s21_decimal num2 = {.bits = {1}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {S21_MAX_INT}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  // 36893488143124135936 - 18446744069414584321 = 18446744073709551615
  s21_decimal num1 = {.bits = {0, S21_MAX_INT, 1}};
  s21_decimal num2 = {.bits = {1, S21_MAX_INT}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {S21_MAX_INT, S21_MAX_INT}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(big_exp_not_overflow) {
  // arrange
  s21_decimal num1 = {.bits = {10, 0, 0, S21_MAKE_EXP(100, 0)}};
  s21_decimal num2 = {.bits = {12, 0, 0, S21_MAKE_EXP(100, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(big_exp_not_overflow2) {
  // arrange
  s21_decimal num1 = {.bits = {10}};
  s21_decimal num2 = {.bits = {12, 0, 0, S21_MAKE_EXP(100, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {10}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(big_exp_not_overflow3) {
  // arrange
  s21_decimal num1 = {.bits = {10}};
  s21_decimal num2 = {.bits = {12, 0, 0, S21_MAKE_EXP(56, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {10}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(big_exp_not_overflow4) {
  // arrange
  s21_decimal num1 = {.bits = {12, 0, 0, S21_MAKE_EXP(57, 0)}};
  s21_decimal num2 = {.bits = {10}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits0) {
  // arrange
  s21_decimal num1 = {.bits = {10}};
  s21_decimal num2 = {.bits = {7}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {3}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1) {
  // arrange
  s21_decimal num1 = {.bits = {S21_MAX_INT, 10}};
  s21_decimal num2 = {.bits = {S21_MAX_INT, 7}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0, 3}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2) {
  // arrange
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, 10}};
  s21_decimal num2 = {.bits = {S21_MAX_INT, S21_MAX_INT, 7}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0, 0, 3}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(less_sub_greater) {
  // arrange
  // 3 - 7 = -4
  s21_decimal num1 = {.bits = {3}};
  s21_decimal num2 = {.bits = {7}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {4, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(signs_plus_minus1) {
  // arrange
  s21_decimal num1 = {.bits = {7}};
  s21_decimal num2 = {.bits = {4, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {11}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(signs_plus_minus2) {
  // arrange
  s21_decimal num1 = {.bits = {7, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {4}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {11, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign1) {
  // arrange
  // 10 - -5 = 15
  s21_decimal num1 = {.bits = {10}};
  s21_decimal num2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {15}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  // 5 - -10 = 15
  s21_decimal num1 = {.bits = {5}};
  s21_decimal num2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {15}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign3) {
  // arrange
  // -10 - 5 = -15
  s21_decimal num1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {5}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {15, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign4) {
  // arrange
  // -5 - 10 = -15
  s21_decimal num1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {10}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {15, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign5) {
  // arrange
  // -5 - -10 = 5
  s21_decimal num1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign6) {
  // arrange
  // -10 - -10 = 0
  s21_decimal num1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign7) {
  // arrange
  // -10 - -5 = 15
  s21_decimal num1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign8) {
  // arrange
  // -10 - 10 = -20
  s21_decimal num1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {10}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {20, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign9) {
  // arrange
  // 10 - -10 = 20
  s21_decimal num1 = {.bits = {10}};
  s21_decimal num2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {20}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(overflow1) {
  // arrange
  // max - -max = overflow
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal num2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  int need_result = S21_BIG_NUM_ERROR;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow2) {
  // arrange
  // max - max = 0
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal num2 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow3) {
  // arrange
  // -max - max = -overflow
  s21_decimal num1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal result_value = {0};

  int need_result = S21_SMALL_NUM_ERROR;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow4) {
  // arrange
  // -max - -max = 0
  s21_decimal num1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(num_is_zero1) {
  // arrange
  s21_decimal num1 = {.bits = {0}};
  s21_decimal num2 = {.bits = {1231234}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1231234, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(num_is_zero2) {
  // arrange
  s21_decimal num1 = {.bits = {1231234}};
  s21_decimal num2 = {.bits = {0}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1231234}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(null1) {
  // arrange
  s21_decimal num = {0};

  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_sub(num, num, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(result_not_init1) {
  // arrange
  // 8789723481274892213434253245 -
  // 234897346278979798347234 =
  // 8789958378621171193232600479
  s21_decimal value_1 = {
      .bits = {(int)0xB308FFBD, (int)0xB27F44AC, (int)0x1C66B058}};
  s21_decimal value_2 = {
      .bits = {(int)0xC3B4ADE2, (int)0xCF873D40, (int)0x31BD}};
  s21_decimal result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_value = {
      .bits = {(int)0xEF5451DB, (int)0xE2F8076B, (int)0x1C667E9A}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(result_not_init2) {
  // arrange
  s21_decimal value_1 = {.bits = {2}};
  s21_decimal value_2 = {.bits = {2}};
  s21_decimal result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_sub(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(not_correct_num1) {
  // arrange
  s21_decimal value_1 = {.bits = {2}};
  value_1.bits[3] = 1;
  s21_decimal value_2 = {.bits = {1}};
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_sub(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(not_correct_num2) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  s21_decimal value_2 = {.bits = {1}};
  value_2.bits[3] = 1;
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_sub(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

Suite *sub_sc(void) {
  Suite *suite = suite_create("s21_sub");

  TCase *t_tc = tcase_create("s21_sub tests");
  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, less_sub_greater);
  tcase_add_test(t_tc, big_exp_not_overflow);
  tcase_add_test(t_tc, big_exp_not_overflow2);
  tcase_add_test(t_tc, big_exp_not_overflow3);
  tcase_add_test(t_tc, big_exp_not_overflow4);
  tcase_add_test(t_tc, not_correct_num1);
  tcase_add_test(t_tc, not_correct_num2);

  suite_add_tcase(suite, t_tc);

  TCase *bits_tc = tcase_create("s21_sub bits");
  tcase_add_test(bits_tc, bits0);
  tcase_add_test(bits_tc, bits1);
  tcase_add_test(bits_tc, bits2);
  suite_add_tcase(suite, bits_tc);

  TCase *signs_tc = tcase_create("s21_sub signs");
  tcase_add_test(signs_tc, signs_plus_minus1);
  tcase_add_test(signs_tc, signs_plus_minus2);
  tcase_add_test(signs_tc, sign1);
  tcase_add_test(signs_tc, sign2);
  tcase_add_test(signs_tc, sign3);
  tcase_add_test(signs_tc, sign4);
  tcase_add_test(signs_tc, sign5);
  tcase_add_test(signs_tc, sign6);
  tcase_add_test(signs_tc, sign7);
  tcase_add_test(signs_tc, sign8);
  tcase_add_test(signs_tc, sign9);
  suite_add_tcase(suite, signs_tc);

  TCase *overflow_tc = tcase_create("s21_sub overflow");
  tcase_add_test(overflow_tc, overflow1);
  tcase_add_test(overflow_tc, overflow2);
  tcase_add_test(overflow_tc, overflow3);
  tcase_add_test(overflow_tc, overflow4);
  suite_add_tcase(suite, overflow_tc);

  TCase *num_is_zero_tc = tcase_create("s21_sub num_is_zero");
  tcase_add_test(num_is_zero_tc, num_is_zero1);
  tcase_add_test(num_is_zero_tc, num_is_zero2);
  suite_add_tcase(suite, num_is_zero_tc);

  TCase *null_tc = tcase_create("s21_sub null");
  tcase_add_test(null_tc, null1);
  suite_add_tcase(suite, null_tc);

  TCase *not_init_tc = tcase_create("s21_sub result not init");
  tcase_add_test(not_init_tc, result_not_init1);
  tcase_add_test(not_init_tc, result_not_init2);
  suite_add_tcase(suite, not_init_tc);

  return suite;
}

MAKE_TEST(sub)
