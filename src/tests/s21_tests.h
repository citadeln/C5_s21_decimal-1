#ifndef S21_TESTS_H
#define S21_TESTS_H

#define PRINT_MSG(msg) \
  (printf("\n\033[32m%s\033[39m\n\n\033[34m-------\n\033[39m", msg))

#define RUN_TEST(TEST_NAME) \
  s21_##TEST_NAME##_t();    \
  printf("\033[34m-------\n\033[39m");

#define MAKE_SRUNNER(SUITE_NAME)                          \
  SRunner *suite_runner = srunner_create(SUITE_NAME);     \
  srunner_set_fork_status(suite_runner, CK_NOFORK);       \
  srunner_run_all(suite_runner, CK_NORMAL);               \
  int failed_count = srunner_ntests_failed(suite_runner); \
  srunner_free(suite_runner);                             \
  return failed_count;

#define MAKE_TEST(TEST_NAME)         \
  int s21_##TEST_NAME##_t(void) {    \
    Suite *suite = TEST_NAME##_sc(); \
    MAKE_SRUNNER(suite)              \
  }

#define PROTOTYPE(TEST_NAME) int s21_##TEST_NAME##_t(void);

int s21_ldecimal_t(void);
int s21_common_t(void);

// Math
PROTOTYPE(add)
PROTOTYPE(sub)
PROTOTYPE(mul)
PROTOTYPE(div)

// Compare
PROTOTYPE(is_less)
PROTOTYPE(is_less_or_equal)
PROTOTYPE(is_greater)
PROTOTYPE(is_greater_or_equal)
PROTOTYPE(is_equal)
PROTOTYPE(is_not_equal)

// Convertors
PROTOTYPE(from_int_to_decimal)
PROTOTYPE(from_float_to_decimal)
PROTOTYPE(from_decimal_to_int)
PROTOTYPE(from_decimal_to_float)

// Other
PROTOTYPE(floor)
PROTOTYPE(round)
PROTOTYPE(truncate)
PROTOTYPE(negate)

#endif
