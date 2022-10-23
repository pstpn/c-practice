#ifndef ___MY_W_W_MTRX___
#define ___MY_W_W_MTRX___

#include <stdio.h>


void matrix_addition_and_write(FILE *f, double **mtrx_1, double **mtrx_2, int n, int m);
void matrix_product_and_write(FILE *f, double **mtrx_1, double **mtrx_2, 
int n_2_m_1, int n_1, int m_2);
void get_det_and_write(FILE *f, double **mtrx, int n);

#endif // ___MY_W_W_MTRX___