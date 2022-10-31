#include <stdlib.h>
#include <string.h>

#include "../inc/my_err.h"
#include "../inc/my_types.h"


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
        free(title);
        free(name);
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
        free(title);
        free(name);
        free(cur_field);
        free(movie->title);
        return ERR_ALLOC;
    }

    movie->year = year;

    return SUCCESS;
}