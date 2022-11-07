#include <stdio.h>

#include "../inc/my_types.h"


node_t *reverse(node_t *head)
{
    node_t *cur = NULL;
    node_t *tmp = head;
    node_t *new_head = head;


    for (; !cur && new_head->next; new_head = new_head->next)
        ;

    if (tmp->next)
        tmp->next = reverse(tmp);

    if (!cur)
    {
        head->next = NULL;

        return new_head;
    }

    return cur;
}