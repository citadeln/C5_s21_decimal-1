#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  // 0.00000000000000000000000000012345678
  s21_decimal src = {.bits = {12345678, 0, 0, S21_MAKE_EXP(35, 0)}};
  float dst;

  float need_result_dst = 1.0e-28F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  // 37485638348795637489456789236
  s21_decimal src = {.bits = {(int)0xB4BE36F4, (int)0xBD0EE26C, (int)0x791F64AE,
                              S21_MAKE_EXP(0, 0)}};
  float dst;

  float need_result_dst = 37485638348795637489456789236.F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  // 0.00123456789
  // 123456789
  s21_decimal src = {.bits = {123456789, 0, 0, S21_MAKE_EXP(11, 0)}};
  float dst;

  float need_result_dst = 0.00123456789F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  // 0.00000000000000000000000000005345678
  s21_decimal src = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  float dst;

  float need_result_dst = 0.0000000000000000000000000001F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  // 123.45675
  s21_decimal src = {.bits = {12345675, 0, 0, S21_MAKE_EXP(5, 0)}};
  float dst;

  float need_result_dst = 123.45675F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  // 0.12345675
  s21_decimal src = {.bits = {12345675, 0, 0, S21_MAKE_EXP(8, 0)}};
  float dst;

  float need_result_dst = 0.12345675F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  // 1.2345675
  s21_decimal src = {.bits = {12345675, 0, 0, S21_MAKE_EXP(7, 0)}};
  float dst;

  float need_result_dst = 1.2345675F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t8) {
  // arrange
  // 123456.75
  s21_decimal src = {.bits = {12345675, 0, 0, S21_MAKE_EXP(2, 0)}};
  float dst;

  float need_result_dst = 123456.75F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t9) {
  // arrange
  // 1234567.5
  s21_decimal src = {.bits = {12345675, 0, 0, S21_MAKE_EXP(1, 0)}};
  float dst;

  float need_result_dst = 1234567.5F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t10) {
  // arrange
  // 12345675.0
  s21_decimal src = {.bits = {12345675, 0, 0, S21_MAKE_EXP(0, 0)}};
  float dst;

  float need_result_dst = 12345675.0F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t11) {
  // arrange
  s21_decimal src = {.bits = {5, 0, 0, S21_MAKE_EXP(6, 0)}};
  float dst;

  float need_result_dst = 0.000005F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t12) {
  // arrange
  s21_decimal src = {.bits = {100000001, 0, 0, S21_MAKE_EXP(8, 0)}};
  float dst;

  float need_result_dst = 1.0F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t13) {
  // arrange
  s21_decimal src = {.bits = {1234567, 0, 0, S21_MAKE_EXP(0, 0)}};
  float dst;

  float need_result_dst = 1234567.0F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t14) {
  // arrange
  s21_decimal src = {.bits = {1234568, 0, 0, S21_MAKE_EXP(4, 0)}};
  float dst;

  float need_result_dst = 123.4568F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t15) {
  // arrange
  // 326236.328238
  s21_decimal src = {.bits = {(int)0xF533512E, (int)0x4B}};
  src.bits[3] = S21_MAKE_EXP(6, 0);
  float dst;

  float need_dst = 326236.328238F;
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t16) {
  // arrange
  // 79228162514264337593543950335
  s21_decimal src = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  src.bits[3] = S21_MAKE_EXP(0, 0);
  float dst;

  float need_dst = 79228162514264337593543950335.0F;
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t17) {
  // arrange
  // 0.79228145
  s21_decimal src = {.bits = {79228145}};
  src.bits[3] = S21_MAKE_EXP(8, 0);
  float dst;

  float need_dst = 0.79228145F;
  int need_result = S21_RESULT_OK;
  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t18) {
  // arrange
  // 605492791886648540813348.64
  s21_decimal src = {.bits = {0x003A6E50, 0x007F1483, 0x003215CF}};
  src.bits[3] = S21_MAKE_EXP(2, 0);
  float dst;

  float need_dst = 605492791886648540813348.64f;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  s21_decimal src = {.bits = {1, 0, 0, S21_MAKE_EXP(0, 1)}};
  float dst;

  float need_result_dst = -1.0F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(zero) {
  // arrange
  s21_decimal src = {0};
  float dst;

  float need_result_dst = 0.0F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(null) {
  // arrange
  s21_decimal src = {0};

  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_decimal_to_float(src, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(convert_error) {
  // arrange
  s21_decimal src = {0};
  src.bits[3] = 1;
  float dst = 0.0F;
  int need_result = S21_CONVERT_ERROR;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(maxexp1) {
  // arrange
  s21_decimal src = {0};
  src.bits[3] = (int)0x80FF0000;
  float dst = 0.0F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(maxexp2) {
  // arrange
  s21_decimal src = {.bits = {1}};
  src.bits[3] = (int)0x80FF0000;
  float dst = 0.0F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(maxexp3) {
  // arrange
  s21_decimal src = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  src.bits[3] = (int)0x80FF0000;
  float dst = 0.0F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(not_init) {
  // arrange
  s21_decimal src = {.bits = {123}};
  src.bits[3] = S21_MAKE_EXP(1, 0);
  float dst = -999999.9F;

  float need_result_dst = 12.3F;
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_from_decimal_to_float(src, &dst);

  // assert
  ck_assert_float_eq(dst, need_result_dst);
  ck_assert_int_eq(result, need_result);
}
END_TEST

Suite *from_decimal_to_float_sc(void) {
  Suite *suite = suite_create("s21_from_decimal_to_float");

  TCase *t_tc = tcase_create("s21_from_decimal_to_float");

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
  tcase_add_test(t_tc, t15);
  tcase_add_test(t_tc, t16);
  tcase_add_test(t_tc, t17);
  tcase_add_test(t_tc, t18);

  tcase_add_test(t_tc, sign1);
  tcase_add_test(t_tc, zero);
  tcase_add_test(t_tc, null);
  tcase_add_test(t_tc, convert_error);
  tcase_add_test(t_tc, not_init);

  tcase_add_test(t_tc, maxexp1);
  tcase_add_test(t_tc, maxexp2);
  tcase_add_test(t_tc, maxexp3);

  suite_add_tcase(suite, t_tc);

  return suite;
}

MAKE_TEST(from_decimal_to_float)
