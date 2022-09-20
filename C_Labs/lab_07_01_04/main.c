#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define INCORRECT_ARGS_COUNT 1
#define INCORRECT_FILENAME 2
#define INCORRECT_FILE 3
#define MEMORY_ERROR 4
#define INCORRECT_ARGS 5
#define INCORRECT_ARR 6

#define MAX_ARGS_COUNT 4
#define MIN_ARGS_COUNT 3


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


void array_filling(FILE *f, int *pcur, int *pend)
{
    while (pcur != pend)
        fscanf(f, "%d", pcur++);
}


double get_avg(const int *pcur, const int *pend)
{
    int count = 0, summ = 0;


    while (pcur != pend)
    {
        summ += *(pcur++);
        ++count;
    }

    return summ / count;
}


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


int compare_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}


void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
    char *p_end = (char *) base + nmemb * size;
    char temp;

    size_t i = 0;


    for (char *pi_cur = (char *) base; pi_cur != p_end; pi_cur += 2 * size, ++i)
    {
        if (nmemb <= i)
            break;

        for (size_t j = i; j < nmemb - (1 + i); ++j)
        {
            char *p1 = (char *) base + size * j;
            char *p2 = (char *) base + size * (j + 1);


            if (compar((void *) p1, (void *) p2) > 0)
            {
                for (size_t elem = 0; elem < size; ++elem)
                {
                    temp = *p1;
                    *(p1++) = *p2;
                    *(p2++) = temp;
                }
            }
        }
        for (size_t j = nmemb - i - 1; j > i; --j)
        {
            char *p1 = (char *) base + size * j;
            char *p2 = (char *) base + size * (j - 1);


            if (compar((void *) p1, (void *) p2) < 0)
            {
                for (size_t elem = 0; elem < size; ++elem)
                {
                    temp = *p1;
                    *(p1++) = *p2;
                    *(p2++) = temp;
                }
            }
        }
    }
}



void writing_to_file(FILE *f, int *pcur, int *pend)
{
    while (pcur != pend)
        fprintf(f, "%d ", *(pcur++));
}


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
