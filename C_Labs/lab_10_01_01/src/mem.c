#include <stdlib.h>

#include "../inc/list_funcs.h"
#include "../inc/my_types.h"


void free_list(node_t *top)
{
    for (; top && top->next; top = top->next)
        free(pop_front(&top));
}