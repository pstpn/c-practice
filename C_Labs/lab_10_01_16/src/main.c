/**
 * @file main.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий главную функцию проекта
 * 
 * TASK:
 * 
 * Требуется написать программу, которая, будучи вызванной из командной строки:
 * 
 * app.exe IN_FILE OUT_FILE KEY
 * 
 * где IN_FILE  — имя входного файла, 
 *     OUT_FILE — имя выходного файла,
 *     KEY — значение ключа;
 * 
 * 1. Считывает информацию о часах.
 * 2.
 * - Если значение ключа равно "r", выполняет обращение списка b ds
 * - Если значение ключа равно "s", выполняет сортировку списка по стоимости
 * 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#include "../inc/mem.h"
#include "../inc/in_out.h"
#include "../inc/my_types.h"
#include "../inc/my_err.h"
#include "../inc/my_def.h"


int main(int argc, char *argv[])
{
    if (argc != COUNT_ARGS)
        return ERR_ARGS;

    FILE *in_file = fopen(argv[1], "r");
    if (!in_file)
        return ERR_FILE;

    if (argv[3][0] == REVERSE_KEY && argv[3][1] == '\0')
    {
        node_t *top = NULL;


        if (get_list(in_file, &top))
        {
            fclose(in_file);
            free_list(top);
            return ERR_READING;
        }

        FILE *out_file = fopen(argv[2], "w");
        if (!out_file)
        {
            fclose(in_file);
            free_list(top);
            return ERR_FILE;
        }


        write_watches(out_file, top);

        fclose(in_file);
        fclose(out_file);
        free_list(top);
    }
    else if (argv[3][0] == SORT_KEY && argv[3][1] == '\0')
    {
        return SUCCESS;
    }
    else
    {
        fclose(in_file);
        return ERR_ARGS;
    }

    return SUCCESS;
}