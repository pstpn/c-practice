#ifndef ___MY_W_W_MEM___
#define ___MY_W_W_MEM___

#include "my_types.h"


void init_movies_arr(movies_t *movies);
int get_buf(movie_t *movie, movie_t *buf);
int append_movie(movies_t *movies, movie_t *movie);
void free_movie(movie_t *movie);
void free_movies(movies_t *movies);

#endif // ___MY_W_W_MEM___