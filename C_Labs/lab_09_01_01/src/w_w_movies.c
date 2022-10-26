#include <stdio.h>
#include <string.h>

#include "../inc/my_types.h"
#include "../inc/in_out.h"
#include "../inc/w_w_mem.h"
#include "../inc/my_err.h"


void replace_movies(movies_t *movies, const int ind_1, const int ind_2)
{
    int buf_year = movies->movies[ind_1]->year;

    char *buf_title = movies->movies[ind_1]->title;
    char *buf_name = movies->movies[ind_1]->name;


    movies->movies[ind_1]->year = movies->movies[ind_2]->year;
    movies->movies[ind_1]->title = movies->movies[ind_2]->title;
    movies->movies[ind_1]->name = movies->movies[ind_2]->name;

    movies->movies[ind_2]->year = buf_year;
    movies->movies[ind_2]->title = buf_title;
    movies->movies[ind_2]->name = buf_name;
}


int read_movies_and_sort(FILE *f, movies_t *movies, char sort_field)
{
    while (feof(f) == 0)
    {
        movie_t movie;
        if (init_movie_alloc(&movie))
            return ERR_ALLOC;


        if (read_movie(f, &movie))
        {
            free_movie(&movie);
            return ERR_READING;
        }

        if (movies->len == movies->allocated)
            if (append_movie(movies, &movie))
            {
                free_movie(&movie);
                return ERR_ALLOC;
            }

        if (sort_field == 't')
        {
            int cur_ind = movies->len - 1;

            while (cur_ind > 0 && strcmp((*(movies->movies[cur_ind - 1])).title, (*(movies->movies[cur_ind])).title) > 0)
                --cur_ind;

            if (cur_ind != movies->len - 1)
                replace_movies(movies, movies->len - 1, cur_ind);
        }
        // if (sort_field == 'n')
        // {
        //     cur_len = *len;

        //     while (*len > 0 && strcmp_al((*films)[*len - 1].name, (*films)[*len].name) > 0)
        //     {
        //         replace_structs(films, *len - 1, *len);
        //         (*len)--;
        //     }

        //     *len = cur_len;
        // }
        // if (sort_field == 'y')
        // {
        //     cur_len = *len;

        //     while (*len > 0 && (*films)[*len - 1].year > (*films)[*len].year)
        //     {
        //         replace_structs(films, *len - 1, *len);
        //         (*len)--;
        //     }

        //     *len = cur_len;
        // }
    }

    return SUCCESS;
}