#include <stdlib.h>

#include "../inc/my_types.h"


void list_add_end(node_t **head, node_t *new_node)
{
    node_t *cur_node = *head;
    if (!cur_node)
    {
        *head = new_node;
        return;
    }


    while (cur_node->next)
        cur_node = cur_node->next;

    cur_node->next = new_node;
}


int pop_front(node_t **head)
{
    node_t *cur = (*head)->next;

    int pop_data = (*head)->elem;


    free(*head);

    *head = cur;

    return pop_data;
}