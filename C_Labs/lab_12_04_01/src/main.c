/**
 * @file main.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий главную функцию проекта
 * 
 * TASK:
 * 
 * Написать программу, которая упорядочивает данные в целочисленном массиве по воз-
 * растанию. Данные в массив считываются из текстового файла. Память под массив выде-
 * ляется динамически. Количество элементов в файле не указано и определяется при первом
 * проходе по текстовому файлу, во время второго прохода числа считываются в массив. 
 * Требуется написать программу, которая, будучи вызванной из командной строки:
 * 
 * app.exe IN_FILE OUT_FILE [f]
 * 
 * где IN_FILE — имя файла с входными данными, OUT_FILE — имя файла с выходными
 * данными, f — запрос фильтрации перед сортировкой;
 * 
 * 1. Считает количество элементов, записанных в файле.
 * 2. Выделяет память под соответствующее количество элементов.
 * 3. Читает файл ещё раз, заполняя динамический массив.
 * 4. Если указан параметр f, вызывает функцию-фильтр.
 * 5. Сортирует массив с новыми элементами с помощью назначенного преподавателем
 * алгоритма сортировки.
 * 6. Записывает элементы отсортированного массива в текстовый файл.
 * 
 * Функция-фильтр работает следующим образом:
 * 
 * 1. определяет количество элементов массива, которые удовлетворяют заданному усло-
 * вию;
 * 2. выделяет память под соответствующее количество элементов;
 * 3. копирует элементы, удовлетворяющие условию, из старого массива в новый.
 * Функция-фильтр имеет следующие название и прототип:
 * 
 * int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
 * 
 * На вход функции-фильтру могут поступать некорректные данные.
 * Функция сортировки реализуется универсальной, т. е. имеет одинаковый прототип с
 * функцией qsort из стандартной библиотеки и называется mysort.
 * Кроме того, необходимо сравнить время работы реализованного алгоритма сортировки
 * и qsort. Постарайтесь найти примеры, когда ваша реализация лучше. Результаты пред-
 * ставьте в виде графиков (рисунки в формате PNG или любом аналогичном векторном, оси
 * подписаны). Графики разместить в Wiki на отдельной странице. Графики можно строить
 * любыми средствами (например, в Excel, gnuplot).
 * 
 * ВАРИАНТ СОРТИРОВКИ:
 * 
 * 6. Модифицированная сортировка пузырьком II: нечётные и чётные проходы выпол-
 * няются в противоположных направлениях: нечётные проходы от начала к концу,
 * чётные – от конца массива к его началу. При нечётных проходах большие элементы
 * сдвигаются к концу массива, а при чётных проходах – меньшие элементы двигаются
 * к его началу.
 * 
 * ВАРИАНТ ФУНКЦИИ-ФИЛЬТРА:
 * 
 * 4. В массиве остаются элементы, которые больше среднего арифметического всех эле-
 * ментов массива.
 * 
 * @version 0.1
 * @date 2022-12-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "lib_arr.h"
#include "my_types.h"
#include "tools.h"
#include "my_err.h"
#include "my_def.h"

#ifndef DYNAMIC
int IS_DYN = 0;
in_out_t tmp_array_filling = (in_out_t) array_filling;
in_out_t tmp_writing_to_file = (in_out_t) writing_to_file;
key_t tmp_key = (key_t) key;
mysort_t tmp_mysort = (mysort_t) mysort;
#else
int IS_DYN = 1;
in_out_t tmp_array_filling = NULL;
in_out_t tmp_writing_to_file = NULL;
key_t tmp_key = NULL;
mysort_t tmp_mysort = NULL;
#endif


int main(int argc, char **argv)
{
    void *arr_lib = NULL;

    in_out_t array_filling = tmp_array_filling;
    in_out_t writing_to_file = tmp_writing_to_file;

    key_t key = tmp_key;

    mysort_t mysort = tmp_mysort;


    if (IS_DYN)
    {
        arr_lib = dlopen("./libs/lib_arr.so", RTLD_NOW);
        if (!arr_lib)
        {
            printf("%s\n", dlerror());
            return OPEN_LIB_ERROR;
        }

        array_filling = (in_out_t) dlsym(arr_lib, "array_filling");
        if (!array_filling)
        {
            dlclose(arr_lib);
            return OPEN_LIB_ERROR;
        }

        writing_to_file = (in_out_t) dlsym(arr_lib, "writing_to_file");
        if (!writing_to_file)
        {
            dlclose(arr_lib);
            return OPEN_LIB_ERROR;
        }

        key = (key_t) dlsym(arr_lib, "key");
        if (!key)
        {
            dlclose(arr_lib);
            return OPEN_LIB_ERROR;
        }

        mysort = (mysort_t) dlsym(arr_lib, "mysort");
        if (!mysort)
        {
            dlclose(arr_lib);
            return OPEN_LIB_ERROR;
        }
    }

    
    if (argc < MIN_ARGS_COUNT || argc > MAX_ARGS_COUNT)
    {
        if (IS_DYN)
            dlclose(arr_lib);
        return INCORRECT_ARGS_COUNT;
    }

    FILE *f = fopen(*(++argv), "r");

    int count = 0;


    if (f == NULL)
    {
        if (IS_DYN)
            dlclose(arr_lib);
        return INCORRECT_FILENAME;
    }

    if (get_count(f, &count) || !count)
    {
        if (IS_DYN)
            dlclose(arr_lib);
        fclose(f);
        return INCORRECT_FILE;
    }
    rewind(f);

    int *arr_ptr = malloc(count * sizeof(int)),
    *p_end = arr_ptr + count, *cur_ptr = arr_ptr;


    if (arr_ptr == NULL)
    {
        if (IS_DYN)
            dlclose(arr_lib);
        return MEMORY_ERROR;
    }

    array_filling(f, cur_ptr, p_end);

    fclose(f);

    FILE *g = fopen(*(++argv), "w");
    if (g == NULL)
    {
        if (IS_DYN)
            dlclose(arr_lib);
        free(arr_ptr);
        return INCORRECT_ARGS;
    }

    if (argc == MAX_ARGS_COUNT)
    {
        if (**(++argv) != 'f' || *(++(*argv)) != '\0')
        {
            if (IS_DYN)
                dlclose(arr_lib);
            free(arr_ptr);
            return INCORRECT_ARGS;
        }
        
        int *pcur_new = NULL, *pend_new = NULL;
        int new_count = 0;


        if (key(cur_ptr, p_end, &pcur_new, &pend_new, &new_count) ||
            !new_count)
        {
            if (IS_DYN)
                dlclose(arr_lib);
            fclose(g);
            free(arr_ptr);
            return INCORRECT_ARR;
        }

        pcur_new = malloc(new_count * sizeof(int));
        if (!pcur_new)
        {
            if (IS_DYN)
                dlclose(arr_lib);
            return MEMORY_ERROR;
        }

        cur_ptr = arr_ptr;
        if (key(cur_ptr, p_end, &pcur_new, &pend_new, &new_count))
        {
            if (IS_DYN)
                dlclose(arr_lib);
            fclose(g);
            free(arr_ptr);
            return INCORRECT_ARR;
        }

        cur_ptr = pcur_new;
        mysort(cur_ptr, pend_new - cur_ptr, sizeof(int), compare_int);

        cur_ptr = pcur_new;
        writing_to_file(g, cur_ptr, pend_new);

        free(pcur_new);
    }

    if (argc != MAX_ARGS_COUNT)
    {
        cur_ptr = arr_ptr;
        mysort(cur_ptr, count, sizeof(int), compare_int);

        cur_ptr = arr_ptr;
        writing_to_file(g, cur_ptr, p_end);
    }

    free(arr_ptr);
    fclose(g);

    if (IS_DYN)
        dlclose(arr_lib);

    return SUCCESS;
}