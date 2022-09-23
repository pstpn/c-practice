/**
 * @file main.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий главную функцию проекта
 * @version 0.1
 * @date 2022-09-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "w_w_arr.h"
#include "in_out.h"
#include "tools.h"
#include "my_err.h"
#include "my_def.h"


int main(int argc, char **argv)
{
    if (argc < MIN_ARGS_COUNT || argc > MAX_ARGS_COUNT)
        return INCORRECT_ARGS_COUNT;

    FILE *f = fopen(*(++argv), "r");

    int count = 0;


    if (f == NULL)
        return INCORRECT_FILENAME;

    if (get_count(f, &count) || !count)
        return INCORRECT_FILE;
    rewind(f);

    int *arr_ptr = malloc(count * sizeof(int)),
    *p_end = arr_ptr + count, *cur_ptr = arr_ptr;


    if (arr_ptr == NULL)
        return MEMORY_ERROR;

    array_filling(f, cur_ptr, p_end);

    fclose(f);

    FILE *g = fopen(*(++argv), "w");


    if (argc == MAX_ARGS_COUNT)
    {
        if (**(++argv) != 'f' || *(++(*argv)) != '\0')
            return INCORRECT_ARGS;
        
        int *pcur_new = NULL, *pend_new = NULL;


        cur_ptr = arr_ptr;
        if (key(cur_ptr, p_end, &pcur_new, &pend_new))
            return INCORRECT_ARR;

        cur_ptr = pcur_new;
        mysort(cur_ptr, pend_new - cur_ptr, sizeof(int), compare_int);

        cur_ptr = pcur_new;
        writing_to_file(g, cur_ptr, pend_new);

        free(pcur_new);
    }

    if (argc != MAX_ARGS_COUNT)
    {
        cur_ptr = arr_ptr;
        mysort(cur_ptr, count, sizeof(int), compare_int);

        cur_ptr = arr_ptr;
        writing_to_file(g, cur_ptr, p_end);
    }

    free(arr_ptr);
    fclose(g);

    return SUCCESS;
}