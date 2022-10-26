#include <stdlib.h>

#include "../inc/my_types.h"
#include "../inc/my_def.h"
#include "../inc/my_err.h"


int init_movie_alloc(movie_t *movie)
{
    movie->name = calloc(INIT_SIZE, sizeof(char));
    if (!movie->name)
        return ERR_ALLOC;

    movie->title = calloc(INIT_SIZE, sizeof(char));
    if (!movie->title)
    {
        free(movie->name);
        return ERR_ALLOC;
    }

    return SUCCESS;
}


void init_movies_arr(movies_t *movies)
{
    movies->len = 0;
    movies->allocated = 0;
    movies->step = 2;
    movies->movies = NULL;
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

    movies->movies[(movies->len)++] = movie;
    
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
        free(movies->movies[i]->name);
        free(movies->movies[i]->title);
    }

    free(movies->movies);
}