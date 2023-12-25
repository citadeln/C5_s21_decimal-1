#include <check.h>

#include "./../../../lib/ldecimal/private/s21_ldec_private.h"

START_TEST(bits0) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, 10}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, 7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, 10}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, 7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 10},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 7},
                          .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits4) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 10}, .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits5) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 10},
      .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 7},
      .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 0, 0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits6) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX, 10},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX, 7},
                          .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0, 0, 0, 0, 0, 0, 3}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(less_sub_greater) {
  // arrange
  s21_ldecimal value_1 = {.bits = {3}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {7}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0xFFFFFFFC, UINT32_MAX, UINT32_MAX,
                                             UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                             UINT32_MAX}};
  int need_result = false;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(signs_plus_minus1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {7}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {4}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {3}};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(signs_plus_minus2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {7}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {4}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {3}};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(t1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {0, 1}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {1}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {UINT32_MAX}};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // Проверка переноса переполнения на старший бит,
  // что он сам не переполнится

  // arrange
  s21_ldecimal value_1 = {.bits = {0, UINT64_MAX, 1}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {1, UINT64_MAX}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {UINT32_MAX, UINT32_MAX},
                                    .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_sub_raw(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *sub_raw_tc(void) {
  TCase *tc = tcase_create("s21_ldec_sub_raw");

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

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);

  return tc;
}
