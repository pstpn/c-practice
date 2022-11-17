#ifndef ___MY_OPERATIONS___
#define ___MY_OPERATIONS___

#include "my_types.h"


int get_val(node_t *head, int count, int a);
int get_ddx(node_t *head, node_t **ddx_head, int count);
int get_sum(node_t *first_head, node_t *second_head, node_t **sum_head, int first_count, int second_count);
int get_dvd(node_t *head, node_t **first_head, node_t **second_head, int count);

#endif // ___MY_OPERATIONS___