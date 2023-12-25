#include <stdint.h>

#include "./../../ldecimal/s21_ldecimal.h"
#include "./../common/s21_dec_common.h"

/**
 * @brief Структура для хранения аргументов между функциями.
 */
typedef struct {
  s21_ldecimal *src;
  long double remain_part;
  long double int_part;
} args;

static void get_remain_part(args *ar);
static void get_int_part(args *ar);

/**
 * @brief Конвертация из decimal в float. Сохраняет только первые 7 значащих
 * цифр. Если цифры остаются производит банковское округление.
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (!dst) return S21_CONVERT_ERROR;
  int res = S21_RESULT_OK;
  *dst = 0.0F;

  if (s21_decimal_check_correct(&src)) {
    s21_ldecimal ldec = s21_dec_to_ldec(&src);
    uint32_t sign = ldec.sign;
    args ar = {.src = &ldec};

    get_remain_part(&ar);
    get_int_part(&ar);

    *dst = (float)(ar.int_part + ar.remain_part);
    if (sign == S21_SIGN_MINUS) *dst = -(*dst);
  } else {
    res = S21_CONVERT_ERROR;
  }

  return res;
}

static void get_remain_part(args *ar) {
  ar->remain_part = 0.0L;
  int exp = (int)ar->src->exp;
  for (int i = 0; i < exp; i++) {
    long double dig = (long double)s21_ldec_shift_right(ar->src);
    ar->remain_part += dig;
    ar->remain_part /= 10;
  }
}

static void get_int_part(args *ar) {
  long double scale = 1;
  while (!s21_ldec_is_zero(ar->src)) {
    long double dig = (long double)s21_ldec_shift_right(ar->src);
    dig *= scale;
    ar->int_part += dig;
    scale *= 10;
  }
}
