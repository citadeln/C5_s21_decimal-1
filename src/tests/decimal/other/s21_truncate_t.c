#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  s21_decimal num1 = {.bits = {1}};
  num1.bits[3] = S21_MAKE_EXP(1, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_decimal num1 = {.bits = {123}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {12}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_decimal num1 = {.bits = {0, 1}};
  num1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0, 1}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  // 1FFFFFFFF
  s21_decimal num1 = {.bits = {S21_MAX_INT, 1}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {(int)0x33333333}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  // 1FFFFFFFFFFFFFFFF
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, 1}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {(int)0x33333333, (int)0x33333333}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  // FFFFFFFFFFFFFFFFFFFFFFFF
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)0x99999999, (int)0x99999999, (int)0x19999999}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  // FFFFFFFFFFFFFFFFFFFFFFFF
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  num1.bits[3] = S21_MAKE_EXP(28, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {7}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
END_TEST
START_TEST(t8) {
  // arrange
  // FFFFFFFFFFFFFFFFFFFFFFFF
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  num1.bits[3] = S21_MAKE_EXP(28, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {7}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(zero1) {
  // arrange
  s21_decimal num1 = {.bits = {0}};
  num1.bits[3] = S21_MAKE_EXP(28, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(zero2) {
  // arrange
  s21_decimal num1 = {.bits = {0}};
  num1.bits[3] = S21_MAKE_EXP(28, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(zero3) {
  // arrange
  s21_decimal num1 = {.bits = {0}};
  num1.bits[3] = S21_MAKE_EXP(0, 1);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {0}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

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
  int result = s21_truncate(num1, NULL);

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

  s21_decimal need_result_num = {.bits = {12}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_truncate(num1, &result_num);

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
  int result = s21_truncate(value, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

Suite *truncate_sc(void) {
  Suite *suite = suite_create("s21_truncate");

  TCase *t_tc = tcase_create("s21_truncate tests");
  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);
  tcase_add_test(t_tc, t5);
  tcase_add_test(t_tc, t6);
  tcase_add_test(t_tc, t7);
  tcase_add_test(t_tc, t8);

  tcase_add_test(t_tc, zero1);
  tcase_add_test(t_tc, zero2);
  tcase_add_test(t_tc, zero3);

  tcase_add_test(t_tc, null);
  tcase_add_test(t_tc, not_init);
  tcase_add_test(t_tc, not_correct_num);

  suite_add_tcase(suite, t_tc);

  return suite;
}

MAKE_TEST(truncate)
