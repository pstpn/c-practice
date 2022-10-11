#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define ERR_ARGS 1
#define ERR_GET_SIZE 2
#define ERR_READING 3

#define MIN_ARGS 4
#define MAX_ARGS 5


int get_size(FILE *f, int *n, int *m)
{
    char buf;


    if (fscanf(f, "%d %d%c", n, m, &buf) != 3 ||
    buf != '\n' || *n != *m || *n < 1)
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
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (fscanf(f, "%lf", &(ptrs[i][j])) != 1)
                return ERR_READING;

    return SUCCESS;
}


int main(int argc, char **argv)
{
    int n, m;


    if (argc == MAX_ARGS && argv[1][0] == 'a' &&
    argv[1][1] == '\0')
    {
        
    }
    else if (argc == MAX_ARGS && argv[1][0] == 'm' &&
    argv[1][1] == '\0')
    {
        
    }
    else if (argc == MIN_ARGS && argv[1][0] == 'o' &&
    argv[1][1] == '\0')
    {
        
    }
    else
        return ERR_ARGS;
    
    

    FILE *f = fopen()
    

    return SUCCESS;
}
