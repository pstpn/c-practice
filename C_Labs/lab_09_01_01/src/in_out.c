#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/my_types.h"
#include "../inc/my_def.h"
#include "../inc/my_err.h"


int read_movie(FILE *f, char **title, char **name, int *year)
{
    int count;
    size_t init_size = INIT_SIZE;


    count = getline(title, &init_size, f);
    if (count < 0)
    {
        free(*title);
        return ERR_READING;
    }

    if ((*title)[strlen(*title) - 1] != '\n' ||
        (*title)[0] == '\n')
    {
        free(*title);
        return ERR_READING;
    }

    count = getline(name, &init_size, f);
    if (count < 0)
    {
        free(*title);
        free(*name);
        return ERR_READING;
    }

    if ((*name)[strlen(*name) - 1] != '\n' ||
        (*name)[0] == '\n')
    {
        free(*title);
        free(*name);
        return ERR_READING;
    }

    (*name)[strlen(*name) - 1] = '\0';
    (*title)[strlen(*title) - 1] = '\0';
    
    if (fscanf(f, "%d\n", year) != 1)
    {
        free(*title);
        free(*name);
        return ERR_READING;
    }
    else if (*year < 0)
    {
        free(*title);
        free(*name);
        return ERR_READING;
    }

    return SUCCESS;
}


void print_movies(movies_t *movies)
{
    for (int i = 0; i < movies->len; ++i)
        printf("%s\n%s\n%d\n", movies->movies[i].title,
        movies->movies[i].name, movies->movies[i].year);
}