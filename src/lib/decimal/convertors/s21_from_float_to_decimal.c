#include "./../../common/s21_parse_float.h"
#include "./../common/s21_dec_common.h"

#define NEED_DIGITS 28

static void convert_num(s21_fparse_t *src, s21_decimal *dst);
static bool out_of_range(float src);

/**
 * @brief Конвертирует float в decimal. Берет первые 7 значащих цифр. В случае
 * если остались еще цифры, они отсекаются, а число округляется банковским
 * округлением.
 *
 * @return
 * 0 - ok
 * 1 - ошибка конвертации (не входит целая часть, или в дробной части очень
 * много ведущих нулей).
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (!dst) return S21_CONVERT_ERROR;
  int result = S21_RESULT_OK;
  s21_clear_num(dst);

  if (out_of_range(src)) {
    result = S21_CONVERT_ERROR;
  } else {
    s21_fparse_t fp = s21_parse_float(src, NEED_DIGITS);
    if (fp.error)
      result = S21_CONVERT_ERROR;
    else
      convert_num(&fp, dst);
  }

  return result;
}

/**
 * @brief Конвертируем распарсенное число в dst.
 *
 * Если экспонента больше или равно 0 - это значит что в числе нет дробной
 * части, число целое. В таком случае домножаем его на 10 (сдвигаем влево),
 * столько раз, сколько записано в экспоненте. А экспоненту зануляем. Экспонента
 * с минусом, указывает сколько раз нужно поделить число на 10, чтобы получить
 * итоговое. При этом экспоненту делаем положительной и записываем в результат.
 */
static void convert_num(s21_fparse_t *src, s21_decimal *dst) {
  dst->bits[0] = (int)src->num;

  if (src->exp >= 0) {
    for (int i = 0; i < src->exp; i++) {
      s21_decimal_shift_left(dst);
    }
    src->exp = 0;
  } else {
    src->exp = -src->exp;
  }

  s21_decimal_set_exp(dst, src->exp);
  s21_decimal_set_sign(dst, src->sign);
}

/**
 * @brief Проверяем что число не выходит за рамки, если число меньше минимально
 * допустимого, и больше максимально, то это ошибка.
 */
static bool out_of_range(float src) {
  bool result = false;
  if (src < 0.0) src = -src;
  if (src > 0.0 && src < S21_MIN_DECIMAL) result = true;
  if (src > S21_MAX_DECIMAL) result = true;
  return result;
}
