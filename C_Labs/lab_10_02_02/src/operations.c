#include <math.h>

#include "../inc/my_types.h"


int get_val(node_t *head, int count, int a)
{
    int p = 0;
    int degree = count - 1;


    for (node_t *cur = head; cur; cur = cur->next, --degree)
        p += cur->elem * ((int) pow(a, degree));

    return p;
}