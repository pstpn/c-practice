#include <stdlib.h>

#include "list_funcs.h"
#include "my_types.h"
#include "my_def.h"


void free_list(node_t *top)
{
    for (; top;)
        pop_front(&top);
}