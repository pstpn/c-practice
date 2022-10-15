#include <stdio.h>
#include <stdlib.h>

#include "../inc/my_err.h"
#include "../inc/my_def.h"
#include "../inc/tools.h"


double** allocate_matrix(int n, int m)
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
    char buf = '\0';


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            if (fscanf(f, "%lf", &(ptrs[i][j])) != 1)
                return ERR_READING;
            
        fscanf(f, "%c", &buf);
        if (buf != '\n' && i != n - 1)
            return ERR_READING;
    }
    
    if (feof(f) == 0)
        return ERR_READING;

    return SUCCESS;
}


void matrix_addition_and_write(FILE *f, double **mtrx_1, double **mtrx_2, int n, int m)
{
    fprintf(f, "%d %d\n", n, m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            fprintf(f, "%lf%s", mtrx_1[i][j] + mtrx_2[i][j],
            (j == m - 1) ? "\0" : " ");
        
        fprintf(f, "%s", (i == n - 1) ? "\0" : "\n");
    }
}


void matrix_product_and_write(FILE *f, double **mtrx_1, double **mtrx_2, 
int n_2_m_1, int n_1, int m_2)
{
    double buf;


    fprintf(f, "%d %d\n", n_1, m_2);

    for (int i = 0; i < n_1; ++i)
    {
        for (int j = 0; j < m_2; ++j)
        {
            buf = 0;

            for (int k = 0; k < n_2_m_1; ++k)
                buf += mtrx_1[i][k] * mtrx_2[k][j];

            fprintf(f, "%lf%s", buf,
            (j == m_2 - 1) ? "\0" : " ");
        }

        fprintf(f, "%s", (i == n_1 - 1) ? "\0" : "\n");
    }
}


void get_det_and_write(FILE *f, double **mtrx, int n)
{
    double det = 1;


    for (int k = 0; k < n; ++k)
    {
        if (mtrx[k][k] >= 0 && mtrx[k][k] <= 0)
        {
            int ind = get_nonzero(mtrx, k, k + 1, n);


            if (ind < 0 || (k && get_nonzero(mtrx, k - 1, k, n) < 0))
            {
                det = 0;
                break;
            }
            
            addition_or_sub_strs(mtrx[k], mtrx[ind], n, FALSE);
        }

        for (int i = k + 1; i < n; ++i)
            if (!(mtrx[i][k] >= 0 && mtrx[i][k] <= 0))
            {
                div_str(mtrx[k] + k + 1, n - (k + 1), (double) mtrx[k][k] / mtrx[i][k]);
                addition_or_sub_strs(mtrx[i] + k + 1, mtrx[k] + k + 1, n - (k + 1), TRUE);
                div_str(mtrx[k] + k + 1, n - (k + 1), (double) mtrx[i][k] / mtrx[k][k]);
                mtrx[i][k] = 0;
            }

        det *= mtrx[k][k];
    }

    fprintf(f, "%lf", det);
}


void free_matrix(double **data, int n)
{
    for (int i = 0; i < n; i++)
       free(data[i]);

    free(data);
}