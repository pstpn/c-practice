#ifndef ___MY_W_W_MOVIES____
#define ___MY_W_W_MOVIES____

#include <stdio.h>

#include "my_types.h"


void replace_movies(movies_t *movies, const int ind_1, const int ind_2);
int sort_movies(char sort_field, movies_t *movies);
int read_movies_and_sort(FILE *f, movies_t *movies, char sort_field);
int binary_search(movies_t *movies, char sort_field, char *key);

#endif // ___MY_W_W_MOVIES____