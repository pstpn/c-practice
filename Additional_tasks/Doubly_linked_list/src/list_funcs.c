#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assert.h"

#include "my_types.h"
#include "my_def.h"
#include "my_err.h"


node_t *list_add_end(node_t *head, node_t *new_node)
{
    node_t *cur_node = head;


    if (!head)
        return new_node;

    while (cur_node->next_node)
        cur_node = cur_node->next_node;

    cur_node->next_node = new_node;
    new_node->prev_node = cur_node;

    return head;
}


char pop_front(node_t **head)
{
    assert(head);
    assert(*head);

    node_t *alloc_head = *head;

    char pop_data = (*head)->value;

    if ((*head)->next_node)
        (*head)->next_node->prev_node = (*head)->prev_node;

    if ((*head)->prev_node)
        (*head)->prev_node->next_node = (*head)->next_node;

    if ((*head)->prev_node && !(*head)->next_node)
        *head = (*head)->prev_node;
    else
        *head = (*head)->next_node;

    free(alloc_head);

    return pop_data;
}


char pop_back(node_t **head)
{
    assert(head);
    assert(*head);

    node_t *cur_node = *head;
    node_t *del_node = (*head)->next_node;


    while (del_node && del_node->next_node)
        del_node = del_node->next_node, cur_node = cur_node->next_node;

    char pop_data;


    if (cur_node == *head && !del_node)
    {
        pop_data = cur_node->value;
        free(cur_node);
        *head = NULL;
    }
    else
    {
        pop_data = del_node->value;
        free(del_node);
        cur_node->next_node = NULL;
    }

    return pop_data;
}


int del_list_elem(node_t **head, char del_elem)
{
    for (node_t *cur = *head; cur; cur = cur->next_node)
        if (cur->value == del_elem)
        {
            pop_front(&cur);

            if (!cur)
                *head = NULL;
            else if (!cur->prev_node)
                *head = cur;

            return SUCCESS;
        }

    return NOT_FOUND;
}