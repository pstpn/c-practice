#include <stdlib.h>

#include "../inc/my_types.h"


void list_add_end(node_t *head, node_t *new_node)
{
    node_t *cur_node = head;


    for (; cur_node->next; cur_node = cur_node->next)
        ;

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


// void *pop_back(node_t **head)
// {
//     if (!(*head) || !(*head)->data)
//         return *head;

//     node_t *cur_node = *head;
//     node_t *del_node = (*head)->next;


//     for (; del_node && del_node->next; del_node = del_node->next, cur_node = cur_node->next)
//         ;

//     void *pop_data;


//     if (cur_node == *head && !del_node)
//     {
//         pop_data = cur_node->data;
//         free(cur_node);
//         (*head) = NULL;
//     }
//     else
//     {
//         pop_data = del_node->data;
//         cur_node->next = NULL;
//         free(del_node);
//     }

//     return pop_data;
// }