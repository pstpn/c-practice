#ifndef ___MY_TOOLS___
#define ___MY_TOOLS___

#include <stdio.h>


int get_size(FILE *f, int *n, int *m);
void addition_or_sub_strs(double str_1[], double str_2[], int n, int sub);
int get_nonzero(double **mtrx, int col, int a, int b);
void div_str(double str[], int n, double div);

#endif // ___MY_TOOLS___