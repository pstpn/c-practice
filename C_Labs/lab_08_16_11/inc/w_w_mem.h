#ifndef ___W_W_MEM___
#define ___W_W_MEM___

#include <stdio.h>


double **allocate_matrix(int n, int m);
int filling_matrix(FILE *f, double **ptrs, int n, int m);
void free_matrix(double **data, int n);

#endif // ___W_W_MEM___