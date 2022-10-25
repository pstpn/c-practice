#ifndef ___MY_W_W_MEM___
#define ___MY_W_W_MEM___

#include "my_types.h"


int init_movie_alloc(movie_t *movie);
void init_movies_arr(movies_t *movies);
int realloc_memory(movies_t *movies);
void free_movie(movie_t *movie);
void free_movies(movies_t *movies);

#endif // ___MY_W_W_MEM___