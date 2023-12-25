#include <check.h>

#include "./../../../lib/ldecimal/s21_ldecimal.h"
#include "./../../decimal/common/common_t.h"

START_TEST(t1) {
  // arrange
  s21_ldecimal num = {.bits = {123456}, .exp = 3, .sign = 1};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {123456, 0, 0, S21_MAKE_EXP(3, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(error1) {
  // arrange
  // 123456789123456789123456789123
  s21_ldecimal num = {.bits = {0x71136A83, 0xC96DD6FC, 0x8EE90FFC, 1},
                      .exp = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)0x71136A83, (int)0xC96DD6FC, (int)0x8EE90FFC}};
  int need_result = S21_BIG_NUM_ERROR;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(error2) {
  // arrange
  // -123456789123456789123456789123
  s21_ldecimal num = {
      .bits = {0x71136A83, 0xC96DD6FC, 0x8EE90FFC, 1}, .exp = 0, .sign = 1};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {(int)0x71136A83, (int)0xC96DD6FC,
                                          (int)0x8EE90FFC, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_SMALL_NUM_ERROR;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(error3) {
  // arrange
  // 7922816251426433759354395033579228162514264337593543950335 =>
  // 79228162514264337593543950336
  s21_ldecimal num = {.bits = {0x5FFFFFFF, 0x928DE835, 0xBCE1F051, 0x9FFFFFFF,
                               0x6D7217CA, 0x431E0FAE, 0x1},
                      .exp = 29};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {0, S21_MAKE_EXP(0, 0)}};
  int need_result = S21_BIG_NUM_ERROR;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(overflow1) {
  // arrange
  // 12345678912345678912345678910 =>
  // 1234567891234567891234567891
  s21_ldecimal num = {.bits = {0x71B5243E, 0xE0F1624C, 0x27E41B32}, .exp = 1};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)0xD82BB6D3, (int)0x7CE4F03A, (int)0x3FD35EB}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow2) {
  // arrange
  // 12345678912345678912345678910000000 =>
  // 1234567891234567891234567891
  s21_ldecimal num = {.bits = {0x40430B80, 0x3A2AF20A, 0x600518DB, 0x260B0},
                      .exp = 34};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {(int)0xD82BB6D3, (int)0x7CE4F03A,
                                          (int)0x3FD35EB, S21_MAKE_EXP(27, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow3) {
  // arrange
  // 00000000000000000000012345678 9123456789123456789123
  s21_ldecimal num = {
      .bits = {0x71136A83, 0xC96DD6FC, 0x8EE90FFC, 1}, .exp = 50, .sign = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {12345679, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow4) {
  // arrange
  // 0000000000000000000000000000123456789123456789123456789123
  s21_ldecimal num = {
      .bits = {0x71136A83, 0xC96DD6FC, 0x8EE90FFC, 1}, .exp = 57, .sign = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow5) {
  // arrange
  // 00000000000000000000000000000123456789123456789123456789123
  s21_ldecimal num = {
      .bits = {0x71136A83, 0xC96DD6FC, 0x8EE90FFC, 1}, .exp = 58, .sign = 1};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow6) {
  // arrange
  // 000000000000000000000000000009123456789123456789123 =>
  // 00000000000000000000000000001
  s21_ldecimal num = {
      .bits = {0xE1936A83, 0x9565BB8F, 0x1EE, 0}, .exp = 50, .sign = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow7) {
  // arrange
  // 000000000000000000000000000005 =>
  // 0
  s21_ldecimal num = {.bits = {5}, .exp = 29, .sign = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow8) {
  // arrange
  // 0000000000000000000000000000050000000000000000000000000000000000001 =>
  // 00000000000000000000000000001
  s21_ldecimal num = {.bits = {0x00000001, 0x04C51120, 0x2D43623D, 0x259DA654},
                      .exp = 66,
                      .sign = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow9) {
  // arrange
  // 000000000000000000000000000015 =>
  // 00000000000000000000000000002
  s21_ldecimal num = {.bits = {0xF}, .exp = 29, .sign = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {2, 0, 0, S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow10) {
  // arrange
  // 79228162514264337593543950336 =>
  // 7922816251426433759354395034
  s21_ldecimal num = {.bits = {0, 0, 0, 1}, .exp = 28};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {(int)0x9999999A, (int)0x99999999,
                                          (int)0x19999999,
                                          S21_MAKE_EXP(27, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow11) {
  // arrange
  // 79228162514264337593543950336 =>
  // 7922816251426433759354395034
  s21_ldecimal num = {.bits = {0, 0, 0, 1}, .exp = 28};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {(int)0x9999999A, (int)0x99999999,
                                          (int)0x19999999,
                                          S21_MAKE_EXP(27, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(overflow12) {
  // arrange
  // 7922816251426433759354395033479228162514264337593543950335 =>
  // 79228162514264337593543950335
  s21_ldecimal num = {.bits = {0xBFFFFFFF, 0x251BD06A, 0x79C3E0A3, 0x9FFFFFFE,
                               0x6D7217CA, 0x431E0FAE, 0x1},
                      .exp = 29};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {(int)0xFFFFFFFF, (int)0xFFFFFFFF,
                                          (int)0xFFFFFFFF, S21_MAKE_EXP(0, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(overflow_to_zero) {
  // arrange
  // 00000000000000000000000000000 4123456789123456789123
  s21_ldecimal num = {
      .bits = {0x88736A83, 0x887556B2, 0xDF}, .exp = 50, .sign = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {0, 0}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(round_no_need1) {
  // arrange
  // 123456789123456789123456789125 =>
  // 12345678912345678912345678912
  s21_ldecimal num = {.bits = {0x71136A85, 0xC96DD6FC, 0x8EE90FFC, 1},
                      .exp = 15};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {(int)0x71B52440, (int)0xE0F1624C,
                                          (int)0x27E41B32,
                                          S21_MAKE_EXP(14, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(round1) {
  // arrange
  // 123456789123456789123456789135 =>
  // 12345678912345678912345678914
  s21_ldecimal num = {.bits = {0x71136A8F, 0xC96DD6FC, 0x8EE90FFC, 1},
                      .exp = 1};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)0x71B52442, (int)0xE0F1624C, (int)0x27E41B32}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(round2) {
  // arrange
  // 123456789123456789123456789125 =>
  // 12345678912345678912345678912
  s21_ldecimal num = {.bits = {0x71136A85, 0xC96DD6FC, 0x8EE90FFC, 1},
                      .exp = 1};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)0x71B52440, (int)0xE0F1624C, (int)0x27E41B32}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(round3) {
  // arrange
  // 12345678912345678912345678912501 =>
  // 12345678912345678912345678913
  s21_ldecimal num = {.bits = {0x2B959BF5, 0xAEE7FA9C, 0xD30A3EBE, 0x9B},
                      .exp = 3};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)0x71B52441, (int)0xE0F1624C, (int)0x27E41B32}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(round4) {
  // arrange
  // 199999999999999999999999999999999995 =>
  // 20000000000000000000000000000
  s21_ldecimal num = {.bits = {0xFFFFFFFB, 0x570F1FCF, 0xE58E9B04, 0x2684C2},
                      .exp = 7};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {0x20000000, 0x7C4A04C2, 0x409F9CBC}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(round5) {
  // arrange
  // 199999999999999999999999999985000001 =>
  // 19999999999999999999999999999
  s21_ldecimal num = {.bits = {0xFF1B1E41, 0x570F1FCF, 0xE58E9B04, 0x2684C2},
                      .exp = 7};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(maxnum) {
  // arrange
  // 79228162514264337593543950335
  s21_ldecimal num = {.bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX}, .exp = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {
      .bits = {(int)S21_MAX_INT, (int)S21_MAX_INT, (int)S21_MAX_INT}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(maxnum_plus) {
  // arrange
  // 79228162514264337593543950336
  s21_ldecimal num = {.bits = {0, 0, 0, 1}, .exp = 0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {0, 0, 0}};
  int need_result = S21_BIG_NUM_ERROR;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(minnum) {
  // arrange
  // 199999999999999999999999999985000001 =>
  // 19999999999999999999999999999
  s21_ldecimal num = {
      .bits = {UINT32_MAX, UINT32_MAX, UINT32_MAX}, .exp = 0, .sign = 1};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {.bits = {(int)S21_MAX_INT, (int)S21_MAX_INT,
                                          (int)S21_MAX_INT,
                                          S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(zero) {
  // arrange
  s21_ldecimal num = {0};
  s21_decimal resul_num = {0};

  s21_decimal need_result_num = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_ldec_to_dec(&num, &resul_num);

  // assert
  ck_assert_mem_eq(&resul_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST

START_TEST(null1) {
  // arrange
  s21_decimal num = {0};
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_ldec_to_dec(NULL, &num);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(null2) {
  // arrange
  s21_ldecimal num = {0};
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_ldec_to_dec(&num, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(null3) {
  // arrange
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_ldec_to_dec(NULL, NULL);

  // assert
  ck_assert_int_eq(result, need_result);
}
END_TEST

TCase *ldec_to_dec_tc(void) {
  TCase *tc = tcase_create("s21_ldec_to_dec");

  tcase_add_test(tc, t1);

  tcase_add_test(tc, error1);
  tcase_add_test(tc, error2);
  tcase_add_test(tc, error3);

  tcase_add_test(tc, overflow1);
  tcase_add_test(tc, overflow2);
  tcase_add_test(tc, overflow3);
  tcase_add_test(tc, overflow4);
  tcase_add_test(tc, overflow5);
  tcase_add_test(tc, overflow6);
  tcase_add_test(tc, overflow7);
  tcase_add_test(tc, overflow8);
  tcase_add_test(tc, overflow9);
  tcase_add_test(tc, overflow10);
  tcase_add_test(tc, overflow11);
  tcase_add_test(tc, overflow12);

  tcase_add_test(tc, overflow_to_zero);

  tcase_add_test(tc, round_no_need1);

  tcase_add_test(tc, round1);
  tcase_add_test(tc, round2);
  tcase_add_test(tc, round3);
  tcase_add_test(tc, round4);
  tcase_add_test(tc, round5);

  tcase_add_test(tc, maxnum);
  tcase_add_test(tc, maxnum_plus);
  tcase_add_test(tc, minnum);

  tcase_add_test(tc, null1);
  tcase_add_test(tc, null2);
  tcase_add_test(tc, null3);

  tcase_add_test(tc, zero);

  return tc;
}
