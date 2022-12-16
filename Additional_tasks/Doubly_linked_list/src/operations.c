/**
 * @file operations.c
 * @author Stepan Postnov
 * @brief 
 * @version 0.1
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "my_types.h"
#include "list_funcs.h"
#include "my_def.h"
#include "mem.h"


/**
 * @brief Comparator for int values
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compare_int(int a, int b)
{
    return a - b;
}


/**
 * @brief Help function for sort
 * 
 * @param head 
 * @param element 
 */
void sorted_insert(node_t **head, node_t *element)
{
    if (!(*head))
        *head = element;
    else
    {
        node_t *cur = NULL;
        node_t *tmp = *head;


        for (; tmp; tmp = tmp->next_node)
        {
            if (compare_int(tmp->value, element->value) > EQUIL)
            {
                if (!cur)
                {
                    element->next_node = *head;
                    (*head)->prev_node = element;
                    *head = element;
                    return;
                }

                cur->next_node = element;
                element->prev_node = cur;
                element->next_node = tmp;
                tmp->prev_node = element;
                return;
            }

            cur = tmp;
        }

        cur->next_node = element;
        element->prev_node = cur;
    }
}


/**
 * @brief Sort list
 * 
 * @param head 
 * @return node_t* 
 */
node_t *sort(node_t *head)
{
    if (!head)
        return NULL;

    char pop_data = pop_front(&head);

    node_t *new_head = calloc(1, sizeof(node_t));
    if (!new_head)
        return NULL;

    new_head->value = pop_data;
    new_head->next_node = NULL;
    new_head->prev_node = NULL;


    for (; head;)
    {
        node_t *tmp = calloc(1, sizeof(node_t));
        if (!tmp)
        {
            free_list(new_head);
            return NULL;
        }

        pop_data = pop_back(&head);
        
        tmp->value = pop_data;
        tmp->next_node = NULL;
        tmp->prev_node = NULL;
        
        sorted_insert(&new_head, tmp);
    }

    return new_head;
}