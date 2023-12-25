#ifndef S21_LDEC_COMMON_H
#define S21_LDEC_COMMON_H

#include "s21_ldec_type.h"

typedef enum {
  nrIsZero,
  nrOk,
} norm_res;

norm_res s21_ldec_normalize(s21_ldecimal *num);

#endif
