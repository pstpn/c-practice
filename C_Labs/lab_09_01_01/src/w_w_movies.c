#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/my_types.h"
#include "../inc/my_def.h"
#include "../inc/in_out.h"
#include "../inc/w_w_movie.h"
#include "../inc/w_w_mem.h"
#include "../inc/my_err.h"


int replace_movies(movies_t *movies, const int ind_1, const int ind_2)
{
    movie_t buf;
    if (get_buf(&(movies->movies[ind_1]), &buf))
        return ERR_ALLOC;


    for (int i = movies->len - 1; i > ind_2; --i)
    {
        movies->movies[i].title = movies->movies[i - 1].title;
        movies->movies[i].name = movies->movies[i - 1].name;
        movies->movies[i].year = movies->movies[i - 1].year;
    }

    movies->movies[ind_2].title = buf.title;
    movies->movies[ind_2].name = buf.name;
    movies->movies[ind_2].year = buf.year;

    return SUCCESS;
}


int read_movies_and_sort(FILE *f, movies_t *movies, char sort_field)
{
    movie_t movie;

    char *cur_title = NULL;
    char *cur_name = NULL;

    int cur_year;


    while (feof(f) == 0)
    {
        movie.title = NULL;
        movie.name = NULL;

        if (read_movie(f, &cur_title, &cur_name, &cur_year))
            return ERR_READING;

        if (init_movie(&movie, cur_title, cur_name, cur_year))
            return ERR_ALLOC;

        if (append_movie(movies, &movie))
        {
            free_movie(&movie);
            return ERR_ALLOC;
        }

        if (sort_field == 't')
        {
            int cur_ind = movies->len - 1;


            do
            {
                --cur_ind;
            } while (cur_ind >= 0 &&
                strcmp(movies->movies[cur_ind].title, movies->movies[movies->len - 1].title) > 0);
                
            if (replace_movies(movies, movies->len - 1, cur_ind + 1))
            {
                free_movie(&movie);
                return ERR_ALLOC;
            }
        }
        if (sort_field == 'n')
        {
            int cur_ind = movies->len - 1;


            do
            {
                --cur_ind;
            } while (cur_ind >= 0 &&
                strcmp(movies->movies[cur_ind].name, movies->movies[movies->len - 1].name) > 0);
                
            if (replace_movies(movies, movies->len - 1, cur_ind + 1))
            {
                free_movie(&movie);
                return ERR_ALLOC;
            }
        }
        if (sort_field == 'y')
        {
            int cur_ind = movies->len - 1;


            do
            {
                --cur_ind;
            } while (cur_ind >= 0 &&
                movies->movies[cur_ind].year > movies->movies[movies->len - 1].year);
                
            if (replace_movies(movies, movies->len - 1, cur_ind + 1))
            {
                free_movie(&movie);
                return ERR_ALLOC;
            }
        }

        free_movie(&movie);
    }

    return SUCCESS;
}