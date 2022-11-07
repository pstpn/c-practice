/**
 * @file tools.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий вспомогательные функции
 * @version 0.1
 * @date 2022-09-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../inc/w_w_movie.h"
#include "../inc/my_types.h"
#include "../inc/my_def.h"


int does_the_field_exist(char *field, char correct_fields[NUMBER_OF_FIELDS][MAX_FIELD_LENGTH + 1])
{
    char sort_field;


    for (int i = 0; i < NUMBER_OF_FIELDS; ++i)
        if (!strcmp(field, correct_fields[i]))
        {
            if (!i)
                sort_field = 't';
            else if (i == 1)
                sort_field = 'n';
            else
                sort_field = 'y';

            return sort_field;
        }

    return FALSE;
}


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


int movie_cpy(movie_t *dst, movie_t *src)
{
    return init_movie(dst, src->title, src->name, src->year);
}