#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(t1) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 1};

  s21_ldecimal need_result_num = {.bits = {123456789UL}, .exp = 0};
  uint32_t need_result = 1;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(transfer1) {
  // arrange
  // 4294967296 => 429496729
  s21_ldecimal num = {.bits = {0, 1}, .exp = 9};

  s21_ldecimal need_result_num = {.bits = {0x19999999}, .exp = 8};
  uint32_t need_result = 6;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(transfer2) {
  // arrange
  // 18446744073709551616
  // 19999999 99999999
  s21_ldecimal num = {.bits = {0, 0, 1}, .exp = 19};

  s21_ldecimal need_result_num = {.bits = {0x99999999, 0x19999999}, .exp = 18};
  uint32_t need_result = 6;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits0) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 3};

  s21_ldecimal need_result_num = {.bits = {123456789UL}, .exp = 2};
  uint32_t need_result = 1;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1) {
  // arrange
  s21_ldecimal num = {.bits = {3755744318UL, 2UL}, .exp = 9};

  s21_ldecimal need_result_num = {.bits = {1234567891UL}, .exp = 8};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2) {
  // arrange
  s21_ldecimal num = {.bits = {2547070976UL, 2974719893UL, 6UL}, .exp = 11};

  s21_ldecimal need_result_num = {.bits = {4120177664UL, 2874452366UL},
                                  .exp = 10};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits3) {
  // arrange
  s21_ldecimal num = {.bits = {3325034496UL, 2212926862UL, 2397638651UL, 1UL},
                      .exp = 20};

  s21_ldecimal need_result_num = {
      .bits = {2050490368UL, 3227769793UL, 669260594UL}, .exp = 19};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits4) {
  // arrange
  s21_ldecimal num = {
      .bits = {3221225472UL, 800943250UL, 3508502674UL, 2697535616UL, 3UL},
      .exp = 30};

  s21_ldecimal need_result_num = {
      .bits = {3758096384UL, 3516068161UL, 2068837185UL, 1558243750UL},
      .exp = 29};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits5) {
  // arrange
  s21_ldecimal num = {
      .bits = {0UL, 100725504UL, 3958325358UL, 1834552814UL, 1920951171UL, 8UL},
      .exp = 40};

  s21_ldecimal need_result_num = {
      .bits = {0UL, 2587052928UL, 3831806372UL, 4048925847UL, 3628068953UL},
      .exp = 39};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits6) {
  // arrange
  s21_ldecimal num = {.bits = {0UL, 3988652032UL, 3865617743UL, 3071842288UL,
                               2882077200UL, 4152289001UL, 1UL},
                      .exp = 49};

  s21_ldecimal need_result_num = {
      .bits = {0UL, 1687355392UL, 386561774UL, 1166177688UL, 3294684827UL,
               844725629UL},
      .exp = 48};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(max_num) {
  // arrange
  s21_ldecimal num = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX,
                               UINT32_MAX, UINT32_MAX, UINT32_MAX},
                      .exp = 55};

  s21_ldecimal need_result_num = {
      .bits = {2576980377UL, 2576980377UL, 2576980377UL, 2576980377UL,
               2576980377UL, 2576980377UL, 429496729},
      .exp = 54};
  uint32_t need_result = 5;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(zero_num) {
  // arrange
  s21_ldecimal num = {.bits = {0}, .exp = 0};

  s21_ldecimal need_result_num = {.bits = {0}, .exp = 0};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(error1) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 0};

  s21_ldecimal need_result_num = {.bits = {123456789UL}, .exp = 0};
  uint32_t need_result = 1U;

  // act
  uint32_t result = s21_ldec_shift_right(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *shift_right_tc(void) {
  TCase *tc = tcase_create("s21_ldec_shift_right");

  tcase_add_test(tc, t1);

  tcase_add_test(tc, transfer1);
  tcase_add_test(tc, transfer2);

  tcase_add_test(tc, bits0);
  tcase_add_test(tc, bits1);
  tcase_add_test(tc, bits2);
  tcase_add_test(tc, bits3);
  tcase_add_test(tc, bits4);
  tcase_add_test(tc, bits5);
  tcase_add_test(tc, bits6);

  tcase_add_test(tc, max_num);

  tcase_add_test(tc, zero_num);

  tcase_add_test(tc, error1);

  return tc;
}
