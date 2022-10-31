#ifndef ___MY_IN_OUT____
#define ___MY_IN_OUT____

#include <stdio.h>

#include "my_types.h"


int read_movie(FILE *f, char **title, char **name, int *year);
void print_movies(movies_t *movies);

#endif // ___MY_IN_OUT____