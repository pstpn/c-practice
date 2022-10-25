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