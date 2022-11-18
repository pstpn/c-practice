/**
 * @file main.c
 * @author Stepan Postnov ICS7-31B
 * @brief Файл, содержащий главную функцию проекта
 * 
 * TASK:
 * 
 * (a) Реализовать подпрограмму вычисления P(a) по введённому с клавиатуры a.
 * (b) Реализовать подпрограмму вычисления производной d(P(x)) / dx
 * (c) Реализовать подпрограмму сложения двух полиномов.
 * (d) Реализовать подпрограмму разделения полинома на полиномы чётных и нечётных степеней.
 * 
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/my_err.h"
#include "../inc/my_def.h"
#include "../inc/in_out.h"
#include "../inc/my_types.h"
#include "../inc/mem.h"
#include "../inc/operations.h"


int main(void)
{
    char op_type[OPERATION_TYPE_LEN + 1] = { '\0' };


    if (get_type(stdin, op_type))
        return ERR_READING;

    if (strcmp(op_type, VAL) == EQUIL)
    {
        node_t *head = NULL;

        int a;
        int count;


        if (read_val(stdin, &count, &head, &a))
        {
            free_list(head);
            return ERR_READING;
        }

        int p = get_val(head, count, a);


        printf("%d\n", p);

        free_list(head);
    }
    else if (strcmp(op_type, DDX) == EQUIL)
    {
        node_t *head = NULL;

        int count;


        if (read_pol(stdin, &count, &head))
        {
            free_list(head);
            return ERR_READING;
        }

        node_t *ddx_head = NULL;


        if (get_ddx(head, &ddx_head, count))
        {
            free_list(ddx_head);
            free_list(head);
            return ERR_ALLOC;
        }

        print_pol(ddx_head);

        free_list(ddx_head);
        free_list(head);
    }
    else if (strcmp(op_type, SUM) == EQUIL)
    {
        node_t *first_head = NULL;
        node_t *second_head = NULL;

        int first_count;
        int second_count;


        if (read_pol(stdin, &first_count, &first_head))
        {
            free_list(first_head);
            return ERR_READING;
        }
        if (read_pol(stdin, &second_count, &second_head))
        {
            free_list(first_head);
            free_list(second_head);
            return ERR_READING;
        }

        node_t *sum_head = NULL;


        if (get_sum(first_head, second_head, &sum_head, first_count, second_count))
        {
            free_list(sum_head);
            free_list(first_head);
            free_list(second_head);
            return ERR_ALLOC;
        }

        print_pol(sum_head);

        free_list(sum_head);
        free_list(first_head);
        free_list(second_head);
    }
    else if (strcmp(op_type, DVD) == EQUIL)
    {
        node_t *head = NULL;

        int count;


        if (read_pol(stdin, &count, &head))
        {
            free_list(head);
            return ERR_READING;
        }

        node_t *first_head = NULL;
        node_t *second_head = NULL;


        if (get_dvd(head, &first_head, &second_head, count))
        {
            free_list(first_head);
            free_list(second_head);
            free_list(head);
            return ERR_ALLOC;
        }

        print_pol(first_head);
        print_pol(second_head);

        free_list(first_head);
        free_list(second_head);
        free_list(head);
    }
    else
        return ERR_READING;
    
    return SUCCESS;
}