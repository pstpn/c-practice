/**
 * @file my_def.h
 * @author Stepan Postnov ICS7-31B
 * @brief Библиотека, содержащая необходимые для 
 * работы программы константы
 * @version 0.1
 * @date 2022-09-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ___MY_DEF___
#define ___MY_DEF___

/**
 * @brief Максимальная длина названия фильма и его автора
 * 
 */
#define MAX_LENGTH 25
/**
 * @brief Максимальное кол-во фильмов в файле
 * 
 */
#define MAX_FILMS_COUNT 15
/**
 * @brief Максимальная длина поля для анализа
 * 
 */
#define MAX_FIELD_LENGTH 5
/**
 * @brief Максимальная длина года
 * 
 */
#define MAX_YEAR_LEN 6
/**
 * @brief Кол-во полей для анализа
 * 
 */
#define NUMBER_OF_FIELDS 3

/**
 * @brief Истина
 * 
 */
#define TRUE 1
/**
 * @brief Ложь
 * 
 */
#define FALSE 0
/**
 * @brief Код возврата из функции сравнения строк 
 * при эквивалентности str_1 и str_2
 * 
 */
#define EQUIV 0
/**
 * @brief Код возврата из функции сравнения строк, 
 * если str_1 должна стоять дальше str_2
 * 
 */
#define MORE 1
/**
 * @brief Код возврата из функции сравнения строк, 
 * если str_1 должна ближе дальше str_2
 * 
 */
#define LESS -1
/**
 * @brief Код, при котором необходимое поле не найдено
 * 
 */
#define NOT_FOUND -1

#endif //___MY_DEF___