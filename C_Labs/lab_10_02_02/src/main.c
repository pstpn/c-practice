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


    if (get_type(op_type))
        return ERR_READING;

    if (strcmp(op_type, VAL) == EQUIL)
    {
        node_t *head = calloc(1, sizeof(node_t));
        if (!head)
            return ERR_ALLOC;

        head->next = NULL;

        int a;
        int count;


        if (read_val(&count, head, &a))
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
        
    }
    else if (strcmp(op_type, SUM) == EQUIL)
    {
        
    }
    else if (strcmp(op_type, DVD) == EQUIL)
    {
        
    }
    else
        return ERR_READING;
    

    return SUCCESS;
}