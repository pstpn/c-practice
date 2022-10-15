/**
 * @file main.c
 * @author Stepan Postnov ICS7-31B
 * @brief 
 * 
 * TASK:
 * 
 * Написать программу для работы с матрицами, которая реализует сложение матриц,
 * умножение матриц и указанную ниже операцию.
 * Память под матрицы выделяется динамически.
 * Исходные матрицы читаются из файла, Результирующая матрица или число записы-
 * ваются в файл. Один файл содержит одну матрицу.
 * Тестирование выполняется с помощью сравнения полученного результата с ожидае-
 * мым. При этом нужно помнить, что сравнивать вещественные числа на равенство можно
 * только с заданной точностью.
 * Имена файлов и выполняемая операция указывается через параметры командной стро-
 * ки. Формат запуска приложения должен быть следующим:
 * 
 * app.exe action mtr_1.txt [mtr_2.txt] res.txt
 * 
 * Возможные значения action:
 * 1. a — сложение;
 * 2. m — умножение;
 * 3. o — операция нахождения определителя методом Гаусса
 * 
 * MEMORYALLOC:
 * 
 * 2. Объединённый подход, способ 1: при этом способе хранения данные хранятся единым
 * блоком построчно. В памяти размещается, помимо данных, массив указателей на
 * строки
 * 
 * FILEFORMAT:
 * 
 * 1. Простой формат: количество строк и столбцов матрицы указывается в первой стро-
 * ке файла, остальные строки содержат сами элементы.
 * 
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../inc/my_def.h"
#include "../inc/my_err.h"
#include "../inc/tools.h"
#include "../inc/w_w_mtrx.h"


int main(int argc, char **argv)
{
    if (argc != MIN_ARGS && argc != MAX_ARGS)
        return ERR_ARGS;

    FILE *f = fopen(argv[2], "r");
    if (f == NULL)
        return ERR_FILE;

    int n_1, m_1;


    if (get_size(f, &n_1, &m_1))
    {
        fclose(f);
        return ERR_GET_SIZE;
    }

    double **mtrx_1 = allocate_matrix(n_1, m_1);
    if (mtrx_1 == NULL)
    {
        fclose(f);
        return ERR_ALLOC;
    }

    if (filling_matrix(f, mtrx_1, n_1, m_1))
    {
        fclose(f);
        free_matrix(mtrx_1, 1);
        return ERR_READING;
    }

    fclose(f);

    if (argc == MAX_ARGS && argv[1][0] == 'a' &&
    argv[1][1] == '\0')
    {
        FILE *g = fopen(argv[3], "r");
        if (g == NULL)
            return ERR_FILE;

        int n_2, m_2;


        if (get_size(g, &n_2, &m_2) || n_2 != n_1 || m_1 != m_2)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            return ERR_GET_SIZE;
        }

        double **mtrx_2 = allocate_matrix(n_2, m_2);
        if (mtrx_2 == NULL)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            return ERR_ALLOC;
        }

        if (filling_matrix(g, mtrx_2, n_2, m_2))
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            free_matrix(mtrx_2, 1);
            return ERR_READING;
        }

        FILE *res = fopen(argv[4], "w");
        if (res == NULL)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            free_matrix(mtrx_2, 1);
            return ERR_FILE;
        }

        matrix_addition_and_write(res, mtrx_1, mtrx_2, n_1, m_1);
        
        free_matrix(mtrx_2, 1);
        fclose(res);
        fclose(g);
    }
    else if (argc == MAX_ARGS && argv[1][0] == 'm' &&
    argv[1][1] == '\0')
    {
        FILE *g = fopen(argv[3], "r");
        if (g == NULL)
            return ERR_FILE;

        int n_2, m_2;


        if (get_size(g, &n_2, &m_2) || m_1 != n_2)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            return ERR_GET_SIZE;
        }

        double **mtrx_2 = allocate_matrix(n_2, m_2);
        if (mtrx_2 == NULL)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            return ERR_ALLOC;
        }

        if (filling_matrix(g, mtrx_2, n_2, m_2))
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            free_matrix(mtrx_2, 1);
            return ERR_READING;
        }

        FILE *res = fopen(argv[4], "w");
        if (res == NULL)
        {
            fclose(g);
            free_matrix(mtrx_1, 1);
            free_matrix(mtrx_2, 1);
            return ERR_FILE;
        }

        matrix_product_and_write(res, mtrx_1, mtrx_2, n_2, n_1, m_2);
        
        free_matrix(mtrx_2, 1);
        fclose(res);
        fclose(g);
    }
    else if (argc == MIN_ARGS && argv[1][0] == 'o' &&
    argv[1][1] == '\0')
    {
        if (n_1 != m_1)
            return ERR_GET_SIZE;

        FILE *res = fopen(argv[3], "w");
        if (res == NULL)
        {
            free_matrix(mtrx_1, 1);
            return ERR_FILE;
        }

        get_det_and_write(res, mtrx_1, n_1);
        
        fclose(res);
    }
    else
    {
        free_matrix(mtrx_1, 1);
        return ERR_ARGS;  
    }

    free_matrix(mtrx_1, 1);

    return SUCCESS;
}
