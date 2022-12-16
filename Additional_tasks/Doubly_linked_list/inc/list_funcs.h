#ifndef ___LIST_FUNCS___
#define ___LIST_FUNCS___

#include "my_types.h"


node_t *list_add_end(node_t *head, node_t *new_node);
char *pop_front(node_t **head);
char *pop_back(node_t **head);
int del_list_elem(node_t **head, char del_elem);

#endif // ___LIST_FUNCS___