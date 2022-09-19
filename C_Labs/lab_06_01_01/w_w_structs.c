/**
 * @file w_w_structs.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий функции для работы со структурами
 * @version 0.1
 * @date 2022-09-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"
#include "my_struct.h"
#include "my_err.h"


/**
 * @brief Функция чтения структуры из файла
 * 
 * @param [in] f Файл
 * @param [out] title Название фильма
 * @param [out] name Фамилия автора
 * @param [out] year Год выпуска
 * @return int 
 */
int read_struct(FILE *f, char *title, char *name, int *year)
{
    int ch;
    int i = 0;


    while ((ch = fgetc(f)) != '\n' && i < MAX_LENGTH)
        title[i++] = ch;

    if (ch != '\n')
        return INCORRECT_STRUCT;

    i = 0;

    while ((ch = fgetc(f)) != '\n' && ch != EOF && i < MAX_LENGTH)
        name[i++] = ch;

    if (ch != '\n')
        return INCORRECT_STRUCT;
        
    if (name[0] == '\0' || title[0] == '\0')
        return INCORRECT_STRUCT;
    
    if (fscanf(f, "%d\n", year) != 1)
        return INCORRECT_STRUCT;
    else if (*year < 0)
        return INCORRECT_YEAR;

    if (feof(f) != 0)
        return END_OF_FILE;

    return SUCCESS;
}


/**
 * @brief Функция перестановки структур
 * 
 * @param [in] ind_1 Индекс первой структуры
 * @param [in] ind_2 Индекс второй структуры
 */
void replace_structs(film_t (*films)[MAX_LENGTH + 1], const int ind_1, const int ind_2)
{
    char buffer[MAX_LENGTH + 1];
    memset(&buffer, '\0', MAX_LENGTH + 1);

    int buf;

    for (int i = 0; (*films)[ind_1].title[i] != '\0'; ++i)
    {
        buffer[i] = (*films)[ind_1].title[i];
        (*films)[ind_1].title[i] = '\0';
    }

    for (int i = 0; (*films)[ind_2].title[i] != '\0'; ++i)
    {
        (*films)[ind_1].title[i] = (*films)[ind_2].title[i];
        (*films)[ind_2].title[i] = '\0';
    }

    for (int i = 0; buffer[i] != '\0'; ++i)
        (*films)[ind_2].title[i] = buffer[i];
    
    memset(&buffer, '\0', MAX_LENGTH + 1);

    for (int i = 0; (*films)[ind_1].name[i] != '\0'; ++i)
    {
        buffer[i] = (*films)[ind_1].name[i];
        (*films)[ind_1].name[i] = '\0';
    }

    for (int i = 0; (*films)[ind_2].name[i] != '\0'; ++i)
    {
        (*films)[ind_1].name[i] = (*films)[ind_2].name[i];
        (*films)[ind_2].name[i] = '\0';
    }

    for (int i = 0; buffer[i] != '\0'; ++i)
        (*films)[ind_2].name[i] = buffer[i];

    buf = (*films)[ind_1].year;
    (*films)[ind_1].year = (*films)[ind_2].year;
    (*films)[ind_2].year = buf;
}


/**
 * @brief Функция получения отсортированных структур
 * 
 * @param [in] f Файл
 * @param [out] films Массив структур с фильмами
 * @param [out] len Кол-во фильмов
 * @param [in] sort_field Поле, по которому происходит сортировка
 * @return int 
 */
int get_structs_and_sort(FILE *f, film_t (*films)[], int *len, char sort_field)
{
    int code, cur_len;


    *len = 0;

    if ((code = read_struct(f, (*films)[*len].title, (*films)[*len].name, &((*films)[*len].year))) > 0)
        return INCORRECT_FILE;
    
    if (code == END_OF_FILE)
    {
        ++(*len);
        return SUCCESS;
    }

    for (*len = 1; *len < MAX_FILMS_COUNT; ++(*len))
    {
        if ((code = read_struct(f, (*films)[*len].title, (*films)[*len].name, &((*films)[*len].year))) > 0)
            return INCORRECT_FILE;

        if (sort_field == 't')
        {
            cur_len = *len;

            while (*len > 0 && strcmp_al((*films)[*len - 1].title, (*films)[*len].title) > 0)
            {
                replace_structs(films, *len - 1, *len);
                (*len)--;
            }

            *len = cur_len;
        }
        if (sort_field == 'n')
        {
            cur_len = *len;

            while (*len > 0 && strcmp_al((*films)[*len - 1].name, (*films)[*len].name) > 0)
            {
                replace_structs(films, *len - 1, *len);
                (*len)--;
            }

            *len = cur_len;
        }
        if (sort_field == 'y')
        {
            cur_len = *len;

            while (*len > 0 && (*films)[*len - 1].year > (*films)[*len].year)
            {
                replace_structs(films, *len - 1, *len);
                (*len)--;
            }

            *len = cur_len;
        }

        if (code == END_OF_FILE)
        {
            ++(*len);
            break;
        }
    }
    int ch = fgetc(f);
    if (ch != -1)
        return INCORRECT_FILE;

    return SUCCESS;
}


/**
 * @brief Функция бинарного поиска
 * 
 * @param [in] films Массив структур с фильмами
 * @param [in] len Кол-во фильмов
 * @param [in] sort_field Поле, по которому происходила сортировка
 * @param [in] key Ключ поиска
 * @return int 
 */
int binary_search(film_t (*films)[], int len, char sort_field, char *key)
{
    int low = 0, high = len - 1, middle;
    int cmp;


    while (low <= high)
    {
        middle = (low + high) / 2;

        if (sort_field == 't')
        {
            cmp = strcmp_al((*films)[middle].title, key);

            if (cmp > 0)
                high = middle - 1;
            else if (cmp < 0)
                low = middle + 1;
            else
                return middle;
        }
        if (sort_field == 'n')
        {
            cmp = strcmp_al((*films)[middle].name, key);

            if (cmp > 0)
                high = middle - 1;
            else if (cmp < 0)
                low = middle + 1;
            else
                return middle;
        }
        if (sort_field == 'y')
        {
            int int_key = atoi(key);


            if ((*films)[middle].year > int_key)
                high = middle - 1;
            else if ((*films)[middle].year < int_key)
                low = middle + 1;
            else
                return middle;
        }
    }

    return NOT_FOUND;
}


/**
 * @brief Функция вывода структур
 * 
 * @param [in] len Кол-во фильмов
 * @param [in] films Массив структур с фильмами
 */
void print_structs(int len, film_t films[])
{
    for (int i = 0; i < len; ++i)
        printf("%s\n%s\n%d\n", films[i].title, films[i].name, films[i].year);
}