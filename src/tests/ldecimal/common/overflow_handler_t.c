#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"

START_TEST(bits0to1) {
  // arrange
  s21_ldecimal num = {.bits = {123456789123UL}};

  s21_ldecimal need_result_num = {.bits = {3197704835, 28}};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(bits1to2) {
  // arrange
  s21_ldecimal num = {.bits = {3577781834554UL, 35470741382UL}};

  s21_ldecimal need_result_num = {.bits = {74076986UL, 1111003847UL, 8UL}};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(bits2to3) {
  // arrange
  s21_ldecimal num = {.bits = {[1] = 3577781834554UL, 35470741382UL}};

  s21_ldecimal need_result_num = {
      .bits = {[1] = 74076986UL, 1111003847UL, 8UL}};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(bits3to4) {
  // arrange
  s21_ldecimal num = {.bits = {[2] = 3577781834554UL, 35470741382UL}};

  s21_ldecimal need_result_num = {
      .bits = {[2] = 74076986UL, 1111003847UL, 8UL}};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bits4to5) {
  // arrange
  s21_ldecimal num = {.bits = {[3] = 3577781834554UL, 35470741382UL}};

  s21_ldecimal need_result_num = {
      .bits = {[3] = 74076986UL, 1111003847UL, 8UL}};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bits5to6) {
  // arrange
  s21_ldecimal num = {.bits = {[4] = 3577781834554UL, 35470741382UL}};

  s21_ldecimal need_result_num = {
      .bits = {[4] = 74076986UL, 1111003847UL, 8UL}};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(bits6to7) {
  // arrange
  s21_ldecimal num = {.bits = {[5] = 3577781834554UL}};

  s21_ldecimal need_result_num = {.bits = {[5] = 74076986UL, 833UL}};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(overflow) {
  // arrange
  s21_ldecimal num = {.bits = {[6] = 3577781834554UL}};

  s21_ldecimal need_result_num = {.bits = {[6] = 74076986UL}};
  uint32_t need_result = 833UL;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow2) {
  // arrange
  s21_ldecimal num = {.bits = {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFF}};

  s21_ldecimal need_result_num = {.bits = {0xFFFFFFFF, 0xFFFFFFFE, 0x1}};
  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(maxnum_overflow) {
  // arrange
  const uint64_t max = 0xFFFFFFFE00000001UL;
  s21_ldecimal num = {.bits = {max, max, max, max, max, max, max}};

  s21_ldecimal need_result_num = {.bits = {1UL, 4294967295UL, 4294967295UL,
                                           4294967295UL, 4294967295UL,
                                           4294967295UL, 4294967295UL}};
  uint32_t need_result = 4294967294UL;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(maxnum_not_overflow) {
  // arrange
  const uint64_t max = 0xFFFFFFFE00000001UL;
  s21_ldecimal num = {
      .bits = {max, max, max, max, max, max}, .exp = 10, .sign = 1};
  s21_ldecimal need_result_num = {
      .bits = {1UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL,
               4294967295UL, 4294967294UL},
      .exp = 10};
  need_result_num.sign = 1;

  uint32_t need_result = 0;

  // act
  uint32_t result = s21_ldec_overflow_handler(&num);

  // assert
  ck_assert_mem_eq(&num, &need_result_num, sizeof(s21_ldecimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

TCase *overflow_handler_tc(void) {
  TCase *tc = tcase_create("s21_ldec_overflow_handler");

  tcase_add_test(tc, bits0to1);
  tcase_add_test(tc, bits1to2);
  tcase_add_test(tc, bits2to3);
  tcase_add_test(tc, bits3to4);
  tcase_add_test(tc, bits4to5);
  tcase_add_test(tc, bits5to6);
  tcase_add_test(tc, bits6to7);

  tcase_add_test(tc, overflow);
  tcase_add_test(tc, overflow2);

  tcase_add_test(tc, maxnum_overflow);
  tcase_add_test(tc, maxnum_not_overflow);

  return tc;
}
