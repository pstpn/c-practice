/**
 * @file lib_arr.c
 * @author Stepan Postnov ICS7-31B
 * @brief Библиотека для работы с массивами на языке Python
 * 
 * TASK:
 * 
 * Реализовать заданные преподавателем функции в виде динамической библиотеки. Язык
 * реализации библиотеки — Си.
 * Библиотеку использовать в скрипте на Python. Скрипт на Python должен предостав-
 * лять графический интерфейс для взаимодействия. Для организации взаимодействия меж-
 * ду библиотекой на Си и Python использовать модуль ctypes.
 * Выделение памяти на вызывающей стороне реализовать двумя способами:
 * 1. выполнить оценку максимально возможного размера массива и выделить память с
 * запасом;
 * 2. сначала вызвать функцию библиотеки, чтобы узнать требуемый размер массива,
 * затем выделить память и повторно вызвать функцию.
 * Написание модуля расширения для библиотеки необязательно.
 * 
 * Вариант 2
 * 
 * 1. Реализовать функцию заполнения массива числами Фибоначчи.
 * 2. Реализовать функцию, которая из одного массива помещает во второй массив
 * первое вхождение каждого элемента первого массива.
 * 
 * @version 0.1
 * @date 2022-12-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdint.h>

#include "my_def.h"


void create_fib_arr(uint64_t *fib_arr, uint64_t count)
{
    uint64_t a = 0, b = 1;


    fib_arr[0] = a;

    if (count > 1)
    {
        uint64_t buf;


        fib_arr[1] = b;

        for (uint64_t i = 2; i < count; ++i)
        {
            fib_arr[i] = a + b;
            
            buf = a;
            a = b;
            b += buf;
        }
    }
}


int is_copy(int *arr, int count, int num, int ind)
{
    for (int i = 0; i < ind; ++i)
        if (arr[i] == num)
            return TRUE;

    return FALSE;
}


int del_dublicates(int *src_arr, int *src_count, int *dst_arr)
{
    int dst_len = 0;


    for (int i = 0; i < *src_count; ++i)
        if (!is_copy(src_arr, *src_count, src_arr[i], i))
            ++dst_len;

    if (dst_arr)
        for (int i = 0, j = 0; i < *src_count; ++i)
            if (!is_copy(src_arr, *src_count, src_arr[i], i))
                dst_arr[j++] = src_arr[i];

    return dst_len;
}