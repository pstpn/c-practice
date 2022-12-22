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

#include "tools.h"
#include "my_err.h"


int get_count(FILE *f, int *count)
{
    int cur_num;


    while (feof(f) == 0)
    {
        if (fscanf(f, "%d", &cur_num) != 1)
            return INCORRECT_FILE;
        ++(*count);
    }

    return SUCCESS;
}


int compare_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}