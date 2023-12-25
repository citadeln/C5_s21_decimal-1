#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  // 3248762136528478278123 / 1234234354 =
  // 2632208482934.9015820078202101
  s21_decimal value_1 = {.bits = {(int)0x3F0C11EB, (int)0x1DA1AE7E, (int)0xB0}};
  s21_decimal value_2 = {.bits = {(int)0x4990EBF2}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0x3614BCF5, (int)0xD0FF65D0,
                                            (int)0x550D1E45,
                                            S21_MAKE_EXP(16, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  // 0.3333333333333333333333333333
  s21_decimal value_1 = {.bits = {1}};
  s21_decimal value_2 = {.bits = {3}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0x05555555, (int)0x14B700CB,
                                            (int)0xAC544CA,
                                            S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  // 0.032
  s21_decimal value_1 = {.bits = {4}};
  s21_decimal value_2 = {.bits = {125}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {32, 0, 0, S21_MAKE_EXP(3, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  // 1.5625
  s21_decimal value_1 = {.bits = {125}};
  s21_decimal value_2 = {.bits = {80}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {15625, 0, 0, S21_MAKE_EXP(4, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  // 79228162514264337593543950335
  // 79228162514264337593543950335
  s21_decimal value_1 = {
      .bits = {(int)0xFFFFFFFF, (int)0xFFFFFFFF, (int)0xFFFFFFFF}};
  s21_decimal value_2 = {
      .bits = {(int)0xFFFFFFFF, (int)0xFFFFFFFF, (int)0xFFFFFFFF}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  // 79228162514264337593543950335
  // 1.0000000000000000000000000001
  // 79228162514264337593543950327
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {(int)0x10000001, (int)0x3E250261,
                                  (int)0x204FCE5E, S21_MAKE_EXP(28, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0xFFFFFFF7, (int)0xFFFFFFFF, (int)0xFFFFFFFF}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  // 2 /
  // 0.00000000000000000000000000025 =
  // 10000000000000000000000000000
  s21_decimal value_1 = {.bits = {2}};
  s21_decimal value_2 = {.bits = {25, 0, 0, S21_MAKE_EXP(29, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x10000000, (int)0x3E250261, (int)0x204FCE5E}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t8) {
  // arrange
  // 2 /
  // 0.0000000000000000000000000002500000000000001 =
  // 6666666666666666666666666666.7
  s21_decimal value_1 = {.bits = {2}};
  s21_decimal value_2 = {
      .bits = {(int)0x9BF04001, (int)0x8E1BC, 0, S21_MAKE_EXP(43, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0x6AAAAAAB, (int)0x9E4C0FDC,
                                            (int)0xD7695FC9,
                                            S21_MAKE_EXP(1, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t9) {
  // arrange
  // 0.0000000001 /
  // 0.00003 =
  // 0.0000033333333333333333333333
  s21_decimal value_1 = {.bits = {1, 0, 0, S21_MAKE_EXP(10, 0)}};
  s21_decimal value_2 = {.bits = {3, 0, 0, S21_MAKE_EXP(5, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0xFCD55555, (int)0x00ED4B18,
                                            (int)0x70F, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t10) {
  // arrange
  s21_decimal value_1 = {.bits = {5}};
  s21_decimal value_2 = {.bits = {2}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {25, 0, 0, S21_MAKE_EXP(1, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t11) {
  // arrange
  s21_decimal value_1 = {.bits = {10}};
  s21_decimal value_2 = {.bits = {32}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {3125, 0, 0, S21_MAKE_EXP(4, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t12) {
  // arrange
  // 7922816251426433759354395033 /
  // 0.822816251426433759354395033 =
  // 9628901030687525026030270619
  s21_decimal value_1 = {
      .bits = {(int)0x99999999, (int)0x99999999, (int)0x19999999}};
  s21_decimal value_2 = {.bits = {(int)0x5D999999, (int)0x5E1E0B1C,
                                  (int)0x2A89E1E, S21_MAKE_EXP(27, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x9991B89B, (int)0xCE53CFE7, (int)0x1F1CD71A}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t13) {
  // arrange
  // 79228162514264337593543950335 /
  // 33333 =
  // 2376868644114371271519033.7004
  s21_decimal value_1 = {
      .bits = {(int)0xFFFFFFFF, (int)0xFFFFFFFF, (int)0xFFFFFFFF}};
  s21_decimal value_2 = {.bits = {33333}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0xBEA47DEC, (int)0xD4AB4405,
                                            (int)0x4CCCFF21,
                                            S21_MAKE_EXP(4, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t14) {
  // arrange
  // 2 /
  // 0.00000000000000000000000000015 =
  // 10000000000000000000000000000
  s21_decimal value_1 = {.bits = {2}};
  s21_decimal value_2 = {.bits = {15, 0, 0, S21_MAKE_EXP(29, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x10000000, (int)0x3E250261, (int)0x204FCE5E}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(zero1) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  s21_decimal value_2 = {.bits = {32}};
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero2) {
  // arrange
  s21_decimal value_1 = {.bits = {32}};
  s21_decimal value_2 = {.bits = {0}};
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_DIV_ZERO_ERROR;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero3) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  s21_decimal value_2 = {.bits = {0}};
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_DIV_ZERO_ERROR;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  // 25 / -5 = -5
  s21_decimal value_1 = {.bits = {25}};
  s21_decimal value_2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  // -25 / 5 = -5
  s21_decimal value_1 = {.bits = {25, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {5}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign3) {
  // arrange
  // 25 / 5 = 5
  s21_decimal value_1 = {.bits = {25}};
  s21_decimal value_2 = {.bits = {5}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign4) {
  // arrange
  // -25 / -5 = 5
  s21_decimal value_1 = {.bits = {25, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign5) {
  // arrange
  // -5 / 100 = 5
  s21_decimal value_1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {100, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5, 0, 0, S21_MAKE_EXP(2, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(div_by_one1) {
  // arrange
  s21_decimal value_1 = {.bits = {123}};
  s21_decimal value_2 = {.bits = {1}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {123}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(div_by_one2) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  s21_decimal value_2 = {.bits = {100}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1, 0, 0, S21_MAKE_EXP(2, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(not_init) {
  // arrange
  // 0.032
  s21_decimal value_1 = {.bits = {4}};
  s21_decimal value_2 = {.bits = {125}};
  s21_decimal result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_value = {.bits = {32, 0, 0, S21_MAKE_EXP(3, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(null) {
  // arrange
  s21_decimal value = {0};

  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_div(value, value, NULL);

  // assert
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
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(not_correct_num2) {
  // arrange
  s21_decimal value_1 = {.bits = {2}};
  s21_decimal value_2 = {.bits = {1}};
  value_2.bits[3] = 1;
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_div(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

Suite *div_sc(void) {
  Suite *suite = suite_create("s21_div");

  TCase *t_tc = tcase_create("s21_div");

  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);
  tcase_add_test(t_tc, t5);
  tcase_add_test(t_tc, t6);
  tcase_add_test(t_tc, t7);
  tcase_add_test(t_tc, t8);
  tcase_add_test(t_tc, t9);
  tcase_add_test(t_tc, t10);
  tcase_add_test(t_tc, t11);
  tcase_add_test(t_tc, t12);
  tcase_add_test(t_tc, t13);
  tcase_add_test(t_tc, t14);

  tcase_add_test(t_tc, zero1);
  tcase_add_test(t_tc, zero2);
  tcase_add_test(t_tc, zero3);

  tcase_add_test(t_tc, sign1);
  tcase_add_test(t_tc, sign2);
  tcase_add_test(t_tc, sign3);
  tcase_add_test(t_tc, sign4);
  tcase_add_test(t_tc, sign5);

  tcase_add_test(t_tc, div_by_one1);
  tcase_add_test(t_tc, div_by_one2);

  tcase_add_test(t_tc, not_init);
  tcase_add_test(t_tc, null);
  tcase_add_test(t_tc, not_correct_num1);
  tcase_add_test(t_tc, not_correct_num2);

  suite_add_tcase(suite, t_tc);

  return suite;
}

MAKE_TEST(div)
