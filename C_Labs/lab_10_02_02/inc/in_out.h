#ifndef ___MY_IN_OUT____
#define ___MY_IN_OUT____

#include "my_types.h"


int get_type(char *type);
int read_pol(int *count, node_t **head);
int read_val(int *count, node_t **head, int *a);
void print_pol(node_t *head);

#endif // ___MY_IN_OUT____