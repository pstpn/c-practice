#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "../inc/my_types.h"
#include "../inc/my_def.h"
#include "../inc/my_err.h"


int read_movie(FILE *f, movie_t *movie)
{
    // int ch;
    int count;
    size_t init_size = INIT_SIZE;


    count = getline(&(movie->title), &init_size, f);
    if (count < 0)
        return ERR_READING;
        
    printf("STR: %s", movie->title);

    // while ((ch = fgetc(f)) != '\n' && ch != EOF && i < MAX_LENGTH)
    //     name[i++] = ch;

    // if (ch != '\n')
    //     return INCORRECT_STRUCT;
        
    // if (name[0] == '\0' || title[0] == '\0')
    //     return INCORRECT_STRUCT;
    
    // if (fscanf(f, "%d\n", year) != 1)
    //     return INCORRECT_STRUCT;
    // else if (*year < 0)
    //     return INCORRECT_YEAR;

    // if (feof(f) != 0)
    //     return END_OF_FILE;

    return SUCCESS;
}