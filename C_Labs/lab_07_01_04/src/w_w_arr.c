/**
 * @file w_w_arr.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий функции работы с массивом
 * целых чисел
 * @version 0.1
 * @date 2022-09-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "../inc/tools.h"
#include "../inc/my_err.h"


int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL ||
    pb_src == pe_src)
        return INCORRECT_ARGS;

    const int *pcur = pb_src;

    double avg = get_avg(pcur, pe_src);

    int count = 0;


    pcur = pb_src;

    while (pcur != pe_src)
        if (*(pcur++) > avg)
            ++count;

    if (!count)
        return INCORRECT_ARR;

    *pb_dst = malloc(count * sizeof(int));
    *pe_dst = *pb_dst + count;

    while (pb_src != pe_src)
    {
        if (*pb_src > avg)
            *((*pb_dst)++) = *pb_src;
        ++pb_src;
    }

    *pb_dst -= count;                

    return SUCCESS;
}


void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
    char *p_end = (char *) base + nmemb * size;
    char temp;

    size_t i = 0;


    for (char *pi_cur = (char *) base; pi_cur != p_end; pi_cur += 2 * size, ++i)
    {
        size_t count = 0;


        if (nmemb <= i)
            break;

        for (size_t j = i; j < nmemb - (1 + i); ++j)
        {
            char *p1 = (char *) base + size * j;
            char *p2 = (char *) base + size * (j + 1);


            if (compar((void *) p1, (void *) p2) > 0)
            {
                ++count;
                for (size_t elem = 0; elem < size; ++elem)
                {
                    temp = *p1;
                    *(p1++) = *p2;
                    *(p2++) = temp;
                }
            }
        }
        if (!count)
            break;
        count = 0;

        for (size_t j = nmemb - i - 1; j > i; --j)
        {
            char *p1 = (char *) base + size * j;
            char *p2 = (char *) base + size * (j - 1);


            if (compar((void *) p1, (void *) p2) < 0)
            {
                ++count;
                for (size_t elem = 0; elem < size; ++elem)
                {
                    temp = *p1;
                    *(p1++) = *p2;
                    *(p2++) = temp;
                }
            }
        }
        if (!count)
            break;
    }
}