#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"
#include "./../../decimal/common/common_t.h"
#include "./../ldecimal_t.h"

START_TEST(bits0) {
  // arrange
  s21_decimal num = {.bits = {123}};
  s21_ldecimal need_result = {.bits = {123}};

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST
START_TEST(bits0_max) {
  // arrange
  s21_decimal num = {0};
  SET_MAX_INT(num.bits[0]);

  s21_ldecimal need_result = {0};
  SET_MAX_INT(need_result.bits[0]);

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST
START_TEST(bits1) {
  // arrange
  s21_decimal num = {.bits = {0, 123}};

  s21_ldecimal need_result = {.bits = {0, 123}};

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST
START_TEST(bits1_max) {
  // arrange
  s21_decimal num = {0};
  SET_MAX_INT(num.bits[1]);

  s21_ldecimal need_result = {0};
  SET_MAX_INT(need_result.bits[1]);

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST
START_TEST(bits2) {
  // arrange
  s21_decimal num = {.bits = {0, 0, 123}};

  s21_ldecimal need_result = {.bits = {0, 0, 123}};

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST
START_TEST(bits2_max) {
  // arrange
  s21_decimal num = {0};
  SET_MAX_INT(num.bits[2]);

  s21_ldecimal need_result = {0};
  SET_MAX_INT(need_result.bits[2]);

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST

START_TEST(zero) {
  // arrange
  s21_decimal num = {0};

  s21_ldecimal need_result = {0};

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST

START_TEST(negative_zero) {
  // arrange
  s21_decimal num = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 1)}};

  s21_ldecimal need_result = {0};

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST
START_TEST(negative_exp15) {
  // arrange
  s21_decimal num = {.bits = {123, 0, 0, S21_MAKE_EXP(15, S21_SIGN_MINUS)}};

  s21_ldecimal need_result = {.bits = {123}, .exp = 15, .sign = 1};

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST
START_TEST(negative_max_num_exp) {
  // arrange
  s21_decimal num = {.bits = {(int)S21_MAX_INT, (int)S21_MAX_INT,
                              (int)S21_MAX_INT,
                              S21_MAKE_EXP(28, S21_SIGN_MINUS)}};

  s21_ldecimal need_result = {
      .bits = {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT}, .exp = 28, .sign = 1};

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST

START_TEST(max_num_exp_plus) {
  // arrange
  s21_decimal num = {.bits = {(int)S21_MAX_INT, (int)S21_MAX_INT,
                              (int)S21_MAX_INT,
                              S21_MAKE_EXP(28, S21_SIGN_PLUS)}};

  s21_ldecimal need_result = {
      .bits = {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT}, .exp = 28, .sign = 0};

  // act
  s21_ldecimal result = s21_dec_to_ldec(&num);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST

START_TEST(null_reference) {
  // arrange
  s21_ldecimal need_result = {0};

  // act
  s21_ldecimal result = s21_dec_to_ldec(NULL);

  // assert
  ck_assert_mem_eq(&result, &need_result, sizeof(s21_ldecimal));
}
END_TEST

TCase *dec_to_ldec_tc(void) {
  TCase *tc = tcase_create("s21_dec_to_ldec");

  tcase_add_test(tc, bits0);
  tcase_add_test(tc, bits0_max);
  tcase_add_test(tc, bits1);
  tcase_add_test(tc, bits1_max);
  tcase_add_test(tc, bits2);
  tcase_add_test(tc, bits2_max);

  tcase_add_test(tc, zero);
  tcase_add_test(tc, negative_zero);
  tcase_add_test(tc, negative_exp15);
  tcase_add_test(tc, negative_max_num_exp);
  tcase_add_test(tc, max_num_exp_plus);

  tcase_add_test(tc, null_reference);

  return tc;
}
