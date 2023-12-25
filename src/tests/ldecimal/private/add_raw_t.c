#include <check.h>

#include "./../../../lib/ldecimal/private/s21_ldec_private.h"

START_TEST(bits0) {
  // arrange
  s21_ldecimal value_1 = {.bits = {1}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {10}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {11}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {444}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {1805}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {0, 0, 0, 1}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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
      .bits = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {15}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {15}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {15}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {15}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {15}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {20}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {15}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {20}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

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

  s21_ldecimal need_result_value = {.bits = {20}};
  int need_result = true;

  // act
  int result = s21_ldec_add_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *add_raw_tc(void) {
  TCase *tc = tcase_create("s21_ldec_add_raw");

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

  return tc;
}
