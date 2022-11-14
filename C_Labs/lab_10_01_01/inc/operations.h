#ifndef ___MY_OPERATIONS___
#define ___MY_OPERATIONS___

#include "my_types.h"


node_t *reverse(node_t *head);
void sorted_insert(node_t **head, node_t *element,
int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

#endif // ___MY_OPERATIONS___