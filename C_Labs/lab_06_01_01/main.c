/**
 * @file main.c
 * @author Stepan Postnov ICS7-31B
 * @brief Главный файл проекта
 * 
 * TASK:
 * 
 * В текстовом файле хранится информация о кинофильмах, которая включает в себя на-
 * звание кинофильма, фамилию режиссёра и год выхода на экран. В названии кинофильма
 * не более двадцати пяти символов. В фамилии кинорежиссёра не более двадцати пяти сим-
 * волов. Год выхода задаётся целым числом. Количество кинофильмов в самом файле не
 * указано. Требуется написать программу, которая, будучи вызванной из командной строки:
 * 
 * app.exe FILE FIELD [KEY]
 * где FILE — имя файла, FIELD — анализируемое поле, KEY — значение ключа;
 * 
 * 1. считывает информацию о кинофильмах в массив. Информация после чтения полей
 * каждой структуры помещается в массив таким образом, чтобы он сразу же был
 * упорядочен по указанному полю.
 * 
 * 2. Если значение ключа не указано, выводит упорядоченный массив.
 * 
 * 3. Если значение ключа указано, выполняет двоичный поиск1 по полю и значению
 * ключа. Если кинофильм с искомым значением ключа найден, программа выводит
 * информацию о нём на экран, иначе программа выводит сообщение «Not found».
 * 
 * @version 0.1
 * @date 2022-09-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string.h>

#include "my_def.h"
#include "my_err.h"
#include "my_struct.h"
#include "tools.h"
#include "w_w_structs.h"


/**
 * @brief Главная функция программы
 * 
 * @param [in] argc 
 * @param [in] argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    film_t films[MAX_FILMS_COUNT];

    char correct_fields[NUMBER_OF_FIELDS][MAX_FIELD_LENGTH + 1] = { "title", "name", "year" };
    char sort_field;

    int len;


    if ((argc < 3 && argc != 4) || (argc > 4 && argv[3][0] != '\"'))
        return INCORRECT_ARGS;

    sort_field = does_the_field_exist(argv[2], correct_fields);
    if (!sort_field)
        return INCORRECT_FIELD;

    FILE *f = fopen(argv[1], "r");
    

    if (f == NULL)
        return INCORRECT_FILENAME;

    memset(&films, '\0', MAX_FILMS_COUNT * sizeof(film_t));

    if (argc == 3)
    {
        if (get_structs_and_sort(f, &films, &len, sort_field))
            return INCORRECT_FILE;

        print_structs(len, films);
    }
    else
    {
        if (get_structs_and_sort(f, &films, &len, sort_field))
            return INCORRECT_FILE;

        if ((sort_field == 'y' && !is_correct_digit(argv[3])) || (sort_field == 'y' && argc > 4))
            return INCORRECT_YEAR;
        
        int index;


        if (argc == 4)
        {
            if (!is_correct_key(argv[3]))
                return INCORRECT_ARGS;
    
            if ((index = binary_search(&films, len, sort_field, argv[3])) == NOT_FOUND)
                printf("Not found\n");
            else
                printf("%s\n%s\n%d\n", films[index].title, films[index].name, films[index].year);
        }
        else
        {
            char param[MAX_LENGTH + 1];
            memset(&param, '\0', MAX_LENGTH + 1);


            get_param(param, ++(argv[3]));

            if ((index = binary_search(&films, len, sort_field, param)) == NOT_FOUND)
                printf("Not found\n");
            else
                printf("%s\n%s\n%d\n", films[index].title, films[index].name, films[index].year);
        }
    }

    
    return SUCCESS;
}