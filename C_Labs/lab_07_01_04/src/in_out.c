/**
 * @file in_out.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий функции ввода/вывода
 * @version 0.1
 * @date 2022-09-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#include "../inc/in_out.h"


void array_filling(FILE *f, int *pcur, int *pend)
{
    while (pcur != pend)
        fscanf(f, "%d", pcur++);
}


void writing_to_file(FILE *f, int *pcur, int *pend)
{
    while (pcur != pend)
        fprintf(f, "%d ", *(pcur++));
}