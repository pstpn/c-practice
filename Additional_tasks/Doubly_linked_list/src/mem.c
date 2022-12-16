#include <stdlib.h>

#include "list_funcs.h"
#include "my_types.h"


void free_list(node_t *top)
{
    for (; top;)
        pop_front(&top);
}