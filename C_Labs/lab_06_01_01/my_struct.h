/**
 * @file my_struct.h
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий собственный тип со структурой
 * @version 0.1
 * @date 2022-09-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __MY_STRUCT__
#define __MY_STRUCT__

#include "my_def.h"

/**
 * @brief Тип, содержащий структуру для работы
 * 
 */
typedef struct film
{
    char title[MAX_LENGTH + 1];
    char name[MAX_LENGTH + 1];
    int year;
} film_t;

#endif // __MY_STRUCT__