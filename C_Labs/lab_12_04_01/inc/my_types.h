#ifndef ___MY_TYPES___
#define ___MY_TYPES___

#include <stdio.h>


typedef void (*in_out_t)(FILE *f, int *, int *);
typedef int (*key_t)(const int *, const int *, int **, int **, int *);
typedef void (*mysort_t)(void *, size_t, size_t, int (*compar)(const void*, const void*));

#endif // ___MY_TYPES___