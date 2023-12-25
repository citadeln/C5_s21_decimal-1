#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  s21_decimal num1 = {.bits = {1}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {1}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_negate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_decimal num1 = {.bits = {0, 1}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0, 1}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_negate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_decimal num1 = {.bits = {S21_MAX_INT, 1}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {S21_MAX_INT, 1}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_negate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  s21_decimal num1 = {.bits = {0, 0, 1}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0, 0, 1}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_negate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_negate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(zero1) {
  // arrange
  s21_decimal num1 = {.bits = {0}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_negate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(zero2) {
  // arrange
  s21_decimal num1 = {.bits = {0}};
  num1.bits[3] = S21_MAKE_EXP(0, 1);

  s21_decimal result_num = {0};
  s21_decimal need_result_num = {.bits = {0}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_negate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(zero3) {
  // arrange
  s21_decimal num1 = {.bits = {1}};
  num1.bits[3] = S21_MAKE_EXP(30, 0);

  s21_decimal result_num = {0};
  s21_decimal need_result_num = {.bits = {1}};
  need_result_num.bits[3] = S21_MAKE_EXP(30, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_negate(num1, &result_num);

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
  int result = s21_negate(num1, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(not_init) {
  // arrange
  s21_decimal num1 = {.bits = {123}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_num = {.bits = {123}};
  need_result_num.bits[3] = S21_MAKE_EXP(1, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_negate(num1, &result_num);

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
  int result = s21_negate(value, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

Suite *negate_sc(void) {
  Suite *suite = suite_create("s21_negate");

  TCase *t_tc = tcase_create("s21_negate tests");
  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);
  tcase_add_test(t_tc, t5);

  tcase_add_test(t_tc, zero1);
  tcase_add_test(t_tc, zero2);
  tcase_add_test(t_tc, zero3);

  tcase_add_test(t_tc, null);
  tcase_add_test(t_tc, not_init);
  tcase_add_test(t_tc, not_correct_num);

  suite_add_tcase(suite, t_tc);

  return suite;
}

MAKE_TEST(negate)
