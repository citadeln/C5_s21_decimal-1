#include <check.h>

#include "./../../s21_tests.h"

TCase *get_sign_tc(void);
TCase *set_sign_tc(void);
TCase *get_exp_tc(void);
TCase *set_exp_tc(void);

TCase *dec_shift_left_tc(void);
TCase *dec_shift_right_tc(void);

TCase *check_correct_tc(void);
TCase *parse_float_tc(void);

int s21_common_t(void) {
  Suite *common_sc = suite_create("common");

  // common
  suite_add_tcase(common_sc, get_sign_tc());
  suite_add_tcase(common_sc, set_sign_tc());
  suite_add_tcase(common_sc, get_exp_tc());
  suite_add_tcase(common_sc, set_exp_tc());

  suite_add_tcase(common_sc, dec_shift_left_tc());
  suite_add_tcase(common_sc, dec_shift_right_tc());

  suite_add_tcase(common_sc, check_correct_tc());
  suite_add_tcase(common_sc, parse_float_tc());

  MAKE_SRUNNER(common_sc)
}
