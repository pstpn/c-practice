#include <stdio.h>
#include <stdlib.h>

#include "../inc/list_funcs.h"
#include "../inc/my_types.h"
#include "../inc/mem.h"


node_t *reverse(node_t *head)
{
    node_t *cur = head->next;
    if (!cur || !head)
        return head;

    node_t *new_head;

    
    if (cur->next)
    {
        new_head = reverse(head->next);
        cur->next = head;
    }
    else
    {
        cur->next = head;
        
        if (head->next->next == head)
            head->next = NULL;

        return cur;
    }

    if (head->next->next == head)
        head->next = NULL;
    
    return new_head;
}


void sorted_insert(node_t **head, node_t *element,
int (*comparator)(const void *, const void *))
{
    if (!(*head))
    {
        *head = element;
        return;
    }

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
    if (!head)
        return NULL;

    void *pop_data = pop_front(&head);

    node_t *new_head = calloc(1, sizeof(node_t));
    if (!new_head)
        return NULL;

    new_head->data = pop_data;
    new_head->next = NULL;


    for (; head;)
    {
        node_t *tmp = calloc(1, sizeof(node_t));
        if (!tmp)
        {
            free_list(new_head);
            return NULL;
        }

        pop_data = pop_back(&head);
        
        tmp->data = pop_data;
        tmp->next = NULL;
        sorted_insert(&new_head, tmp, comparator);
    }

    return new_head;
}