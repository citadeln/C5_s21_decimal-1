#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  float src = 123000000000.0F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {(int)0xA35F0E00, (int)0x1C}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  //
  float src = 0.000000123F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {123, 0, 0, S21_MAKE_EXP(9, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  //
  float src = 0.4F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {4, 0, 0, S21_MAKE_EXP(1, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  //
  float src = 12345678.0F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {12345680, 0, 0, S21_MAKE_EXP(0, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  // 7.9228160000000000000000000000
  float src = 7.9228160e28F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {(int)0x20000000, (int)0xB392B21A,
                                          (int)0xFFFFFF77, S21_MAKE_EXP(0, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  // 9999999000000000000000000000
  float src = 1e28F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {(int)0x31600000, (int)0x085B549B,
                                          (int)0x204FCE28, S21_MAKE_EXP(0, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  // 0.0000000000000000000000000001
  float src = 1e-28F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t8) {
  // arrange
  // 0.00000000000000000000000000001
  float src = 1e-29F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {0};
  int need_result = S21_CONVERT_ERROR;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t9) {
  // arrange
  // 0.00000000000000000000000000007922816
  float src = 7.922816e-29F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t10) {
  // arrange
  // 0.0000000000000000000000000007922816
  float src = 7.922816e-28F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {8, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t11) {
  // arrange
  // 0.0000000000000000000000000009922816
  float src = 9.922816e-28F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {1, 0, 0, S21_MAKE_EXP(27, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t12) {
  // arrange
  // 0.0000000000000000000000000000522816
  float src = 522816e-34F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t13) {
  // arrange
  // 0.0000000000000000000000000000422816
  float src = 422816e-34F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {0};
  int need_result = S21_CONVERT_ERROR;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t14) {
  // arrange
  float src = 0.4F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {4, 0, 0, S21_MAKE_EXP(1, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(range1) {
  // arrange
  float src = 1e-28F;
  s21_decimal dst = {0};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(range2) {
  // arrange
  float src = 1e-29F;
  s21_decimal dst = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(1, 1)}};

  int need_bits0 = 0;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = 0;
  int need_result = 1;

  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST
START_TEST(range3) {
  // arrange
  // 79228170000000000000000000000
  float src = 7.922817e28F;
  s21_decimal dst = {0};
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(range4) {
  // arrange
  // 79228160000000000000000000000
  float src = 7.922816e28F;
  s21_decimal dst = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(range5) {
  // arrange
  float src = 1e-30F;
  s21_decimal dst = {0};

  int need_bits0 = 0;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = 0;
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST
START_TEST(range6) {
  // arrange
  float src = 1e29F;
  s21_decimal dst = {0};

  int need_bits0 = 0;
  int need_bits1 = 0;
  int need_bits2 = 0;
  int need_bits3 = 0;
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
  ck_assert_int_eq(dst.bits[0], need_bits0);
  ck_assert_int_eq(dst.bits[1], need_bits1);
  ck_assert_int_eq(dst.bits[2], need_bits2);
  ck_assert_int_eq(dst.bits[3], need_bits3);
}
END_TEST

START_TEST(sign) {
  // arrange
  float src = -0.4F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {.bits = {4, 0, 0, S21_MAKE_EXP(1, 1)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(zero1) {
  // arrange
  float src = 0.0F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {0};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(zero2) {
  // arrange
  float src = -0.0F;
  s21_decimal dst = {0};

  s21_decimal need_result_dst = {0};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(not_init_num) {
  // arrange
  // 12345670000000000000000000000
  float src = 1.234567e28F;
  s21_decimal dst = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_dst = {.bits = {(int)0x7FC00000, (int)0xBD4CFAF5,
                                          (int)0x27E4194F, S21_MAKE_EXP(0, 0)}};
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_float_to_decimal(src, &dst);

  // assert
  ck_assert_mem_eq(&dst, &need_result_dst, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(null) {
  // arrange
  float src = 0.0F;
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_float_to_decimal(src, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST

Suite *from_float_to_decimal_sc(void) {
  Suite *suite = suite_create("s21_from_float_to_decimal");

  TCase *t_tc = tcase_create("s21_from_float_to_decimal");

  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);
  tcase_add_test(t_tc, t5);
  tcase_add_test(t_tc, t6);
  tcase_add_test(t_tc, t7);
  tcase_add_test(t_tc, t8);
  tcase_add_test(t_tc, t9);
  tcase_add_test(t_tc, t10);
  tcase_add_test(t_tc, t11);
  tcase_add_test(t_tc, t12);
  tcase_add_test(t_tc, t13);
  tcase_add_test(t_tc, t14);

  tcase_add_test(t_tc, range1);
  tcase_add_test(t_tc, range2);
  tcase_add_test(t_tc, range3);
  tcase_add_test(t_tc, range4);
  tcase_add_test(t_tc, range5);
  tcase_add_test(t_tc, range6);

  tcase_add_test(t_tc, sign);

  tcase_add_test(t_tc, zero1);
  tcase_add_test(t_tc, zero2);

  tcase_add_test(t_tc, not_init_num);
  tcase_add_test(t_tc, null);

  suite_add_tcase(suite, t_tc);

  return suite;
}

MAKE_TEST(from_float_to_decimal)
