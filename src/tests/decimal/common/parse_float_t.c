#include <check.h>

#include "./../../../lib/common/s21_parse_float.h"

START_TEST(t1) {
  // arrange
  float num = 0.0;

  int need_num = 0;
  int need_exp = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
}
END_TEST
START_TEST(t2) {
  // arrange
  float num = 1.0;

  int need_num = 1;
  int need_exp = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
}
END_TEST
START_TEST(t3) {
  // arrange
  float num = 123.456e20F;

  int need_num = 123456;
  int need_exp = 17;
  int need_cnt_digs = 6;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(t4) {
  // arrange
  float num = 1.23456e20F;

  int need_num = 123456;
  int need_exp = 15;
  int need_cnt_digs = 6;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(t5) {
  // arrange
  float num = 123456.e20F;

  int need_num = 123456;
  int need_exp = 20;
  int need_cnt_digs = 6;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(t6) {
  // arrange
  float num = 1.01e32F;

  int need_num = 101;
  int need_exp = 30;
  int need_cnt_digs = 3;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(t7) {
  // arrange
  float num = 1.0e32F;

  int need_num = 1;
  int need_exp = 32;
  int need_cnt_digs = 1;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(t8) {
  // arrange
  float num = 10.0F;

  int need_num = 1;
  int need_exp = 1;
  int need_cnt_digs = 1;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(t9) {
  // arrange
  float num = 1e-40F;

  int need_num = 0;
  int need_exp = 0;
  int need_cnt_digs = 0;
  int need_sign = 0;
  int need_error = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(t10) {
  // arrange
  float num = 1.234567F;

  int need_num = 1234567;
  int need_exp = -6;
  int need_cnt_digs = 7;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(t11) {
  // arrange
  float num = 0.0F;

  int need_num = 0;
  int need_exp = 0;
  int need_cnt_digs = 0;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST

START_TEST(parse_float_part1) {
  // arrange
  float num = 1e-10F;

  int need_num = 1;
  int need_exp = -10;
  int need_cnt_digs = 1;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(parse_float_part2) {
  // arrange
  float num = 1e-27F;

  int need_num = 1;
  int need_exp = -27;
  int need_cnt_digs = 1;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(parse_float_part3) {
  // arrange
  float num = 1.23e-28F;

  int need_num = 1;
  int need_exp = -28;
  int need_cnt_digs = 1;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(parse_float_part4) {
  // arrange
  float num = 9.234565e-37F;

  int need_num = 0;
  int need_exp = 0;
  int need_cnt_digs = 0;
  int need_sign = 0;
  int need_error = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST

START_TEST(round1) {
  // arrange
  float num = 1234567.6F;

  int need_num = 1234568;
  int need_exp = 0;
  int need_cnt_digs = 7;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round2) {
  // arrange
  float num = 1234567.4F;

  int need_num = 1234567;
  int need_exp = 0;
  int need_cnt_digs = 7;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round3) {
  // arrange
  float num = 1234567.5F;

  int need_num = 1234568;
  int need_exp = 0;
  int need_cnt_digs = 7;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round4) {
  // arrange
  float num = 1234568.5F;

  int need_num = 1234568;
  int need_exp = 0;
  int need_cnt_digs = 7;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round5) {
  // arrange
  float num = 1234569.5F;

  int need_num = 123457;
  int need_exp = 1;
  int need_cnt_digs = 6;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round6) {
  // arrange
  float num = 123456.501F;

  int need_num = 1234565;
  int need_exp = -1;
  int need_cnt_digs = 7;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round7) {
  // arrange
  float num = 1234.5675F;

  int need_num = 1234568;
  int need_exp = -3;
  int need_cnt_digs = 7;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round8) {
  // arrange
  float num = 1234.5625F;

  int need_num = 1234562;
  int need_exp = -3;
  int need_cnt_digs = 7;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round9) {
  // arrange
  float num = 1234.5195F;

  int need_num = 123452;
  int need_exp = -2;
  int need_cnt_digs = 6;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round10) {
  // arrange
  float num = 0.12345675F;

  int need_num = 1234567;
  int need_exp = -7;
  int need_cnt_digs = 7;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round11) {
  // arrange
  float num = 1.234551e-24F;

  int need_num = 12346;
  int need_exp = -28;
  int need_cnt_digs = 5;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(round12) {
  // arrange
  float num = 1.23455e-24F;

  int need_num = 12345;
  int need_exp = -28;
  int need_cnt_digs = 5;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.cnt_digs, need_cnt_digs);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST

START_TEST(negative1) {
  // arrange
  float num = -1.0;

  int need_num = 1;
  int need_exp = 0;
  int need_sign = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
}
END_TEST
START_TEST(negative2) {
  // arrange
  float num = -1.0e32F;

  int need_num = 1;
  int need_exp = 32;
  int need_sign = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
}
END_TEST

START_TEST(error1) {
  // arrange
  float num = -INFINITY;  // negative Inf

  int need_num = 0;
  int need_exp = 0;
  int need_sign = 1;
  int need_error = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(error2) {
  // arrange
  float num = INFINITY;  // positive Inf

  int need_num = 0;
  int need_exp = 0;
  int need_sign = 0;
  int need_error = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(error3) {
  // arrange
  float num = NAN;  // Nan

  int need_num = 0;
  int need_exp = 0;
  int need_sign = 0;
  int need_error = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(error4) {
  // arrange
  float num = NAN;  // Nan
  num = -num;       // convert sign

  int need_num = 0;
  int need_exp = 0;
  int need_sign = 0;
  int need_error = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST

START_TEST(overflow1) {
  // arrange
  float num = 3.4e38F;

  int need_num = 34;
  int need_exp = 37;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(overflow2) {
  // arrange
  float num = -3.4e38F;

  int need_num = 34;
  int need_exp = 37;
  int need_sign = 1;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(overflow3) {
  // arrange
  float num = 3.401e38F;

  int need_num = 0;
  int need_exp = 0;
  int need_sign = 0;
  int need_error = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(overflow4) {
  // arrange
  float num = -3.401e38F;

  int need_num = 0;
  int need_exp = 0;
  int need_sign = 1;
  int need_error = 1;

  // act
  s21_fparse_t result = s21_parse_float(num, 28);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST

START_TEST(precision1) {
  // arrange
  float num = 1.25F;

  int need_num = 12;
  int need_exp = -1;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 1);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST
START_TEST(precision2) {
  // arrange
  float num = 1.35F;

  int need_num = 14;
  int need_exp = -1;
  int need_sign = 0;
  int need_error = 0;

  // act
  s21_fparse_t result = s21_parse_float(num, 1);

  // assert
  ck_assert_int_eq(result.num, need_num);
  ck_assert_int_eq(result.exp, need_exp);
  ck_assert_int_eq(result.sign, need_sign);
  ck_assert_int_eq(result.error, need_error);
}
END_TEST

TCase *parse_float_tc(void) {
  TCase *tc = tcase_create("s21_parse_float");
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

  tcase_add_test(tc, round1);
  tcase_add_test(tc, round2);
  tcase_add_test(tc, round3);
  tcase_add_test(tc, round4);
  tcase_add_test(tc, round5);
  tcase_add_test(tc, round6);
  tcase_add_test(tc, round7);
  tcase_add_test(tc, round8);
  tcase_add_test(tc, round9);
  tcase_add_test(tc, round10);
  tcase_add_test(tc, round11);
  tcase_add_test(tc, round12);

  tcase_add_test(tc, negative1);
  tcase_add_test(tc, negative2);

  tcase_add_test(tc, error1);
  tcase_add_test(tc, error2);
  tcase_add_test(tc, error3);
  tcase_add_test(tc, error4);

  tcase_add_test(tc, overflow1);
  tcase_add_test(tc, overflow2);
  tcase_add_test(tc, overflow3);
  tcase_add_test(tc, overflow4);

  tcase_add_test(tc, parse_float_part1);
  tcase_add_test(tc, parse_float_part2);
  tcase_add_test(tc, parse_float_part3);
  tcase_add_test(tc, parse_float_part4);

  tcase_add_test(tc, precision1);
  tcase_add_test(tc, precision2);

  return tc;
}
