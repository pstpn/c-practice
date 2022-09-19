/**
 * @file tools.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий вспомогательные функции
 * @version 0.1
 * @date 2022-09-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string.h>
#include <ctype.h>

#include "my_def.h"
#include "my_err.h"


/**
 * @brief Функция, проверяющая корректность введенного поля
 * 
 * @param [in] field Поле для проверки
 * @param [in] correct_fields Корректные поля
 * @return int 
 */
int does_the_field_exist(char *field, char correct_fields[NUMBER_OF_FIELDS][MAX_FIELD_LENGTH + 1])
{
    char sort_field;


    for (int i = 0; i < NUMBER_OF_FIELDS; ++i)
        if (!strcmp(field, correct_fields[i]))
        {
            if (i == 0)
                sort_field = 't';
            else if (i == 1)
                sort_field = 'n';
            else
                sort_field = 'y';

            return sort_field;
        }

    return FALSE;
}


/**
 * @brief Функция сравнения строк по алфавиту
 * 
 * @param [in] str_1 Первая строка
 * @param [in] str_2 Вторая строка
 * @return int 
 */
int strcmp_al(const char *str_1, const char *str_2)
{
    while (*str_1 != '\0' && *str_2 != '\0')
    {
        if (tolower(*str_1) < tolower(*str_2))
            return LESS;
        else if (tolower(*str_1) > tolower(*str_2))
            return MORE;

        ++str_1, ++str_2;
    }

    if (*str_1 != '\0')
        return MORE;

    if (*str_2 != '\0')
        return LESS;

    return EQUIV;
}


/**
 * @brief Функция, проверяющая строку на то,
 * состоит ли она из цифр или нет
 * 
 * @param[in] str Строка для проверки
 * @return int 
 */
int is_correct_digit(const char *str)
{
    if (*str == '-' && isdigit(*(str + 1)))
        str++;

    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
            return FALSE;

        str++;
    }

    return TRUE;
}


/**
 * @brief Функция проверки ключа поиска на корректность
 * 
 * @param [in] key Ключ для проверки
 * @return int 
 */
int is_correct_key(char *key)
{
    int i = 0;


    while (i < MAX_LENGTH && *key != 0)
        ++key, ++i;

    if (i == MAX_LENGTH && *key != 0)
        return FALSE;

    return TRUE;
}


/**
 * @brief Функция получения ключа поиска,
 * состоящего из нескольких слов
 * 
 * @param [out] param 
 * @param [in] ptr 
 * @return int 
 */
int get_param(char *param, char *ptr)
{
    int i = 0;


    while (*ptr != '\"' && i < MAX_LENGTH)
        param[i++] = *(ptr++);

    if (*ptr != '\"')
        return INCORRECT_ARGS;
    
    return SUCCESS;
}