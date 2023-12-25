#include <check.h>

#include "./../../../lib/ldecimal/common/s21_ldec_common.h"

START_TEST(t1) {
  // arrange
  s21_ldecimal num = {.bits = {99999}, .exp = 0};

  s21_ldecimal need_result_num = {.bits = {99999}, .exp = 0};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_ldecimal num = {.bits = {99999}, .exp = 1};

  s21_ldecimal need_result_num = {.bits = {99999}, .exp = 1};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_ldecimal num = {.bits = {99999}, .exp = 15};

  s21_ldecimal need_result_num = {.bits = {99999}, .exp = 15};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  s21_ldecimal num = {.bits = {10000}, .exp = 0};

  s21_ldecimal need_result_num = {.bits = {10000}, .exp = 0};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  s21_ldecimal num = {.bits = {10000}, .exp = 1};

  s21_ldecimal need_result_num = {.bits = {1000}, .exp = 0};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  s21_ldecimal num = {.bits = {10000}, .exp = 3};

  s21_ldecimal need_result_num = {.bits = {10}, .exp = 0};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  s21_ldecimal num = {.bits = {10000}, .exp = 4};

  s21_ldecimal need_result_num = {.bits = {1}, .exp = 0};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t8) {
  // arrange
  s21_ldecimal num = {.bits = {10000}, .exp = 5};

  s21_ldecimal need_result_num = {.bits = {1}, .exp = 1};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t9) {
  // arrange
  s21_ldecimal num = {.bits = {10000}, .exp = 10};

  s21_ldecimal need_result_num = {.bits = {1}, .exp = 6};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t10) {
  // arrange
  s21_ldecimal num = {.bits = {90000}, .exp = 4};

  s21_ldecimal need_result_num = {.bits = {9}, .exp = 0};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t11) {
  // arrange
  s21_ldecimal num = {.bits = {90000}, .exp = 6};

  s21_ldecimal need_result_num = {.bits = {9}, .exp = 2};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t12) {
  // arrange
  s21_ldecimal num = {.bits = {1234560001}, .exp = 4};

  s21_ldecimal need_result_num = {.bits = {1234560001}, .exp = 4};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t13) {
  // arrange
  s21_ldecimal num = {.bits = {123456000000}, .exp = 6};

  s21_ldecimal need_result_num = {.bits = {123456}, .exp = 0};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t14) {
  // arrange
  s21_ldecimal num = {.bits = {123456000000}, .exp = 7};

  s21_ldecimal need_result_num = {.bits = {123456}, .exp = 1};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(big_num1) {
  // arrange
  // 1234567890000000000000000000000000000000
  s21_ldecimal num = {
      .bits = {0x80000000, 0xE9487EA8, 0x31F2E3C1, 0xA0C92074, 0x3}, .exp = 31};

  s21_ldecimal need_result_num = {.bits = {0x75BCD15}, .exp = 0};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(big_num2) {
  // arrange
  // 1234567890000000000000000000000000000001
  s21_ldecimal num = {
      .bits = {0x80000001, 0xE9487EA8, 0x31F2E3C1, 0xA0C92074, 0x3}, .exp = 31};

  s21_ldecimal need_result_num = {
      .bits = {0x80000001, 0xE9487EA8, 0x31F2E3C1, 0xA0C92074, 0x3}, .exp = 31};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(big_num3) {
  // arrange
  // 10000000000000000000000000000000000000000000000000000000000000000000
  s21_ldecimal num = {.bits = {0x00000000, 0x00000000, 0xB6891BE8, 0x8E5F518B,
                               0x1EA97776, 0x21E86476, 0x5EF4A747},
                      .exp = 66};

  s21_ldecimal need_result_num = {.bits = {10}, .exp = 0};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(big_num4) {
  // arrange
  // 6277101735386680763835789423049210091073826769276946612225
  s21_ldecimal num = {.bits = {0x00000001, 0x00000000, 0x00000000, 0xFFFFFFFE,
                               0xFFFFFFFF, 0xFFFFFFFF},
                      .exp = 56};
  s21_ldecimal need_result_num = {.bits = {0x00000001, 0x00000000, 0x00000000,
                                           0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF},
                                  .exp = 56};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(sign) {
  // arrange
  s21_ldecimal num = {.bits = {123456000000}, .exp = 7, .sign = 1};

  s21_ldecimal need_result_num = {.bits = {123456}, .exp = 1, .sign = 1};
  norm_res need_result = nrOk;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(num_is_zero1) {
  // arrange
  s21_ldecimal num = {.bits = {0}, .exp = 0};

  s21_ldecimal need_result_num = {.bits = {0}, .exp = 0};
  norm_res need_result = nrIsZero;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(num_is_zero2) {
  // arrange
  s21_ldecimal num = {.bits = {0}, .exp = 10};

  s21_ldecimal need_result_num = {.bits = {0}, .exp = 0};
  norm_res need_result = nrIsZero;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(num_is_zero3) {
  // arrange
  s21_ldecimal num = {.bits = {0}, .exp = 10, .sign = 1};

  s21_ldecimal need_result_num = {.bits = {0}, .exp = 0, .sign = 0};
  norm_res need_result = nrIsZero;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(num_is_zero4) {
  // arrange
  s21_ldecimal num = {.bits = {0}, .exp = 0, .sign = 1};

  s21_ldecimal need_result_num = {.bits = {0}, .exp = 0, .sign = 0};
  norm_res need_result = nrIsZero;

  // act
  norm_res result = s21_ldec_normalize(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

TCase *normalize_tc(void) {
  TCase *tc = tcase_create("s21_ldec_normalize");

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

  tcase_add_test(tc, big_num1);
  tcase_add_test(tc, big_num2);
  tcase_add_test(tc, big_num3);
  tcase_add_test(tc, big_num4);

  tcase_add_test(tc, sign);

  tcase_add_test(tc, num_is_zero1);
  tcase_add_test(tc, num_is_zero2);
  tcase_add_test(tc, num_is_zero3);
  tcase_add_test(tc, num_is_zero4);

  return tc;
}
