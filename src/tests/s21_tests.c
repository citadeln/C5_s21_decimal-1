#include "s21_tests.h"

#include <stdio.h>

static void print_head(void);

int main(void) {
  print_head();

  RUN_TEST(common);
  RUN_TEST(ldecimal);

  // Math
  PRINT_MSG("MATH");
  RUN_TEST(add);
  RUN_TEST(sub);
  RUN_TEST(mul);
  RUN_TEST(div);

  // Compare
  PRINT_MSG("COMPARE");
  RUN_TEST(is_less);
  RUN_TEST(is_less_or_equal);
  RUN_TEST(is_greater);
  RUN_TEST(is_greater_or_equal);
  RUN_TEST(is_equal);
  RUN_TEST(is_not_equal);

  // Convertors
  PRINT_MSG("CONVERTORS");
  RUN_TEST(from_int_to_decimal);
  RUN_TEST(from_float_to_decimal);
  RUN_TEST(from_decimal_to_int);
  RUN_TEST(from_decimal_to_float);

  // Other
  PRINT_MSG("OTHER");
  RUN_TEST(floor);
  RUN_TEST(round);
  RUN_TEST(truncate);
  RUN_TEST(negate);

  printf("\n");
  return 0;
}

static void print_head(void) {
  printf(
      "\033[34m****************************************************************"
      "*******"
      "\n\033["
      "39m");
  printf(
      "\033[34m***\033[39m Тесты Decimal.h \033[34m***\033[39m "
      "\033[32m monroebu / moryamel / tilmapat / typewria \033[39m "
      "\033[34m***\033[39m\n");
  printf(
      "\033[34m****************************************************************"
      "*******"
      "\n\n\033["
      "39m");
}
