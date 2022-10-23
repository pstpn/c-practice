#include <stdio.h>
#include <stdlib.h>

#include "../inc/my_err.h"


double **allocate_matrix(int n, int m)
{
    double **ptrs, *data;


    ptrs = calloc(n, sizeof(double*));
    if (!ptrs)
        return NULL;

    data = calloc(n * m, sizeof(double));

    if (!data)
    {
        free(ptrs);
        return NULL;
    }

    for (int i = 0; i < n; i++)
        ptrs[i] = data + i * m;

    return ptrs;
}


int filling_matrix(FILE *f, double **ptrs, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            if (fscanf(f, "%lf", &(ptrs[i][j])) != 1)
                return ERR_READING;
    }
    
    if ((feof(f) == 0 && fgetc(f) != '\n'))
        return ERR_READING;

    return SUCCESS;
}


void free_matrix(double **data, int n)
{
    for (int i = 0; i < n; i++)
        free(data[i]);

    free(data);
}