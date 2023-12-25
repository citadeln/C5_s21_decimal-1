#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(t1) {
  // arrange
  // 3248762136528478278123 / 1234234354 =
  // 2632208482934.90158200782021013166515700469637065
  s21_ldecimal value_1 = {.bits = {0x3F0C11EB, 0x1DA1AE7E, 0xB0}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {0x4990EBF2}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0x09389FC9, 0x802F47FF, 0x5D085B91, 0x7818412B, 0x2E1B3B26},
      .exp = 35};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  // 0.33333333333333333333333333333333333
  s21_ldecimal value_1 = {.bits = {1}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {3}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0x55555555, 0x0e82854d, 0xd0ed19d6, 0x66b75}, .exp = 35};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {4}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {125}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {32}, .exp = 3};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  s21_ldecimal value_1 = {.bits = {125}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {80}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {15625}, .exp = 4};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  // 79228162514264337593543950335
  // 79228162514264337593543950335
  s21_ldecimal value_1 = {.bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF},
                          .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {1}, .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  // 79228162514264337593543950335
  // 0.0000000000000000000000000001
  // 792281625142643375935439503350000000000000000000000000000
  s21_ldecimal value_1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {1}, .exp = 28};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0xF0000000, 0xC1DAFD9E, 0xDFB031A1, 0x0FFFFFFF, 0x3E250261,
               0x204FCE5E},
      .exp = 0};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  // 792281625142643375935439503350000000000000000000000000000 / 2 =
  // 396140812571321687967719751675
  s21_ldecimal value_1 = {.bits = {0xF0000000, 0xC1DAFD9E, 0xDFB031A1,
                                   0x0FFFFFFF, 0x3E250261, 0x204FCE5E},
                          .exp = 28};
  s21_ldecimal value_2 = {.bits = {2}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x4}, .exp = 1};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t8) {
  // arrange
  // 792281625142643375935439503350000000000000000000000000000
  // 123456789123 =>
  // 6417481215660753872427111133122580489485455512.64328583780739544383
  // 6417481215660753872427111133122580489485455512 64328583780 (73954438397904)
  s21_ldecimal value_1 = {.bits = {0xF0000000, 0xC1DAFD9E, 0xDFB031A1,
                                   0x0FFFFFFF, 0x3E250261, 0x204FCE5E},
                          .exp = 0};
  s21_ldecimal value_2 = {.bits = {0xBE991A83, 0x1C}, .exp = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0x16BD010A, 0x1228F830, 0xF27900E6,
                                             0x40426F87, 0x576C686A, 0x29E042C},
                                    .exp = 10};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t9) {
  // arrange
  // 0.0000000001 /
  // 0.00003 =
  // 0.0000033333333333
  s21_ldecimal value_1 = {.bits = {1}, .exp = 10};
  s21_ldecimal value_2 = {.bits = {3}, .exp = 5};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0x15555555, 0x177C4F4E, 0x350EDEF0, 0x4}, .exp = 35};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t10) {
  // arrange
  s21_ldecimal value_1 = {.bits = {5}};
  s21_ldecimal value_2 = {.bits = {2}};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {25}, .exp = 1};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t11) {
  // arrange
  s21_ldecimal value_1 = {.bits = {10}};
  s21_ldecimal value_2 = {.bits = {32}};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {0xC35}, .exp = 4};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t12) {
  // arrange
  // 79228162514264337593543950335 /
  // 0.822816251426433759354395033 =
  // 85854754282662683588068124651.3657157490221204538757824141057
  s21_ldecimal num1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX}};
  s21_ldecimal num2 = {.bits = {0x8FFFFFFF, 0x4CFCEF58, 0x1DD15B6C}, .exp = 28};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {
      .bits = {0xA9E53E8D, 0x55FD8DAD, 0xC5C9FEBA, 0x7FD005B3, 0x0C19837E,
               0x2303A793},
      .exp = 28};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t13) {
  // arrange
  s21_ldecimal num1 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX}};
  s21_ldecimal num2 = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX}};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {1}};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t14) {
  // arrange
  s21_ldecimal num1 = {.bits = {0xFFFFFFFE, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                UINT32_MAX, UINT32_MAX, UINT32_MAX}};
  s21_ldecimal num2 = {.bits = {2}};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                             UINT32_MAX, UINT32_MAX, UINT32_MAX,
                                             0x7FFFFFFF}};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(zero1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {0}};
  s21_ldecimal value_2 = {.bits = {32}};
  s21_ldecimal result_value;

  s21_ldecimal need_result_value = {0};
  int need_result = true;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {32}};
  s21_ldecimal value_2 = {.bits = {0}};
  s21_ldecimal result_value;

  s21_ldecimal need_result_value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(zero3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {0}};
  s21_ldecimal value_2 = {.bits = {0}};
  s21_ldecimal result_value;

  s21_ldecimal need_result_value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_div(&value_1, &value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  // 25 / -5 = -5
  s21_ldecimal num1 = {.bits = {25}, .sign = 0};
  s21_ldecimal num2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  // -25 / 5 = -5
  s21_ldecimal num1 = {.bits = {25}, .sign = 1};
  s21_ldecimal num2 = {.bits = {5}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 1};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign3) {
  // arrange
  // 25 / 5 = 5
  s21_ldecimal num1 = {.bits = {25}, .sign = 0};
  s21_ldecimal num2 = {.bits = {5}, .sign = 0};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign4) {
  // arrange
  // -25 / -5 = 5
  s21_ldecimal num1 = {.bits = {25}, .sign = 1};
  s21_ldecimal num2 = {.bits = {5}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign5) {
  // arrange
  // -5 / 100 = 5
  s21_ldecimal num1 = {.bits = {5}, .sign = 1};
  s21_ldecimal num2 = {.bits = {100}, .sign = 1};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {5}, .exp = 2, .sign = 0};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(div_by_one1) {
  // arrange
  s21_ldecimal num1 = {.bits = {123}};
  s21_ldecimal num2 = {.bits = {1}};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {123}};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(div_by_one2) {
  // arrange
  s21_ldecimal num1 = {.bits = {1}};
  s21_ldecimal num2 = {.bits = {100}};
  s21_ldecimal result_value = {0};

  s21_ldecimal need_result_value = {.bits = {1}, .exp = 2};
  int need_result = true;

  // act
  int result = s21_ldec_div(&num1, &num2, &result_value);

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
  int result = s21_ldec_div(&value, &value, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null2) {
  // arrange
  s21_ldecimal value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_div(&value, NULL, &value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(null3) {
  // arrange
  s21_ldecimal value = {0};
  int need_result = false;

  // act
  int result = s21_ldec_div(NULL, &value, &value);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *div_tc(void) {
  TCase *tc = tcase_create("s21_ldec_div");

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);
  tcase_add_test(tc, t3);
  tcase_add_test(tc, t4);
  tcase_add_test(tc, t5);
  tcase_add_test(tc, t6);
  tcase_add_test(tc, t7);
  tcase_add_test(tc, t8);
  tcase_add_test(tc, t9);
  tcase_add_test(tc, t10);
  tcase_add_test(tc, t11);
  tcase_add_test(tc, t12);
  tcase_add_test(tc, t13);
  tcase_add_test(tc, t14);

  tcase_add_test(tc, zero1);
  tcase_add_test(tc, zero2);
  tcase_add_test(tc, zero3);

  tcase_add_test(tc, sign1);
  tcase_add_test(tc, sign2);
  tcase_add_test(tc, sign3);
  tcase_add_test(tc, sign4);
  tcase_add_test(tc, sign5);

  tcase_add_test(tc, div_by_one1);
  tcase_add_test(tc, div_by_one2);

  tcase_add_test(tc, null1);
  tcase_add_test(tc, null2);
  tcase_add_test(tc, null3);

  return tc;
}
