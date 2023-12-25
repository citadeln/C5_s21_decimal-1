#ifndef S21_PARSE_FLOAT_H
#define S21_PARSE_FLOAT_H

/**
 * @brief Структура для хранения распарсеного числа.
 * @param Num содержит 7 значащих цифр, с примененным округлением
 * @param Exp содержит 10ную экспоненту, от -28 до +28
 * @param cnt_digs количество значащих цифр в числе, не включая ноли по краям
 * @param error ошибка парсинга, например число слишком маленькое (< 1e-28), или
 * большое
 */
typedef struct {
  int sign;
  int exp;
  int num;

  int cnt_digs;

  int error;
} s21_fparse_t;

s21_fparse_t s21_parse_float(float num, int precision);

#endif
