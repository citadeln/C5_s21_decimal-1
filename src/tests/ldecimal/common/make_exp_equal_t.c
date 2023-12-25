#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(t1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {1}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 2};

  s21_ldecimal need_result_value_1 = {.bits = {100}, .exp = 2};
  s21_ldecimal need_result_value_2 = {.bits = {123}, .exp = 2};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 5};

  s21_ldecimal need_result_value_1 = {.bits = {12300000}, .exp = 5};
  s21_ldecimal need_result_value_2 = {.bits = {123}, .exp = 5};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 5};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 0};

  s21_ldecimal need_result_value_1 = {.bits = {123}, .exp = 5};
  s21_ldecimal need_result_value_2 = {.bits = {12300000}, .exp = 5};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 5};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 4};

  s21_ldecimal need_result_value_1 = {.bits = {123}, .exp = 5};
  s21_ldecimal need_result_value_2 = {.bits = {1230}, .exp = 5};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 5};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 5};

  s21_ldecimal need_result_value_1 = {.bits = {123}, .exp = 5};
  s21_ldecimal need_result_value_2 = {.bits = {123}, .exp = 5};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 0};

  s21_ldecimal need_result_value_1 = {.bits = {123}, .exp = 0};
  s21_ldecimal need_result_value_2 = {.bits = {123}, .exp = 0};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits1_1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 10};

  s21_ldecimal need_result_value_1 = {.bits = {0x61B68C00, 0x11E}, .exp = 10};
  s21_ldecimal need_result_value_2 = {.bits = {123}, .exp = 10};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1_2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 10};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 0};

  s21_ldecimal need_result_value_1 = {.bits = {123}, .exp = 10};
  s21_ldecimal need_result_value_2 = {.bits = {0x61B68C00, 0x11E}, .exp = 10};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits2_1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 20};

  s21_ldecimal need_result_value_1 = {.bits = {0x98B00000, 0xC8CA3FCE, 0x29A},
                                      .exp = 20};
  s21_ldecimal need_result_value_2 = {.bits = {123}, .exp = 20};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2_2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 20};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 0};

  s21_ldecimal need_result_value_1 = {.bits = {123}, .exp = 20};
  s21_ldecimal need_result_value_2 = {.bits = {0x98B00000, 0xC8CA3FCE, 0x29A},
                                      .exp = 20};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits3_1) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 0};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 27};

  s21_ldecimal need_result_value_1 = {
      .bits = {0x78000000, 0xC92D9D43, 0x8D6F3720, 0x1}, .exp = 27};
  s21_ldecimal need_result_value_2 = {.bits = {123}, .exp = 27};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits3_2) {
  // arrange
  s21_ldecimal value_1 = {.bits = {123}, .exp = 27};
  s21_ldecimal value_2 = {.bits = {123}, .exp = 0};

  s21_ldecimal need_result_value_1 = {.bits = {123}, .exp = 27};
  s21_ldecimal need_result_value_2 = {
      .bits = {0x78000000, 0xC92D9D43, 0x8D6F3720, 0x1}, .exp = 27};
  bool need_result = true;

  // act
  bool result = s21_ldec_make_exp_equal(&value_1, &value_2);

  // assert
  ck_assert_mem_eq(&value_1, &need_result_value_1, sizeof(s21_ldecimal));
  ck_assert_mem_eq(&value_2, &need_result_value_2, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *make_exp_equal_tc(void) {
  TCase *tc = tcase_create("s21_ldec_make_exp_equal");

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);
  tcase_add_test(tc, t3);
  tcase_add_test(tc, t4);
  tcase_add_test(tc, t5);
  tcase_add_test(tc, t6);

  tcase_add_test(tc, bits1_1);
  tcase_add_test(tc, bits1_2);
  tcase_add_test(tc, bits2_1);
  tcase_add_test(tc, bits2_2);
  tcase_add_test(tc, bits3_1);
  tcase_add_test(tc, bits3_2);

  return tc;
}
