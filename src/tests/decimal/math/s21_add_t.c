#include <check.h>

#include "./../../../s21_decimal.h"
#include "./../../s21_tests.h"
#include "./../common/common_t.h"

START_TEST(t1) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  s21_decimal value_2 = {.bits = {1}};
  s21_decimal result_num = {0};

  s21_decimal need_result_num = {.bits = {2}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_num);

  // assert
  ck_assert_mem_eq(&result_num, &need_result_num, sizeof(s21_decimal));
  ck_assert_int_eq(result, need_result);
}
END_TEST
START_TEST(t2) {
  // arrange
  s21_decimal value_1 = {.bits = {123, 0, 0, S21_MAKE_EXP(3, 0)}};
  s21_decimal value_2 = {.bits = {321, 0, 0, S21_MAKE_EXP(1, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {32223, 0, 0, S21_MAKE_EXP(3, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t3) {
  // arrange
  s21_decimal value_1 = {.bits = {550, 0, 0, S21_MAKE_EXP(3, 0)}};
  s21_decimal value_2 = {.bits = {1255, 0, 0, S21_MAKE_EXP(2, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {131, 0, 0, S21_MAKE_EXP(1, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t4) {
  // arrange
  // 550000000000000000000000000000
  // 1255
  // 550000000000000000000000001255
  s21_decimal value_1 = {.bits = {550, 0, 0, S21_MAKE_EXP(3, 0)}};
  s21_decimal value_2 = {.bits = {1255, 0, 0, S21_MAKE_EXP(30, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0xFC00000D, (int)0x6EFAC14E,
                                            (int)0x11C57E4D,
                                            S21_MAKE_EXP(28, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t5) {
  // arrange
  // 0.0000000000000000000001000000
  // 0.00000000000000100000
  // 10000001
  s21_decimal value_1 = {
      .bits = {0x000F4240, 0x00000000, 0x00000000, S21_MAKE_EXP(28, 0)}};
  s21_decimal value_2 = {.bits = {0x000186A0, 0, 0, S21_MAKE_EXP(20, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x989681, 0, 0, S21_MAKE_EXP(22, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t6) {
  // arrange
  // 12721717217217217.21821901290
  // 0.000000212810
  // 12721717217217217.21821922571
  s21_decimal value_1 = {.bits = {0x2564B1EA, 0x3927F1F3, 0x041C50D7}};
  value_1.bits[3] = S21_MAKE_EXP(11, 0);
  s21_decimal value_2 = {.bits = {0x00033F4A}};
  value_2.bits[3] = S21_MAKE_EXP(12, 0);
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x2565050B, (int)0x3927F1F3, (int)0x41C50D7}};
  need_result_value.bits[3] = S21_MAKE_EXP(11, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t7) {
  // arrange
  // 0.99999
  // 0.00001
  // 1
  s21_decimal value_1 = {.bits = {0x0001869F}};
  value_1.bits[3] = S21_MAKE_EXP(5, 0);
  s21_decimal value_2 = {.bits = {1}};
  value_2.bits[3] = S21_MAKE_EXP(5, 0);
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {1}};
  need_result_value.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(t8) {
  // arrange
  // 79228162514264337593543950334
  // 0.51
  // 79228162514264337593543950335
  // 7922816251426433759354395033451

  s21_decimal value_1 = {.bits = {(int)0xFFFFFFFE, S21_MAX_INT, S21_MAX_INT}};
  value_1.bits[3] = S21_MAKE_EXP(0, 0);
  s21_decimal value_2 = {.bits = {51}};
  value_2.bits[3] = S21_MAKE_EXP(2, 0);
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  need_result_value.bits[3] = S21_MAKE_EXP(0, 0);
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(bits0) {
  // arrange
  s21_decimal value_1 = {.bits = {9999}};
  s21_decimal value_2 = {.bits = {9999}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {19998}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {S21_MAX_INT}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0xFFFFFFFE, (int)0x1}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits1_2) {
  // arrange
  // 561516841564 +
  // 651652156155 =
  // 1213168997719
  s21_decimal value_1 = {.bits = {(int)0xBD030A5C, (int)0x82}};
  s21_decimal value_2 = {.bits = {(int)0xB97ECAFB, (int)0x97}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0x7681D557, (int)0x11A}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {S21_MAX_INT, S21_MAX_INT}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {(int)0xFFFFFFFE, S21_MAX_INT, 0x1}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(bits2_2) {
  // arrange
  // 8789723481274892213434253245 +
  // 234897346278979798347234 =
  // 8789958378621171193232600479
  s21_decimal value_1 = {
      .bits = {(int)0xB308FFBD, (int)0xB27F44AC, (int)0x1C66B058}};
  s21_decimal value_2 = {
      .bits = {(int)0xC3B4ADE2, (int)0xCF873D40, (int)0x31BD}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0x76BDAD9F, (int)0x820681ED, (int)0x1C66E216}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(max_min1) {
  // arrange
  // 79228162514264337593543950335 +
  // 0.0000000000000000000000000001
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {1, 0, 0, S21_MAKE_EXP(28, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(max_min2) {
  // arrange
  // 79228162514264337593543950335 +
  // 0.4
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {4, 0, 0, S21_MAKE_EXP(1, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(max_min3) {
  // arrange
  // 79228162514264337593543950335 +
  // 0.4
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {499999999, 0, 0, S21_MAKE_EXP(9, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(sign1) {
  // arrange
  // 10 + -5 = 5
  s21_decimal value_1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 0)}};
  s21_decimal value_2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign2) {
  // arrange
  // 5 + -10 = -5
  s21_decimal value_1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 0)}};
  s21_decimal value_2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign3) {
  // arrange
  // -10 + 5 = -5
  s21_decimal value_1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {5}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign4) {
  // arrange
  // -5 + 10 = 5
  s21_decimal value_1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 0)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign5) {
  // arrange
  // -5 + -10 = -15
  s21_decimal value_1 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {15, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign6) {
  // arrange
  // -10 + -10 = -20
  s21_decimal value_1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {20, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign7) {
  // arrange
  // -10 + -5 = - 15
  s21_decimal value_1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {5, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {15, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign8) {
  // arrange
  // -10 + 10 = 0
  s21_decimal value_1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {10}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(sign9) {
  // arrange
  // 10 + -10 = 0
  s21_decimal value_1 = {.bits = {10}};
  s21_decimal value_2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(add_with_zero1) {
  // arrange
  s21_decimal value_1 = {.bits = {0}};
  s21_decimal value_2 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(add_with_zero2) {
  // arrange
  s21_decimal value_1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {0}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(add_with_zero3) {
  // arrange
  s21_decimal value_1 = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {10, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(add_with_zero4) {
  // arrange
  s21_decimal value_1 = {.bits = {10}};
  s21_decimal value_2 = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {10}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(big_exp_not_overflow) {
  // arrange
  s21_decimal value_1 = {.bits = {10, 0, 0, S21_MAKE_EXP(100, 0)}};
  s21_decimal value_2 = {.bits = {12, 0, 0, S21_MAKE_EXP(100, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(error1) {
  // arrange
  // 79228162514264337593543950335 +
  // 0.500001
  s21_decimal value_1 = {
      .bits = {(int)S21_MAX_INT, (int)S21_MAX_INT, (int)S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {500001, 0, 0, S21_MAKE_EXP(6, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = 1;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(error2) {
  // arrange
  // 79228162514264337593543950335 +
  // 0.6
  s21_decimal value_1 = {
      .bits = {(int)S21_MAX_INT, (int)S21_MAX_INT, (int)S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {6, 0, 0, S21_MAKE_EXP(1, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = 1;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(error3) {
  // arrange
  // 79228162514264337593543950335 +
  // 0.500001
  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {500001, 0, 0, S21_MAKE_EXP(6, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = 2;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(error4) {
  // arrange
  // 79228162514264337593543950335 +
  // 0.6
  s21_decimal value_1 = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAKE_EXP(0, 1)}};
  s21_decimal value_2 = {.bits = {6, 0, 0, S21_MAKE_EXP(1, 1)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {.bits = {0, 0, 0, S21_MAKE_EXP(0, 1)}};
  int need_result = 2;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(error5) {
  // arrange
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {
      .bits = {(int)0xFFFFFFFE, (int)0xFFFFFFFF, (int)0xFFFFFFFF}};
  int need_result = 1;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(error6) {
  // arrange
  // 79228162514264337593543950335 +
  // 0.5
  s21_decimal value_1 = {.bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};
  s21_decimal value_2 = {.bits = {5, 0, 0, S21_MAKE_EXP(1, 0)}};
  s21_decimal result_value = {0};

  s21_decimal need_result_value = {0};
  int need_result = 1;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(null) {
  // arrange
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};

  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_add(value_1, value_2, NULL);

  // assert
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(result_not_init1) {
  // arrange
  // 8789723481274892213434253245 +
  // 234897346278979798347234 =
  // 8789958378621171193232600479
  s21_decimal value_1 = {
      .bits = {(int)0xB308FFBD, (int)0xB27F44AC, (int)0x1C66B058}};
  s21_decimal value_2 = {
      .bits = {(int)0xC3B4ADE2, (int)0xCF873D40, (int)0x31BD}};
  s21_decimal result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_value = {
      .bits = {(int)0x76BDAD9F, (int)0x820681ED, (int)0x1C66E216}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(result_not_init2) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  s21_decimal value_2 = {.bits = {1}};
  s21_decimal result_value = {
      .bits = {S21_MAX_INT, S21_MAX_INT, S21_MAX_INT, S21_MAX_INT}};

  s21_decimal need_result_value = {.bits = {2}};
  int need_result = S21_RESULT_OK;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

START_TEST(not_correct_num1) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  value_1.bits[3] = 1;
  s21_decimal value_2 = {.bits = {1}};
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST
START_TEST(not_correct_num2) {
  // arrange
  s21_decimal value_1 = {.bits = {1}};
  s21_decimal value_2 = {.bits = {1}};
  value_2.bits[3] = 1;
  s21_decimal result_value;

  s21_decimal need_result_value = {0};
  int need_result = S21_RESULT_ERROR;

  // act
  int result = s21_add(value_1, value_2, &result_value);

  // assert
  ck_assert_mem_eq(&result_value, &need_result_value, sizeof(s21_decimal));
  ck_assert_uint_eq(result, need_result);
}
END_TEST

Suite *add_sc(void) {
  Suite *suite = suite_create("s21_add");

  TCase *t_tc = tcase_create("s21_add");
  tcase_add_test(t_tc, t1);
  tcase_add_test(t_tc, t2);
  tcase_add_test(t_tc, t3);
  tcase_add_test(t_tc, t4);
  tcase_add_test(t_tc, t5);
  tcase_add_test(t_tc, t6);
  tcase_add_test(t_tc, t7);
  tcase_add_test(t_tc, t8);
  tcase_add_test(t_tc, big_exp_not_overflow);
  suite_add_tcase(suite, t_tc);

  TCase *bits_tc = tcase_create("s21_add bits");
  tcase_add_test(bits_tc, bits0);
  tcase_add_test(bits_tc, bits1);
  tcase_add_test(bits_tc, bits1_2);
  tcase_add_test(bits_tc, bits2);
  tcase_add_test(bits_tc, bits2_2);
  suite_add_tcase(suite, bits_tc);

  TCase *maxmin_tc = tcase_create("s21_add maxmin");
  tcase_add_test(maxmin_tc, max_min1);
  tcase_add_test(maxmin_tc, max_min2);
  tcase_add_test(maxmin_tc, max_min3);
  suite_add_tcase(suite, maxmin_tc);

  TCase *error_tc = tcase_create("s21_add error");
  tcase_add_test(error_tc, error1);
  tcase_add_test(error_tc, error2);
  tcase_add_test(error_tc, error3);
  tcase_add_test(error_tc, error4);
  tcase_add_test(error_tc, error5);
  tcase_add_test(error_tc, error6);
  tcase_add_test(error_tc, null);
  tcase_add_test(error_tc, not_correct_num1);
  tcase_add_test(error_tc, not_correct_num2);
  suite_add_tcase(suite, error_tc);

  TCase *signs_tc = tcase_create("s21_add signs");
  tcase_add_test(signs_tc, sign1);
  tcase_add_test(signs_tc, sign2);
  tcase_add_test(signs_tc, sign3);
  tcase_add_test(signs_tc, sign4);
  tcase_add_test(signs_tc, sign5);
  tcase_add_test(signs_tc, sign6);
  tcase_add_test(signs_tc, sign7);
  tcase_add_test(signs_tc, sign8);
  tcase_add_test(signs_tc, sign9);
  suite_add_tcase(suite, signs_tc);

  TCase *zero_tc = tcase_create("s21_add with zero");
  tcase_add_test(zero_tc, add_with_zero1);
  tcase_add_test(zero_tc, add_with_zero2);
  tcase_add_test(zero_tc, add_with_zero3);
  tcase_add_test(zero_tc, add_with_zero4);
  suite_add_tcase(suite, zero_tc);

  TCase *not_init_tc = tcase_create("s21_add result not init");
  tcase_add_test(not_init_tc, result_not_init1);
  tcase_add_test(not_init_tc, result_not_init2);
  suite_add_tcase(suite, not_init_tc);

  return suite;
}

MAKE_TEST(add)
