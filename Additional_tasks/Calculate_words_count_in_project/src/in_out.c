#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"
#include "my_def.h"


void draw_line(int len)
{
    for (int i = 0; i < len; ++i)
        printf("-");

    printf("\n");
}


void print_words_count(char *src_filenames, char *seps)
{
    FILE *src_file = fopen(src_filenames, "r");

    size_t init_buf = 40;

    int all_count = 0;


    while (feof(src_file) == 0)
    {
        char *cur_filename = NULL;
        

        getline(&cur_filename, &init_buf, src_file);

        if (cur_filename[strlen(cur_filename) - 1] != '\n')
            break;
        else
        {
            cur_filename[strlen(cur_filename) - 1] = '\0';

            FILE *cur_file = fopen(cur_filename, "r");


            int cur_count = get_words_count_in_file(cur_file, seps);


            printf("\nFilename: %s\nWords count: %d\n", cur_filename, cur_count);

            all_count += cur_count;

            fclose(cur_file);
        }

        free(cur_filename);
    }

    printf("\n%sSUMMARY: %d%s\n\n", PURPLE, all_count, RESET);

    fclose(src_file);
}