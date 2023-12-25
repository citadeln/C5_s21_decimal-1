#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(exp_not_equal1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {1}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 2};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_not_equal2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {1}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 3};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_not_equal3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 2};
  s21_ldecimal value_2 = {.bits = {1}, .exp = 0};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_not_equal4) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 3};
  s21_ldecimal value_2 = {.bits = {1}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(exp_equal1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_equal2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {1}, .exp = 0};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_equal3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {1}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_equal4) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 28};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 28};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(exp_equal5) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 28};
  s21_ldecimal value_2 = {.bits = {12}, .exp = 28};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits1_1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, 123}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, 122}, .exp = 0};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1_2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, 122}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, 122}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1_3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, 121}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, 122}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits2_1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, 123}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, 122}, .exp = 0};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2_2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, 122}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, 122}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2_3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, 121}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, 122}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits3_1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 123},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 122},
                          .exp = 0};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits3_2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 122},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 122},
                          .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits3_3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 121},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 122},
                          .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits4_1) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 123}, .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 122}, .exp = 0};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits4_2) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 122}, .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 122}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits4_3) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 121}, .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 122}, .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits5_1) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 123},
      .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 122},
      .exp = 0};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits5_2) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 122},
      .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 122},
      .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits5_3) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 121},
      .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, 122},
      .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits6_1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX, 2},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX, 1},
                          .exp = 0};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits6_2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX, 2},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX, 2},
                          .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits6_3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX, 1},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                   UINT32_MAX, UINT32_MAX, UINT32_MAX, 2},
                          .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits6_4) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX},
      .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX - 1},
      .exp = 0};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits6_5) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX},
      .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX},
      .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits6_6) {
  // arrange
  s21_ldecimal value_1 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX - 1},
      .exp = 0};
  s21_ldecimal value_2 = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
               UINT32_MAX, UINT32_MAX},
      .exp = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(null1) {
  // arrange
  s21_ldecimal value_1 = {0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null2) {
  // arrange
  s21_ldecimal value_1 = {0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(NULL, &value_1);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null3) {
  // arrange
  int need_result = false;

  // act
  int result = s21_ldec_is_greater(NULL, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign_minus_plus1) {
  // -10 > 5 ? false
  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {5}, .sign = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_minus_plus2) {
  // -5 > 10 ? false
  // arrange
  s21_ldecimal value_1 = {.bits = {5}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_minus_plus3) {
  // -5 > 5 ? false

  // arrange
  s21_ldecimal value_1 = {.bits = {5}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {5}, .sign = 0};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_plus_minus1) {
  // 10 > -5 ? true

  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {5}, .sign = 1};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_plus_minus2) {
  // 5 > -10 ? true

  // arrange
  s21_ldecimal value_1 = {.bits = {5}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 1};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_plus_minus3) {
  // 5 > -5 ? true

  // arrange
  s21_ldecimal value_1 = {.bits = {5}, .sign = 0};
  s21_ldecimal value_2 = {.bits = {5}, .sign = 1};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign_minus_minus1) {
  // -5 > -10 ? true

  // arrange
  s21_ldecimal value_1 = {.bits = {5}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {10}, .sign = 1};

  int need_result = true;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_minus_minus2) {
  // -10 > -5 ? false

  // arrange
  s21_ldecimal value_1 = {.bits = {10}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {5}, .sign = 1};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign_minus_minus3) {
  // -5 > -5 ? false

  // arrange
  s21_ldecimal value_1 = {.bits = {5}, .sign = 1};
  s21_ldecimal value_2 = {.bits = {5}, .sign = 1};

  int need_result = false;

  // act
  int result = s21_ldec_is_greater(&value_1, &value_2);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *ldec_is_greater_tc(void) {
  TCase *tc = tcase_create("s21_ldec_is_greater");

  tcase_add_test(tc, exp_not_equal1);
  tcase_add_test(tc, exp_not_equal2);
  tcase_add_test(tc, exp_not_equal3);
  tcase_add_test(tc, exp_not_equal4);

  tcase_add_test(tc, exp_equal1);
  tcase_add_test(tc, exp_equal2);
  tcase_add_test(tc, exp_equal3);
  tcase_add_test(tc, exp_equal4);
  tcase_add_test(tc, exp_equal5);

  tcase_add_test(tc, bits1_1);
  tcase_add_test(tc, bits1_2);
  tcase_add_test(tc, bits1_3);

  tcase_add_test(tc, bits2_1);
  tcase_add_test(tc, bits2_2);
  tcase_add_test(tc, bits2_3);

  tcase_add_test(tc, bits3_1);
  tcase_add_test(tc, bits3_2);
  tcase_add_test(tc, bits3_3);

  tcase_add_test(tc, bits4_1);
  tcase_add_test(tc, bits4_2);
  tcase_add_test(tc, bits4_3);

  tcase_add_test(tc, bits5_1);
  tcase_add_test(tc, bits5_2);
  tcase_add_test(tc, bits5_3);

  tcase_add_test(tc, bits6_1);
  tcase_add_test(tc, bits6_2);
  tcase_add_test(tc, bits6_3);
  tcase_add_test(tc, bits6_4);
  tcase_add_test(tc, bits6_5);
  tcase_add_test(tc, bits6_6);

  tcase_add_test(tc, null1);
  tcase_add_test(tc, null2);
  tcase_add_test(tc, null3);

  tcase_add_test(tc, sign_minus_plus1);
  tcase_add_test(tc, sign_minus_plus2);
  tcase_add_test(tc, sign_minus_plus3);

  tcase_add_test(tc, sign_plus_minus1);
  tcase_add_test(tc, sign_plus_minus2);
  tcase_add_test(tc, sign_plus_minus3);

  tcase_add_test(tc, sign_minus_minus1);
  tcase_add_test(tc, sign_minus_minus2);
  tcase_add_test(tc, sign_minus_minus3);

  return tc;
}
