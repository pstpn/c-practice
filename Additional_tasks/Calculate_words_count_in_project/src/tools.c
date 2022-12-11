#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "my_def.h"


void get_all_filenames_in_cur_folder(char *out_filename, char *folder, int count, ...)
{
    char *command;
    char desired_extensions[MAX_EXT_STR_LEN + 1] = "\0";

    va_list cur_param;

    va_start(cur_param, count);


    for (int i = 0; i < count - 1; ++i)
    {
        strcat(desired_extensions, "-name \"*.");
        strcat(desired_extensions, va_arg(cur_param, char *));
        strcat(desired_extensions, "\" -o ");
    }
    strcat(desired_extensions, "-name \"*.");
    strcat(desired_extensions, va_arg(cur_param, char *));
    strcat(desired_extensions, "\"");

    va_end(cur_param);

    asprintf(&command, GET_ALL_FILENAMES_COMMAND_FORMAT,
            folder, desired_extensions, out_filename);

    system(command);

    free(command);
}


int is_sep_sym(char *seps, char ch)
{
    for (int i = 0; seps[i]; ++i)
        if (ch == seps[i])
            return TRUE;

    return FALSE;
}


int get_words_count_in_file(FILE *f, char *seps)
{
    int all_words_count = 0;

    char buf_word[MAX_WORD_LEN + 1];
    char buf_sym;


    while (feof(f) == 0)
    {
        int i = 0;


        memset(buf_word, '\0', MAX_WORD_LEN + 1);

        do
        {
            if (fscanf(f, "%c", &buf_sym) != 1)
                break;
            
            if (!is_sep_sym(seps, buf_sym))
                buf_word[i++] = buf_sym;
            else
                break;
        } while (buf_sym != EOF);
        

        all_words_count += (buf_word[0]) ? 1 : 0;

        // printf("\nCUR_BUF_WORD: %s\n", buf_word);
    }

    return all_words_count;
}