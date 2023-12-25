#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(t1) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 0};

  s21_ldecimal need_result_num = {.bits = {3755744318UL, 2UL}, .exp = 1};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 1);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 0};

  s21_ldecimal need_result_num = {.bits = {3197704812UL, 28UL}, .exp = 2};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 2);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 0};

  s21_ldecimal need_result_num = {
      .bits = {2050490368UL, 3227769793UL, 669260594UL}, .exp = 19};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 19);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 0};

  s21_ldecimal need_result_num = {
      .bits = {3325034496UL, 2212926862UL, 2397638651UL, 1UL}, .exp = 20};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 20);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 0};

  s21_ldecimal need_result_num = {
      .bits = {0UL, 1231814656UL, 1471775UL, 653651817UL, 3050968231UL,
               2868184352UL, 19UL},
      .exp = 50};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 50);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 0};

  s21_ldecimal need_result_num = {
      .bits = {0UL, 939524096UL, 1663614695UL, 1192760466UL, 114557661UL,
               4121065329UL, 2487932024UL},
      .exp = 59};
  uint32_t need_result = 4;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 59);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  // 627710173538668076383578942304921009107382676927694661222 =>
  // 6277101735386680763835789423049210091073826769276946612220
  s21_ldecimal num = {.bits = {0x66666666, 0x66666666, 0x66666666, 0x99999999,
                               0x99999999, 0x19999999}};

  s21_ldecimal need_result_num = {.bits = {0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFF,
                                           0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF},
                                  .exp = 1};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 1);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(overflow_stop_shift1) {
  // arrange
  s21_ldecimal num = {.bits = {1234567891UL}, .exp = 0};

  s21_ldecimal need_result_num = {
      .bits = {0UL, 939524096UL, 1663614695UL, 1192760466UL, 114557661UL,
               4121065329UL, 2487932024UL},
      .exp = 59};
  uint32_t need_result = 4;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 60);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(overflow_stop_shift2) {
  // arrange
  // 100000000000000000000000000000000000000000000000000000000000000000000
  s21_ldecimal num = {.bits = {1}, .exp = 0};

  s21_ldecimal need_result_num = {
      .bits = {0x00000000, 0x00000000, 0x215B1710, 0x8FB92F75, 0x329EAAA1,
               0x5313EC9D, 0xB58E88C7},
      .exp = 68};
  uint32_t need_result = 0x3;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 68);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(overflow_stop_shift3) {
  // arrange
  // 100000000000000000000000000000000000000000000000000000000000000000000
  s21_ldecimal num = {.bits = {1}, .exp = 0};

  s21_ldecimal need_result_num = {
      .bits = {0x00000000, 0x00000000, 0x215B1710, 0x8FB92F75, 0x329EAAA1,
               0x5313EC9D, 0xB58E88C7},
      .exp = 68};
  uint32_t need_result = 0x3;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 69);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(not_overflow) {
  // arrange
  // 10000000000000000000000000000000000000000000000000000000000000000000
  s21_ldecimal num = {.bits = {1}, .exp = 0};

  s21_ldecimal need_result_num = {
      .bits = {0x00000000, 0x00000000, 0xB6891BE8, 0x8E5F518B, 0x1EA97776,
               0x21E86476, 0x5EF4A747},
      .exp = 67};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_shift_left(&num, 67);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

TCase *shift_left_tc(void) {
  TCase *tc = tcase_create("s21_ldec_shift_left");

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);
  tcase_add_test(tc, t3);
  tcase_add_test(tc, t4);
  tcase_add_test(tc, t5);
  tcase_add_test(tc, t6);
  tcase_add_test(tc, t7);

  tcase_add_test(tc, overflow_stop_shift1);
  tcase_add_test(tc, overflow_stop_shift2);
  tcase_add_test(tc, overflow_stop_shift3);

  tcase_add_test(tc, not_overflow);

  return tc;
}
