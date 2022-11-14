#include "../inc/my_def.h"



int compare_int(const void *a, const void *b)
{
    const int *c = a;
    const int *d = b;


    return (*c > *d) ? TRUE : FALSE;
}