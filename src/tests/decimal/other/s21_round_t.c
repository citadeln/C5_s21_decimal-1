#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  s21_decimal num1 = {.bits = {1}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_decimal num1 = {.bits = {19345678}};
  num1.bits[3] = S21_MAKE_EXP(7, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {2}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_decimal num1 = {.bits = {19345678}};
  num1.bits[3] = S21_MAKE_EXP(7, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {2}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  num1.bits[3] = S21_MAKE_EXP(1, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)0x9999999A, (int)0x99999999, (int)0x19999999}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  // 7922816251426433759354395033.5
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)0x9999999A, (int)0x99999999, (int)0x19999999}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  s21_decimal num1 = {.bits = {1}};
  num1.bits[3] = S21_MAKE_EXP(28, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  s21_decimal num1 = {.bits = {1}};
  num1.bits[3] = S21_MAKE_EXP(29, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t8) {
  // arrange
  s21_decimal num1 = {.bits = {0}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t9) {
  // arrange
  // -7.9228162514264337593543950335
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  num1.bits[3] = S21_MAKE_EXP(28, S21_SIGN_MINUS);

  s21_decimal result_num = {0};
  s21_decimal need_result_num = {.bits = {8}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, S21_SIGN_MINUS);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(bank_round1) {
  // arrange
  s21_decimal num1 = {.bits = {12345655}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1234566}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bank_round2) {
  // arrange
  s21_decimal num1 = {.bits = {12345665}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1234566}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bank_round3) {
  // arrange
  s21_decimal num1 = {.bits = {1234565501}};
  num1.bits[3] = S21_MAKE_EXP(3, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1234566}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bank_round4) {
  // arrange
  s21_decimal num1 = {.bits = {1234566501}};
  num1.bits[3] = S21_MAKE_EXP(3, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1234567}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bank_round5) {
  // arrange
  s21_decimal num1 = {.bits = {12345655}};
  num1.bits[3] = S21_MAKE_EXP(1, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1234566}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bank_round6) {
  // arrange
  s21_decimal num1 = {.bits = {12345665}};
  num1.bits[3] = S21_MAKE_EXP(1, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1234566}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bank_round7) {
  // arrange
  s21_decimal num1 = {.bits = {1234565501}};
  num1.bits[3] = S21_MAKE_EXP(3, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1234566}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bank_round8) {
  // arrange
  s21_decimal num1 = {.bits = {1234566501}};
  num1.bits[3] = S21_MAKE_EXP(3, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1234567}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(null) {
  // arrange
  s21_decimal num1 = {.bits = {1}};
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_round(num1, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(not_init) {
  // arrange
  s21_decimal num1 = {.bits = {135}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_num = {.bits = {14}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_round(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(not_correct_num) {
  // arrange
  s21_decimal value = {.bits = {2}};
  value.bits[3] = 1;
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_round(value, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

Suite *round_sc(void) {
  Suite *suite = suite_create("s21_round");

  TCase *t_tc = tcase_create("s21_round tests");
  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);
  tcase_add_test(t_tc, t5);
  tcase_add_test(t_tc, t6);
  tcase_add_test(t_tc, t7);
  tcase_add_test(t_tc, t8);
  tcase_add_test(t_tc, t9);

  tcase_add_test(t_tc, bank_round1);
  tcase_add_test(t_tc, bank_round2);
  tcase_add_test(t_tc, bank_round3);
  tcase_add_test(t_tc, bank_round4);
  tcase_add_test(t_tc, bank_round5);
  tcase_add_test(t_tc, bank_round6);
  tcase_add_test(t_tc, bank_round7);
  tcase_add_test(t_tc, bank_round8);

  tcase_add_test(t_tc, null);
  tcase_add_test(t_tc, not_init);
  tcase_add_test(t_tc, not_correct_num);

  suite_add_tcase(suite, t_tc);

  return suite;
}

MAKE_TEST(round)
