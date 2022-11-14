#ifndef ___MY_IN_OUT____
#define ___MY_IN_OUT____

#include <stdio.h>

#include "my_types.h"


watch_t *read_watch(FILE *f);
int get_list(FILE *f, node_t **top);
void write_watches(FILE *f, node_t *top);

#endif // ___MY_IN_OUT____