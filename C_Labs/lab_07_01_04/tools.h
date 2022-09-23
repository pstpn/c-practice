#ifndef ___MY_TOOLS____
#define ___MY_TOOLS____

#include <stdio.h>


int get_count(FILE *f, int *count);
double get_avg(const int *pcur, const int *pend);
int compare_int(const void *p, const void *q);

#endif // ___MY_TOOLS____