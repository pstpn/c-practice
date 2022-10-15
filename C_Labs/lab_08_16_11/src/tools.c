#include <stdio.h>

#include "../inc/my_err.h"


int get_size(FILE *f, int *n, int *m)
{
    char buf;


    if (fscanf(f, "%d%d%c", n, m, &buf) != 3 ||
        buf != '\n' || *n < 1 || *m < 1)
        return ERR_GET_SIZE;

    return SUCCESS;
}


void addition_or_sub_strs(double str_1[], double str_2[], int n, int sub)
{
    for (int i = 0; i < n; ++i)
        str_1[i] += (sub) ? -str_2[i] : str_2[i];
}


int get_nonzero(double **mtrx, int col, int a, int b)
{
    for (;a < b; ++a)
        if (!(mtrx[a][col] >= 0 && mtrx[a][col] <= 0))
            return a;
    
    return -1;
}


void div_str(double str[], int n, double div)
{
    for (int i = 0; i < n; ++i)
        str[i] /= div;
}