#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/my_types.h"
#include "../inc/my_def.h"
#include "../inc/my_err.h"


node_t *list_add_end(node_t *head, node_t *new_node)
{
    node_t *cur_node = head;


    if (!head)
        return new_node;

    for ( ; cur_node->next; cur_node = cur_node->next)
        ;

    cur_node->next = new_node;

    return head;
}


void *pop_front(node_t **head)
{
    node_t *cur = *head;


    void *pop_data = (*head)->data;


    *head = (*head)->next;

    free(cur);

    return pop_data;
}


void *pop_back(node_t **head)
{
    if (!(*head))
        return NULL;

    node_t *cur_node = *head;
    node_t *del_node = (*head)->next;


    for ( ; del_node->next; del_node = del_node->next, cur_node = cur_node->next)
        ;

    if (cur_node == *head)
    {
        *head = NULL;
        return cur_node->data;
    }
    else
    {
        cur_node->next = NULL;
        return del_node->data;
    }
}