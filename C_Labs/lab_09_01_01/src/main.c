/**
 * @file main.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий главную функцию проекта
 * 
 * TASK:
 * 
 * Требуется написать программу, которая, будучи вызванной из командной строки:
 * 
 * app.exe FILE FIELD [KEY]
 * 
 * где FILE — имя файла, FIELD — анализируемое поле, KEY — значение ключа;
 * 
 * 1. считывает информацию о кинофильмах в массив. Информация после чтения полей
 * каждой структуры помещается в массив таким образом, чтобы он сразу же был
 * упорядочен по указанному полю.
 * 2. Если значение ключа не указано, выводит упорядоченный массив.
 * 3. Если значение ключа указано, выполняет двоичный поиск1 по полю и значению
 * ключа. Если кинофильм с искомым значением ключа найден, программа выводит
 * информацию о нём на экран, иначе программа выводит сообщение «Not found».
 * 
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "../inc/w_w_mem.h"
#include "../inc/w_w_movies.h.h"
#include "../inc/in_out.h"
#include "../inc/tools.h"
#include "../inc/my_types.h"
#include "../inc/my_def.h"
#include "../inc/my_err.h"


int main(int argc, char *argv[])
{
    char correct_fields[NUMBER_OF_FIELDS][MAX_FIELD_LENGTH + 1] = { "title", "name", "year" };
    char sort_field;


    if ((argc < MIN_ARGS && argc != MAX_ARGS) ||
        (argc > MAX_ARGS && argv[3][0] != '\"'))
        return INCORRECT_ARGS;

    sort_field = does_the_field_exist(argv[2], correct_fields);
    if (!sort_field)
        return INCORRECT_FIELD;

    FILE *f = fopen(argv[1], "r");
    if (!f)
        return INCORRECT_FILENAME;

    movies_t movies;
    init_movies_arr(&movies);


    if (argc == MIN_ARGS)
    {
        int code;


        code = read_movies_and_sort(f, &movies, sort_field);
        if (code == ERR_READING)
        {
            fclose(f);
            free_movies(&movies);
            return ERR_READING;
        }
        else if (code == ERR_ALLOC)
        {
            fclose(f);
            free_movies(&movies);
            return ERR_ALLOC;
        }

        print_movies(&movies);

        free_movies(&movies);
        fclose(f);
    }
    // else
    // {
    //     if (get_structs_and_sort(f, &films, &len, sort_field))
    //         return INCORRECT_FILE;

    //     if ((sort_field == 'y' && !is_correct_digit(argv[3])) || (sort_field == 'y' && argc > 4))
    //         return INCORRECT_YEAR;
        
    //     int index;


    //     if (argc == 4)
    //     {
    //         if (!is_correct_key(argv[3]))
    //             return INCORRECT_ARGS;
    
    //         if ((index = binary_search(&films, len, sort_field, argv[3])) == NOT_FOUND)
    //             printf("Not found\n");
    //         else
    //             printf("%s\n%s\n%d\n", films[index].title, films[index].name, films[index].year);

    //         free_movies(movies);
    //     }
    //     else
    //     {
    //         char param[MAX_LENGTH + 1];
    //         memset(&param, '\0', MAX_LENGTH + 1);


    //         get_param(param, ++(argv[3]));

    //         if ((index = binary_search(&films, len, sort_field, param)) == NOT_FOUND)
    //             printf("Not found\n");
    //         else
    //             printf("%s\n%s\n%d\n", films[index].title, films[index].name, films[index].year);

    //         free_movies(movies);
    //     }
    // }

    
    return SUCCESS;
}