#include <stdio.h>

#include "my_err.h"


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


int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, int *count)
{
    if (pb_src == NULL || pe_src == NULL ||
        pb_src >= pe_src || pb_src == *pb_dst ||
        pe_src == *pb_dst || pb_src == *pe_dst ||
        pe_src == *pe_dst)
        return INCORRECT_ARGS;

    const int *pcur = pb_src;

    double avg = get_avg(pcur, pe_src);


    pcur = pb_src;

    if (!(*pb_dst))
    {
        while (pcur != pe_src)
            if (*(pcur++) > avg)
                ++(*count);
        return SUCCESS;
    }
        
    *pe_dst = *pb_dst + (*count);

    while (pb_src != pe_src)
    {
        if (*pb_src > avg)
            *((*pb_dst)++) = *pb_src;
        ++pb_src;
    }

    *pb_dst -= (*count);                

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