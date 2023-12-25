#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(t1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {2}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {2}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {4}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  // 2000000 * 2000000 =>
  // 40000000000000
  s21_ldecimal value_1 = {.bits = {0x1E8480}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {0x1E8480}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0x52944000, 0x3A3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {0xFFFFFFFF, 0x1}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {0xFFFFFFFF, 0x1}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0x00000001, 0xFFFFFFFC, 0x3},
                                    .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  s21_ldecimal value_1 = {.bits = {0xFFFFFFFF, 0xFFFFFFFF}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {0xFFFFFFFF, 0xFFFFFFFF}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0x00000001, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  // 732698.734268923234324342452343
  // 0.0000000000000000000000023456
  s21_ldecimal value_1 = {.bits = {0xE0513077, 0x9658EC31, 0x3F7A3015, 0x9},
                          .exp = 24};
  s21_ldecimal value_2 = {.bits = {0x5BA0}, .exp = 28};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0x0EF89760, 0x938959E9, 0x1B75B9EF, 0x34F58}, .exp = 52};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(max_min) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {1}, .exp = 28};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX}, .exp = 28};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(decimal_max_nums) {
  // arrange
  // 79228162514264337593543950335
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX}};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX}};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0x00000001, 0x00000000, 0x00000000,
                                             0xFFFFFFFE, 0xFFFFFFFF,
                                             0xFFFFFFFF}};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(overflow1) {
  // arrange
  // 6277101735386680763835789423049210091073826769276946612225 *
  // 6277101735386680763835789423049210091073826769276946612225
  s21_ldecimal value_1 = {
      .bits = {0x00000001, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF}, .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {0x00000001, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX},
      .exp = 0};
  int need_result = false;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(exp_1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123456789}, .exp = 4};
  s21_ldecimal value_2 = {.bits = {123456789}, .exp = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0x9738A3B9, 0x362622}, .exp = 5};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_2) {
  // arrange
  // 79228162514264337593543950335
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX}};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 56};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0x00000001, 0x00000000, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF,
               0xFFFFFFFF},
      .exp = 56};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_3) {
  // arrange
  // 79228162514264337593543950335
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 56};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 56};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0x00000001, 0x00000000, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF,
               0xFFFFFFFF},
      .exp = 112};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  // 5 * -5 = -25
  s21_ldecimal num1 = {.bits = {5}, .sign = 0};
  s21_ldecimal num2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {25}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  // -5 * 5 = -25
  s21_ldecimal num1 = {.bits = {5}, .sign = 1};
  s21_ldecimal num2 = {.bits = {5}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {25}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign3) {
  // arrange
  // 5 * 5 = 25
  s21_ldecimal num1 = {.bits = {5}, .sign = 0};
  s21_ldecimal num2 = {.bits = {5}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {25}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign4) {
  // arrange
  // -5 * -5 = 25
  s21_ldecimal num1 = {.bits = {5}, .sign = 1};
  s21_ldecimal num2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {25}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(zero1) {
  // arrange
  // 5 * -0
  s21_ldecimal num1 = {.bits = {5}, .sign = 0};
  s21_ldecimal num2 = {.bits = {0}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero2) {
  // arrange
  // -5 * 0 = 0
  s21_ldecimal num1 = {.bits = {5}, .sign = 1};
  s21_ldecimal num2 = {.bits = {0}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero3) {
  // arrange
  // 5 * 0 = 0
  s21_ldecimal num1 = {.bits = {5}, .sign = 0};
  s21_ldecimal num2 = {.bits = {0}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero4) {
  // arrange
  // -5 * -0 = 0
  s21_ldecimal num1 = {.bits = {5}, .sign = 1};
  s21_ldecimal num2 = {.bits = {0}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero5) {
  // arrange
  // 0 * -5
  s21_ldecimal num1 = {.bits = {0}, .sign = 0};
  s21_ldecimal num2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero6) {
  // arrange
  // -0 * 5 = 0
  s21_ldecimal num1 = {.bits = {0}, .sign = 1};
  s21_ldecimal num2 = {.bits = {5}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero7) {
  // arrange
  // 0 * 5 = 0
  s21_ldecimal num1 = {.bits = {0}, .sign = 0};
  s21_ldecimal num2 = {.bits = {5}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero8) {
  // arrange
  // -0 * -5 = 0
  s21_ldecimal num1 = {.bits = {0}, .sign = 1};
  s21_ldecimal num2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_mul(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(null1) {
  // arrange
  s21_ldecimal value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_mul(&value, &value, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null2) {
  // arrange
  s21_ldecimal value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_mul(&value, NULL, &value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null3) {
  // arrange
  s21_ldecimal value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_mul(NULL, &value, &value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *mul_tc(void) {
  TCase *tc = tcase_create("s21_ldec_mul");

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);
  tcase_add_test(tc, t3);
  tcase_add_test(tc, t4);
  tcase_add_test(tc, t5);

  tcase_add_test(tc, max_min);
  tcase_add_test(tc, decimal_max_nums);

  tcase_add_test(tc, overflow1);

  tcase_add_test(tc, exp_1);
  tcase_add_test(tc, exp_2);
  tcase_add_test(tc, exp_3);

  tcase_add_test(tc, sign1);
  tcase_add_test(tc, sign2);
  tcase_add_test(tc, sign3);
  tcase_add_test(tc, sign4);

  tcase_add_test(tc, zero1);
  tcase_add_test(tc, zero2);
  tcase_add_test(tc, zero3);
  tcase_add_test(tc, zero4);
  tcase_add_test(tc, zero5);
  tcase_add_test(tc, zero6);
  tcase_add_test(tc, zero7);
  tcase_add_test(tc, zero8);

  tcase_add_test(tc, null1);
  tcase_add_test(tc, null2);
  tcase_add_test(tc, null3);

  return tc;
}
