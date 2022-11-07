#include <stdlib.h>
#include <string.h>

#include "../inc/tools.h"
#include "../inc/in_out.h"
#include "../inc/w_w_mem.h"
#include "../inc/my_err.h"
#include "../inc/my_types.h"
#include "../inc/my_def.h"


int init_movie(movie_t *movie, char *title, char *name, int year)
{
    char *cur_field = strdup(title);


    if (cur_field)
    {
        free(movie->title);
        movie->title = cur_field;
    }
    else
    {
        free(cur_field);
        return ERR_ALLOC;
    }

    cur_field = strdup(name);

    if (cur_field)
    {
        free(movie->name);
        movie->name = cur_field;
    }
    else
    {
        free(cur_field);
        return ERR_ALLOC;
    }

    movie->year = year;

    return SUCCESS;
}


int append_movie(movies_t *movies, movie_t *movie)
{
    if (!movies->movies)
    {
        movies->movies = calloc(INIT_SIZE, sizeof(movie_t));
        if (!movies->movies)
            return ERR_ALLOC;
        
        movies->allocated = INIT_SIZE;
    }
    else if (movies->len == movies->allocated)
    {
        void *tmp = realloc(movies->movies,
        movies->step * movies->allocated * sizeof(movie_t));
        if (!tmp)
            return ERR_ALLOC;
        
        movies->movies = tmp;
        movies->allocated *= movies->step;
    }

    movies->movies[movies->len].title = movie->title;
    movies->movies[movies->len].name = movie->name;
    movies->movies[movies->len++].year = movie->year;
    
    return SUCCESS;
}
