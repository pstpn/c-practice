#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../inc/list_funcs.h"
#include "../inc/in_out.h"
#include "../inc/mem.h"
#include "../inc/my_def.h"


node_t *init_all_list(int count, ...)
{
    node_t *head = NULL;

    va_list cur_elem;
    va_start(cur_elem, count);


    for (; count > 0; --count)
    {
        node_t *cur_node = calloc(1, sizeof(node_t));


        cur_node->next = NULL;

        cur_node->elem = va_arg(cur_elem, int);

        list_add_end(&head, cur_node);
    }

    va_end(cur_elem);

    return head;
}


int cmp_lists(node_t *top_1, node_t *top_2)
{
    for (node_t *cur_1 = top_1, *cur_2 = top_2;
        cur_1 && cur_2; cur_1 = cur_1->next, cur_2 = cur_2->next)
        if (cur_1->elem != cur_2->elem)
            return FALSE;

    return TRUE;
}