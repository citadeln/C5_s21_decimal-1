#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(bits0) {
  // arrange
  s21_ldecimal value_1 = {.bits = {1}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {10}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {11}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {4294967294UL, 1UL}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0xFFFFFFFE, UINT32_MAX, 0x1},
                                    .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0xFFFFFFFE, UINT32_MAX, UINT32_MAX, 0x1}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits4) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX}, .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0xFFFFFFFE, UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x1}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits5) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX},
      .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX},
      .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0xFFFFFFFE, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x1},
      .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits6) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0xFFFFFFFE, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, 0x1},
      .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits7_overflow) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX},
      .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX},
      .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0xFFFFFFFE, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX},
      .exp = 0};
  int need_result = false;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(t1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 3};
  s21_ldecimal value_2 = {.bits = {321}, .exp = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {32223}, .exp = 3};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {550}, .exp = 3};
  s21_ldecimal value_2 = {.bits = {1255}, .exp = 2};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {131}, .exp = 1};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {0xF0000001, 0xC1DAFD9E, 0xDFB031A1,
                                             0xFFFFFFF, 0x3E250261, 0x204FCE5E},
                                    .exp = 28};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(max_remainder_full) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 28};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0xEFFFFFFF, 0xC1DAFD9E, 0xDFB031A1, 0x10000000, 0x3E250261,
               0x204FCE5E},
      .exp = 28};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {5}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {5}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign4) {
  // arrange
  s21_ldecimal value_1 = {.bits = {5}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign5) {
  // arrange
  s21_ldecimal value_1 = {.bits = {5}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {15}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign6) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {20}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign7) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {15}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign8) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign9) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(add_with_zero1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {0}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {10}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(add_with_zero2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {0}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {10}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(add_with_zero3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {0}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {10}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(add_with_zero4) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {0}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {10}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(overflow1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .exp = 100};
  s21_ldecimal value_2 = {.bits = {12}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .exp = 1};
  s21_ldecimal value_2 = {.bits = {12}, .exp = 100};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(big_exp_not_overflow) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .exp = 100};
  s21_ldecimal value_2 = {.bits = {12}, .exp = 100};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {22}, .exp = 100};
  int need_result = true;

  // act
  int result = s21_ldec_add(&value_1, &value_2, &result_value);

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
  int result = s21_ldec_add(&value, &value, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null2) {
  // arrange
  s21_ldecimal value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_add(&value, NULL, &value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null3) {
  // arrange
  s21_ldecimal value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_add(NULL, &value, &value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *add_tc(void) {
  TCase *tc = tcase_create("s21_ldec_add");

  tcase_add_test(tc, bits0);
  tcase_add_test(tc, bits1);
  tcase_add_test(tc, bits2);
  tcase_add_test(tc, bits3);
  tcase_add_test(tc, bits4);
  tcase_add_test(tc, bits5);
  tcase_add_test(tc, bits6);
  tcase_add_test(tc, bits7_overflow);

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);

  tcase_add_test(tc, max_min);
  tcase_add_test(tc, max_remainder_full);

  tcase_add_test(tc, sign1);
  tcase_add_test(tc, sign2);
  tcase_add_test(tc, sign3);
  tcase_add_test(tc, sign4);
  tcase_add_test(tc, sign5);
  tcase_add_test(tc, sign6);
  tcase_add_test(tc, sign7);
  tcase_add_test(tc, sign8);
  tcase_add_test(tc, sign9);

  tcase_add_test(tc, add_with_zero1);
  tcase_add_test(tc, add_with_zero2);
  tcase_add_test(tc, add_with_zero3);
  tcase_add_test(tc, add_with_zero4);

  tcase_add_test(tc, overflow1);
  tcase_add_test(tc, overflow2);

  tcase_add_test(tc, big_exp_not_overflow);

  tcase_add_test(tc, null1);
  tcase_add_test(tc, null2);
  tcase_add_test(tc, null3);

  return tc;
}
