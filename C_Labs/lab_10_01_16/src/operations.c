#include <stdio.h>

#include "../inc/my_types.h"


node_t *reverse(node_t *head)
{
    node_t *cur = head->next;

    node_t *new_head;

    
    if (cur->next)
    {
        new_head = reverse(head->next);

        cur->next = head;
    }
    else
    {
        cur->next = head;
        return cur;
    }

    if (head->next->next == head)
        head->next = NULL;
    
    return new_head;
}