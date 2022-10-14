#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define ERR_ARGS 1
#define ERR_GET_SIZE 2
#define ERR_READING 3
#define ERR_FILE 4
#define ERR_ALLOC 5

#define MIN_ARGS 4
#define MAX_ARGS 5
#define TRUE 1
#define FALSE 0


int get_size(FILE *f, int *n, int *m)
{
    char buf;


    if (fscanf(f, "%d%d%c", n, m, &buf) != 3 ||
    buf != '\n' || *n < 1 || *m < 1)
        return ERR_GET_SIZE;

    return SUCCESS;
}


double** allocate_matrix(int n, int m)
{
    double **ptrs, *data;


    ptrs = malloc(n * sizeof(double*));
    if (!ptrs)
        return NULL;

    data = malloc(n * m * sizeof(double));

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
    char buf;


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


int main(int argc, char **argv)
{
    if (argc != MIN_ARGS && argc != MAX_ARGS)
        return ERR_ARGS;

    FILE *f = fopen(argv[2], "r");
    if (f == NULL)
        return ERR_FILE;

    int n_1, m_1;


    if (get_size(f, &n_1, &m_1))
    {
        fclose(f);
        return ERR_GET_SIZE;
    }

    double **mtrx_1 = allocate_matrix(n_1, m_1);
    if (mtrx_1 == NULL)
    {
        fclose(f);
        return ERR_ALLOC;
    }

    if (filling_matrix(f, mtrx_1, n_1, m_1))
    {
        fclose(f);
        free_matrix(mtrx_1, 1);
        return ERR_READING;
    }

    fclose(f);

    if (argc == MAX_ARGS && argv[1][0] == 'a' &&
    argv[1][1] == '\0')
    {
        FILE *g = fopen(argv[3], "r");
        if (g == NULL)
            return ERR_FILE;

        int n_2, m_2;


        if (get_size(g, &n_2, &m_2) || n_2 != n_1 || m_1 != m_2)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            return ERR_GET_SIZE;
        }

        double **mtrx_2 = allocate_matrix(n_2, m_2);
        if (mtrx_2 == NULL)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            return ERR_ALLOC;
        }

        if (filling_matrix(g, mtrx_2, n_2, m_2))
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            free_matrix(mtrx_2, 1);
            return ERR_READING;
        }

        FILE *res = fopen(argv[4], "w");
        if (res == NULL)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            free_matrix(mtrx_2, 1);
            return ERR_FILE;
        }

        matrix_addition_and_write(res, mtrx_1, mtrx_2, n_1, m_1);
        
        free_matrix(mtrx_2, 1);
        fclose(res);
        fclose(g);
    }
    else if (argc == MAX_ARGS && argv[1][0] == 'm' &&
    argv[1][1] == '\0')
    {
        FILE *g = fopen(argv[3], "r");
        if (g == NULL)
            return ERR_FILE;

        int n_2, m_2;


        if (get_size(g, &n_2, &m_2) || m_1 != n_2)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            return ERR_GET_SIZE;
        }

        double **mtrx_2 = allocate_matrix(n_2, m_2);
        if (mtrx_2 == NULL)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            return ERR_ALLOC;
        }

        if (filling_matrix(g, mtrx_2, n_2, m_2))
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            free_matrix(mtrx_2, 1);
            return ERR_READING;
        }

        FILE *res = fopen(argv[4], "w");
        if (res == NULL)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            free_matrix(mtrx_2, 1);
            return ERR_FILE;
        }

        matrix_product_and_write(res, mtrx_1, mtrx_2, n_2, n_1, m_2);
        
        free_matrix(mtrx_2, 1);
        fclose(res);
        fclose(g);
    }
    else if (argc == MIN_ARGS && argv[1][0] == 'o' &&
    argv[1][1] == '\0')
    {
        if (n_1 != m_1)
            return ERR_GET_SIZE;

        FILE *res = fopen(argv[3], "w");
        if (res == NULL)
        {
            free_matrix(mtrx_1, 1);
            return ERR_FILE;
        }

        get_det_and_write(res, mtrx_1, n_1);
        
        fclose(res);
    }
    else
    {
        free_matrix(mtrx_1, 1);
        return ERR_ARGS;  
    }

    free_matrix(mtrx_1, 1);

    return SUCCESS;
}
