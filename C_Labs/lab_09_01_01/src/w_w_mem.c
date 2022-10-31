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


int append_movie(movies_t *movies, movie_t *movie)
{
    if (!movies->movies)
    {
        movies->movies = calloc(INIT_SIZE, sizeof(movie_t *));
        if (!movies->movies)
            return ERR_ALLOC;
        
        movies->allocated = INIT_SIZE;
    }
    else
        if (movies->len == movies->allocated)
        {
            void *tmp = realloc(movies->movies,
                movies->step * movies->allocated * sizeof(movie_t *));
            if (!tmp)
                return ERR_ALLOC;
            
            movies->movies = tmp;
            movies->allocated *= movies->step;
        }

    movies->movies[movies->len].title = NULL;
    movies->movies[movies->len].name = NULL;

    if (init_movie(&(movies->movies[movies->len]),
        movie->title, movie->name, movie->year))
        return ERR_ALLOC;

    ++(movies->len);
    
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