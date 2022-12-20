#ifndef ___MY_W_W_ARR____
#define ___MY_W_W_ARR____

#include <stdio.h>


int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, int *count);
void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

#endif // ___MY_W_W_ARR____