#ifndef COMMON_T_H
#define COMMON_T_H

#define S21_MAX_INT ((int)0xFFFFFFFF)
#define S21_MAKE_EXP(exp, sign) \
  ((int)(((unsigned int)(sign) << 31U) | ((unsigned int)(exp) << 16U)))

#endif
