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

#include "../inc/tools.h"
#include "../inc/my_err.h"


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


double get_avg(const int *pcur, const int *pend)
{
    int count = 0, summ = 0;


    while (pcur != pend)
    {
        summ += *(pcur++);
        ++count;
    }

    return (double) summ / count;
}


int compare_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}