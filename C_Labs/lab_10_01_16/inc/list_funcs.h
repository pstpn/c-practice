#ifndef ___LIST_FUNCS___
#define ___LIST_FUNCS___

#include "my_types.h"


node_t *list_add_end(node_t *head, node_t *new_node);
void *pop_front(node_t **head);
void *pop_back(node_t **head);

#endif // ___LIST_FUNCS___