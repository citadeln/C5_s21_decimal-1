#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(bits0) {
  // arrange
  s21_ldecimal num1 = {.bits = {10}, .exp = 0};
  s21_ldecimal num2 = {.bits = {7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1) {
  // arrange
  s21_ldecimal num1 = {.bits = {UINT32_MAX, 10}, .exp = 0};
  s21_ldecimal num2 = {.bits = {UINT32_MAX, 7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2) {
  // arrange
  s21_ldecimal num1 = {.bits = {UINT32_MAX, UINT32_MAX, 10}, .exp = 0};
  s21_ldecimal num2 = {.bits = {UINT32_MAX, UINT32_MAX, 7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits3) {
  // arrange
  s21_ldecimal num1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 10},
                       .exp = 0};
  s21_ldecimal num2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 7},
                       .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits4) {
  // arrange
  s21_ldecimal num1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 10}, .exp = 0};
  s21_ldecimal num2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits5) {
  // arrange
  s21_ldecimal num1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 10},
      .exp = 0};
  s21_ldecimal num2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 7},
      .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 0, 0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits6) {
  // arrange
  s21_ldecimal num1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, 10},
                       .exp = 0};
  s21_ldecimal num2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, 7},
                       .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 0, 0, 0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(less_sub_greater) {
  // arrange
  // 3 - 7 = -4
  s21_ldecimal num1 = {.bits = {3}, .exp = 0};
  s21_ldecimal num2 = {.bits = {7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {4}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(signs_plus_minus1) {
  // arrange
  s21_ldecimal num1 = {.bits = {7}, .sign = 0};
  s21_ldecimal num2 = {.bits = {4}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {11}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(signs_plus_minus2) {
  // arrange
  s21_ldecimal num1 = {.bits = {7}, .sign = 1};
  s21_ldecimal num2 = {.bits = {4}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {11}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(t1) {
  // arrange
  s21_ldecimal num1 = {.bits = {0, 1}, .sign = 0};
  s21_ldecimal num2 = {.bits = {1}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {UINT32_MAX}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // Проверка переноса переполнения на старший бит,
  // что он сам не переполнится

  // arrange
  s21_ldecimal num1 = {.bits = {0, UINT64_MAX, 1}, .sign = 0};
  s21_ldecimal num2 = {.bits = {1, UINT64_MAX}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {UINT32_MAX, UINT32_MAX},
                                    .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  // 10 - -5 = 15
  s21_ldecimal num1 = {.bits = {10}, .sign = 0};
  s21_ldecimal num2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {15}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  // 5 - -10 = 15
  s21_ldecimal num1 = {.bits = {5}, .sign = 0};
  s21_ldecimal num2 = {.bits = {10}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {15}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign3) {
  // arrange
  // -10 - 5 = -15
  s21_ldecimal num1 = {.bits = {10}, .sign = 1};
  s21_ldecimal num2 = {.bits = {5}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {15}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign4) {
  // arrange
  // -5 - 10 = -15
  s21_ldecimal num1 = {.bits = {5}, .sign = 1};
  s21_ldecimal num2 = {.bits = {10}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {15}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign5) {
  // arrange
  // -5 - -10 = 5
  s21_ldecimal num1 = {.bits = {5}, .sign = 1};
  s21_ldecimal num2 = {.bits = {10}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign6) {
  // arrange
  // -10 - -10 = 0
  s21_ldecimal num1 = {.bits = {10}, .sign = 1};
  s21_ldecimal num2 = {.bits = {10}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign7) {
  // arrange
  // -10 - -5 = 15
  s21_ldecimal num1 = {.bits = {10}, .sign = 1};
  s21_ldecimal num2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign8) {
  // arrange
  // -10 - 10 = -20
  s21_ldecimal num1 = {.bits = {10}, .sign = 1};
  s21_ldecimal num2 = {.bits = {10}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {20}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign9) {
  // arrange
  // 10 - -10 = 20
  s21_ldecimal num1 = {.bits = {10}, .sign = 0};
  s21_ldecimal num2 = {.bits = {10}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {20}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(overflow1) {
  // arrange
  // max - -max = overflow
  s21_ldecimal num1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX},
                       .sign = 0};
  s21_ldecimal num2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX},
                       .sign = 1};
  s21_ldecimal result_value = {0};

  int need_result = false;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow2) {
  // arrange
  // max - max = 0
  s21_ldecimal num1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX},
                       .sign = 0};
  s21_ldecimal num2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX},
                       .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow3) {
  // arrange
  // -max - max = -overflow
  s21_ldecimal num1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX},
                       .sign = 1};
  s21_ldecimal num2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX},
                       .sign = 0};
  s21_ldecimal result_value = {0};

  int need_result = false;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow4) {
  // arrange
  // -max - -max = 0
  s21_ldecimal num1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX},
                       .sign = 1};
  s21_ldecimal num2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX},
                       .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(num_is_zero1) {
  // arrange
  s21_ldecimal num1 = {.bits = {0}};
  s21_ldecimal num2 = {.bits = {1231234}};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {1231234}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(num_is_zero2) {
  // arrange
  s21_ldecimal num1 = {.bits = {1231234}};
  s21_ldecimal num2 = {.bits = {0}};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {1231234}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(null1) {
  // arrange
  s21_ldecimal num = {0};

  int need_result = false;

  // act
  int result = s21_ldec_sub(&num, &num, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null2) {
  // arrange
  s21_ldecimal num = {0};

  int need_result = false;

  // act
  int result = s21_ldec_sub(&num, NULL, &num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null3) {
  // arrange
  s21_ldecimal num = {0};

  int need_result = false;

  // act
  int result = s21_ldec_sub(NULL, &num, &num);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *sub_tc(void) {
  TCase *tc = tcase_create("s21_ldec_sub");

  tcase_add_test(tc, bits0);
  tcase_add_test(tc, bits1);
  tcase_add_test(tc, bits2);
  tcase_add_test(tc, bits3);
  tcase_add_test(tc, bits4);
  tcase_add_test(tc, bits5);
  tcase_add_test(tc, bits6);

  tcase_add_test(tc, less_sub_greater);

  tcase_add_test(tc, signs_plus_minus1);
  tcase_add_test(tc, signs_plus_minus2);

  tcase_add_test(tc, sign1);
  tcase_add_test(tc, sign2);
  tcase_add_test(tc, sign3);
  tcase_add_test(tc, sign4);
  tcase_add_test(tc, sign5);
  tcase_add_test(tc, sign6);
  tcase_add_test(tc, sign7);
  tcase_add_test(tc, sign8);
  tcase_add_test(tc, sign9);

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);

  tcase_add_test(tc, overflow1);
  tcase_add_test(tc, overflow2);
  tcase_add_test(tc, overflow3);
  tcase_add_test(tc, overflow4);

  tcase_add_test(tc, num_is_zero1);
  tcase_add_test(tc, num_is_zero2);

  tcase_add_test(tc, null1);
  tcase_add_test(tc, null2);
  tcase_add_test(tc, null3);

  return tc;
}
