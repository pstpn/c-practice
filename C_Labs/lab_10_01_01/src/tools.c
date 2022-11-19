#include <string.h>
#include <stdio.h>

#include "../inc/my_def.h"
#include "../inc/my_types.h"


int compare_int(const void *a, const void *b)
{
    const int c = ((watch_t *) a)->price;
    const int d = ((watch_t *) b)->price;


    return (c > d) ? MORE : LESS;
}


int cmp_watches(node_t *top_1, node_t *top_2)
{
    for (node_t *cur_1 = top_1, *cur_2 = top_2;
        cur_1 && cur_2; cur_1 = cur_1->next, cur_2 = cur_2->next)
        if (strcmp(((watch_t *) (cur_1->data))->model, ((watch_t *) (cur_2->data))->model)
            || ((watch_t *) (cur_1->data))->price != ((watch_t *) (cur_2->data))->price)
            return FALSE;

    return TRUE;
}