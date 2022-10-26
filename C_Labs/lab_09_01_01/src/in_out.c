#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "../inc/my_types.h"
#include "../inc/my_def.h"
#include "../inc/my_err.h"


int read_movie(FILE *f, movie_t *movie)
{
    int count;
    size_t init_size = INIT_SIZE;


    count = getline(&(movie->title), &init_size, f);
    if (count < 0)
        return ERR_READING;

    count = getline(&(movie->name), &init_size, f);
    if (count < 0)
        return ERR_READING;
        
    if (movie->name[0] == '\0' || movie->title[0] == '\0')
        return ERR_READING;
    
    if (fscanf(f, "%d\n", &(movie->year)) != 1)
        return ERR_READING;
    else if (movie->year < 0)
        return ERR_READING;

    return SUCCESS;
}