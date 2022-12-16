/**
 * @file mem.c
 * @author Stepan Postnov
 * @brief 
 * @version 0.1
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>

#include "list_funcs.h"
#include "my_types.h"
#include "my_def.h"


/**
 * @brief Free list nodes
 * 
 * @param top 
 */
void free_list(node_t *top)
{
    for (; top;)
        pop_front(&top);
}