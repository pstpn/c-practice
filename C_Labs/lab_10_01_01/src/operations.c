#include <stdio.h>
#include <stdlib.h>

#include "../inc/list_funcs.h"
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


void sorted_insert(node_t **head, node_t *element,
int (*comparator)(const void *, const void *))
{
    node_t *cur = (*head);
    node_t *tmp = (*head)->next;


    if (comparator(&(((watch_t *) (cur->data))->price),
    &(((watch_t *) (element->data))->price)))
    {
        *head = element;
        element->next = cur;
        return;
    }

    for (; tmp; tmp = tmp->next, cur = cur->next)
    {
        if (comparator(&(((watch_t *) (tmp->data))->price),
        &(((watch_t *) (element->data))->price)))
        {
            cur->next = element;
            element->next = tmp;
            return;
        }
    }

    cur->next = element;
    element->next = NULL;
}


node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    void *pop_data = pop_front(&head);

    node_t *new_head = calloc(1, sizeof(node_t));
    new_head->data = pop_data;
    new_head->next = NULL;


    for (; head; )
    {
        node_t *tmp = calloc(1, sizeof(node_t));


        pop_data = pop_back(&head);
        
        tmp->data = pop_data;
        tmp->next = NULL;
        sorted_insert(&new_head, tmp, comparator);
    }

    return new_head;
}