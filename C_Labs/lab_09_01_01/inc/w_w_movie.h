#ifndef ___W_W_MOVIE___
#define ___W_W_MOVIE___

#include "my_types.h"


int init_movie(movie_t *movie, char *title, char *name, int year);
int append_movie(movies_t *movies, movie_t *movie);

#endif // ___W_W_MOVIE___