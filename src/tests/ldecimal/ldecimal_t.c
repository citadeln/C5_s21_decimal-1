#include <check.h>

#include "./../s21_tests.h"

// Math
TCase *add_tc(void);
TCase *sub_tc(void);
TCase *mul_tc(void);
TCase *div_tc(void);

// Convertors
TCase *dec_to_ldec_tc(void);
TCase *ldec_to_dec_tc(void);

// Compare
TCase *is_zero_tc(void);
TCase *ldec_is_greater_tc(void);
TCase *ldec_is_greater_or_equal_tc(void);
TCase *ldec_is_equal_tc(void);

// Common
TCase *make_exp_equal_tc(void);
TCase *normalize_tc(void);
TCase *overflow_handler_tc(void);
TCase *shift_left_tc(void);
TCase *shift_right_tc(void);

// Private
TCase *sub_raw_tc(void);
TCase *add_raw_tc(void);
TCase *is_greater_raw_tc(void);
TCase *ldec_convert_prepare_tc(void);
TCase *dec_has_overflow_tc(void);

int s21_ldecimal_t(void) {
  Suite *ldecimal_sc = suite_create("long decimal");

  // Math
  suite_add_tcase(ldecimal_sc, add_tc());
  suite_add_tcase(ldecimal_sc, sub_tc());
  suite_add_tcase(ldecimal_sc, mul_tc());
  suite_add_tcase(ldecimal_sc, div_tc());

  // Convertors
  suite_add_tcase(ldecimal_sc, dec_to_ldec_tc());
  suite_add_tcase(ldecimal_sc, ldec_to_dec_tc());

  // Compare
  suite_add_tcase(ldecimal_sc, is_zero_tc());
  suite_add_tcase(ldecimal_sc, ldec_is_greater_tc());
  suite_add_tcase(ldecimal_sc, ldec_is_greater_or_equal_tc());
  suite_add_tcase(ldecimal_sc, ldec_is_equal_tc());

  // Common
  suite_add_tcase(ldecimal_sc, make_exp_equal_tc());
  suite_add_tcase(ldecimal_sc, normalize_tc());
  suite_add_tcase(ldecimal_sc, overflow_handler_tc());
  suite_add_tcase(ldecimal_sc, shift_left_tc());
  suite_add_tcase(ldecimal_sc, shift_right_tc());

  // Private
  suite_add_tcase(ldecimal_sc, sub_raw_tc());
  suite_add_tcase(ldecimal_sc, add_raw_tc());
  suite_add_tcase(ldecimal_sc, is_greater_raw_tc());
  suite_add_tcase(ldecimal_sc, ldec_convert_prepare_tc());
  suite_add_tcase(ldecimal_sc, dec_has_overflow_tc());

  MAKE_SRUNNER(ldecimal_sc)
}
