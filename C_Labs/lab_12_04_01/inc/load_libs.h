#ifndef ___MY_LOAD_LIBS___
#define ___MY_LOAD_LIBS___

#include <stdio.h>

typedef void (*in_out_t)(FILE *f, int *, int *);
typedef int (*key_t)(const int *, const int *, int **, int **, int *);
typedef void (*mysort_t)(void *, size_t, size_t, int (*compar)(const void*, const void*));


void *load_func(void *cur_lib, const char *lib_name, const char *func_name);

#endif // ___MY_LOAD_LIBS___