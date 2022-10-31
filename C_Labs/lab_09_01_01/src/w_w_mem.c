#include <stdlib.h>
#include <string.h>

#include "../inc/my_types.h"
#include "../inc/w_w_movie.h"
#include "../inc/my_def.h"
#include "../inc/my_err.h"


void init_movies_arr(movies_t *movies)
{
    movies->len = 0;
    movies->allocated = 0;
    movies->step = 2;
    movies->movies = NULL;
}


int get_buf(movie_t *movie, movie_t *buf)
{
    buf->title = strdup(movie->title);
    if (!buf->title)
        return ERR_ALLOC;

    buf->name = strdup(movie->name);
    if (!buf->name)
    {
        free(buf->title);
        return ERR_ALLOC;
    }

    buf->year = movie->year;

    return SUCCESS;
}


void free_movie(movie_t *movie)
{
    free(movie->name);
    free(movie->title);
}


void free_movies(movies_t *movies)
{
    for (int i = 0; i < movies->len; ++i)
    {
        free(movies->movies[i].name);
        free(movies->movies[i].title);
    }

    free(movies->movies);
}