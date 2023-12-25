#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  s21_decimal value_1 = {.bits = {2}};
  s21_decimal value_2 = {.bits = {2}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {4}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  // 2000000 * 2000000 =>
  // 40000000000000
  s21_decimal value_1 = {.bits = {0x1E8480}};
  s21_decimal value_2 = {.bits = {0x1E8480}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0x52944000, 0x3A3}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  // 8589934591 * 8589934591 = 73786976277658337281
  s21_decimal value_1 = {.bits = {(int)0xFFFFFFFF, (int)0x1}};
  s21_decimal value_2 = {.bits = {(int)0xFFFFFFFF, (int)0x1}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x00000001, (int)0xFFFFFFFC, (int)0x3}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  // 18446744073709551615 * 4294967295 = 79228162495817593515539431425
  s21_decimal value_1 = {.bits = {(int)0xFFFFFFFF, (int)0xFFFFFFFF}};
  s21_decimal value_2 = {.bits = {(int)0xFFFFFFFF}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x00000001, (int)0xFFFFFFFF, (int)0xFFFFFFFE}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  // 79228.162514264337593543950335 *
  // 0.0000000000000000000000023456 =
  // 0.000000000000000000185837577993458430259416689905776
  s21_decimal value_1 = {.bits = {(int)0xFFFFFFFF, (int)0xFFFFFFFF,
                                  (int)0xFFFFFFFF, S21_MAKE_EXP(24, 0)}};
  s21_decimal value_2 = {.bits = {(int)23456, 0, 0, S21_MAKE_EXP(28, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {185837578, 0, 0, S21_MAKE_EXP(27, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(max_min) {
  // arrange
  // 79228162514264337593543950335 *
  // 00000000000000000000000000001
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(max_nums) {
  // arrange
  // 79228162514264337593543950335 * 79228162514264337593543950335 =
  // 62771017353866807638357894230 (.49210091073826769276946612225)
  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(15, 0)}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(14, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x096EE456, (int)0x359A3B3E, (int)0xCAD2F7F5}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(overflow1) {
  // arrange

  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1}};
  int need_result = 1;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow2) {
  // arrange

  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = 2;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow3) {
  // arrange

  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = 2;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow4) {
  // arrange

  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1}};
  int need_result = 1;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(exp_1) {
  // arrange
  s21_decimal value_1 = {.bits = {123456789, 0, 0, S21_MAKE_EXP(4, 0)}};
  s21_decimal value_2 = {.bits = {123456789, 0, 0, S21_MAKE_EXP(1, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x9738A3B9, (int)0x362622, 0, S21_MAKE_EXP(5, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_2) {
  // arrange
  // 79228162514264337593543950335 *
  // 0.00000000000000000000000000079228162514264337593543950335 =
  // 63.382530011411470074835160268
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(56, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0xCCCCCCCC, (int)0xCCCCCCCC,
                                            (int)0xCCCCCCCC,
                                            S21_MAKE_EXP(27, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_3) {
  // arrange
  // 79228162514264337593543950335
  // 0.000000000000000000000000000079228162514264337593543950335
  // 7.9228162514264337593543950335
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(57, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_4) {
  // arrange
  // 0.000000000000000000000000000079228162514264337593543950335
  // 79228162514264337593543950335
  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(57, 0)}};
  s21_decimal value_2 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_5) {
  // arrange
  // 7.9228162514264337593543950335
  // 7.9228162514264337593543950335
  // 62.77101735386680763835789423 (049210091073826769276946612225)
  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(28, 0)}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(28, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0x3424B06F, (int)0xEBC29F86,
                                            (int)0x14484BFE,
                                            S21_MAKE_EXP(26, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_6) {
  // arrange
  // 0.0000000000000079228162514264337593543950335
  // 0.00000000000079228162514264337593543950335
  // 0.0000000000000000000000000062 (77101735386680763835789423049210091)
  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(44, 0)}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(41, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {6, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_7) {
  // arrange
  // 0.0000000000000079228162514264337593543950335
  // 0.00000000000079228162514264337593543950335
  // 0.0000000000000000000000000062 (77101735386680763835789423049210091)
  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 0)}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(255, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_8) {
  // arrange
  // 0.000000000000000079228162514264337593543950335
  // 0.00000000000079228162514264337593543950335
  // 0.0000000000000000000000000000627710173538668076383578942304921009
  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(45, 0)}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(41, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_9) {
  // arrange
  // 0.0000000000000000079228162514264337593543950335
  // 0.00000000000079228162514264337593543950335
  // 0.0000000000000000000000000000627710173538668076383578942304921009
  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(46, 0)}};
  s21_decimal value_2 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(41, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  // 5 * -5 = -25
  s21_decimal num1 = {.bits = {5}};
  s21_decimal num2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {25, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  // -5 * 5 = -25
  s21_decimal num1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {5}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {25, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign3) {
  // arrange
  // 5 * 5 = 25
  s21_decimal num1 = {.bits = {5}};
  s21_decimal num2 = {.bits = {5}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {25}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign4) {
  // arrange
  // -5 * -5 = 25
  s21_decimal num1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {25}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(zero1) {
  // arrange
  // 5 * -0
  s21_decimal num1 = {.bits = {5}};
  s21_decimal num2 = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero2) {
  // arrange
  // -5 * 0 = 0
  s21_decimal num1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {0}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero3) {
  // arrange
  // 5 * 0 = 0
  s21_decimal num1 = {.bits = {5}};
  s21_decimal num2 = {.bits = {0}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero4) {
  // arrange
  // -5 * -0 = 0
  s21_decimal num1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero5) {
  // arrange
  // 0 * -5
  s21_decimal num1 = {.bits = {0}};
  s21_decimal num2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero6) {
  // arrange
  // -0 * 5 = 0
  s21_decimal num1 = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {5}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero7) {
  // arrange
  // 0 * 5 = 0
  s21_decimal num1 = {.bits = {0}};
  s21_decimal num2 = {.bits = {5}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero8) {
  // arrange
  // -0 * -5 = 0
  s21_decimal num1 = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal num2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(num1, num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(result_not_init1) {
  // arrange
  // 345782344363465 * 2345234543 = 810940698360719465171495
  s21_decimal value_1 = {.bits = {(int)0xB9CE2DC9, (int)0x13A7C}};
  s21_decimal value_2 = {.bits = {(int)0x8BC9706F}};
  s21_decimal result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_value = {
      .bits = {(int)0xDA3ECA27, (int)0x2EEFC31C, (int)0xABB9}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(result_not_init2) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  s21_decimal value_2 = {.bits = {1}};
  s21_decimal result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_value = {.bits = {1}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

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
  int result = s21_mul(value, value, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(not_correct_num1) {
  // arrange
  s21_decimal value_1 = {.bits = {2}};
  value_1.bits[3] = 1;
  s21_decimal value_2 = {.bits = {2}};
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(not_correct_num2) {
  // arrange
  s21_decimal value_1 = {.bits = {2}};
  s21_decimal value_2 = {.bits = {2}};
  value_2.bits[3] = 1;
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_mul(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

Suite *mul_sc(void) {
  Suite *suite = suite_create("s21_mul");

  TCase *t_tc = tcase_create("s21_mul");
  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);
  tcase_add_test(t_tc, t5);
  tcase_add_test(t_tc, null);
  tcase_add_test(t_tc, not_correct_num1);
  tcase_add_test(t_tc, not_correct_num2);
  suite_add_tcase(suite, t_tc);

  TCase *max_min_tc = tcase_create("s21_mul max_min");
  tcase_add_test(max_min_tc, max_min);
  tcase_add_test(max_min_tc, max_nums);
  suite_add_tcase(suite, max_min_tc);

  TCase *overflow_tc = tcase_create("s21_mul overflow");
  tcase_add_test(overflow_tc, overflow1);
  tcase_add_test(overflow_tc, overflow2);
  tcase_add_test(overflow_tc, overflow3);
  tcase_add_test(overflow_tc, overflow4);
  suite_add_tcase(suite, overflow_tc);

  TCase *exp_tc = tcase_create("s21_mul exp");
  tcase_add_test(exp_tc, exp_1);
  tcase_add_test(exp_tc, exp_2);
  tcase_add_test(exp_tc, exp_3);
  tcase_add_test(exp_tc, exp_4);
  tcase_add_test(exp_tc, exp_5);
  tcase_add_test(exp_tc, exp_6);
  tcase_add_test(exp_tc, exp_7);
  tcase_add_test(exp_tc, exp_8);
  tcase_add_test(exp_tc, exp_9);
  suite_add_tcase(suite, exp_tc);

  TCase *signs_tc = tcase_create("s21_mul signs");
  tcase_add_test(signs_tc, sign1);
  tcase_add_test(signs_tc, sign2);
  tcase_add_test(signs_tc, sign3);
  tcase_add_test(signs_tc, sign4);
  suite_add_tcase(suite, signs_tc);

  TCase *zero_tc = tcase_create("s21_mul zero");
  tcase_add_test(zero_tc, zero1);
  tcase_add_test(zero_tc, zero2);
  tcase_add_test(zero_tc, zero3);
  tcase_add_test(zero_tc, zero4);
  tcase_add_test(zero_tc, zero5);
  tcase_add_test(zero_tc, zero6);
  tcase_add_test(zero_tc, zero7);
  tcase_add_test(zero_tc, zero8);
  suite_add_tcase(suite, zero_tc);

  TCase *not_init_tc = tcase_create("s21_mul result not init");
  tcase_add_test(not_init_tc, result_not_init1);
  tcase_add_test(not_init_tc, result_not_init2);
  suite_add_tcase(suite, not_init_tc);

  return suite;
}

MAKE_TEST(mul)
