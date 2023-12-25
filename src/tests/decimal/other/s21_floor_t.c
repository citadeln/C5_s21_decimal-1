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
  int result = s21_floor(num1, &result_num);

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

  s21_decimal need_result_num = {.bits = {1}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_floor(num1, &result_num);

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
  int result = s21_floor(num1, &result_num);

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
  int result = s21_floor(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  s21_decimal num1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  num1.bits[3] = S21_MAKE_EXP(1, 0);
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)0x99999999, (int)0x99999999, (int)0x19999999}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_floor(num1, &result_num);

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
  int result = s21_floor(num1, &result_num);

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
  int result = s21_floor(num1, &result_num);

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
  int result = s21_floor(num1, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t9) {
  // arrange
  // -0.000000000000000000123456789
  s21_decimal num1 = {.bits = {12345678}};
  num1.bits[3] = S21_MAKE_EXP(27, S21_SIGN_MINUS);

  s21_decimal result_num = {0};
  s21_decimal need_result_num = {.bits = {1}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, S21_SIGN_MINUS);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_floor(num1, &result_num);

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
  int result = s21_floor(num1, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(not_init) {
  // arrange
  s21_decimal num1 = {.bits = {129}};
  num1.bits[3] = S21_MAKE_EXP(1, 1);
  s21_decimal result_num = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_num = {.bits = {13}};
  need_result_num.bits[3] = S21_MAKE_EXP(0, 1);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_floor(num1, &result_num);

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
  int result = s21_floor(value, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

Suite *floor_sc(void) {
  Suite *suite = suite_create("s21_floor");

  TCase *t_tc = tcase_create("s21_floor tests");
  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);
  tcase_add_test(t_tc, t5);
  tcase_add_test(t_tc, t6);
  tcase_add_test(t_tc, t7);
  tcase_add_test(t_tc, t8);
  tcase_add_test(t_tc, t9);

  tcase_add_test(t_tc, null);
  tcase_add_test(t_tc, not_init);
  tcase_add_test(t_tc, not_correct_num);

  suite_add_tcase(suite, t_tc);

  return suite;
}

MAKE_TEST(floor)
