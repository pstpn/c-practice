#ifndef ___MY_STRUCTS___
#define ___MY_STRUCTS___

#include <stdio.h>

#include "my_struct.h"

int read_struct(FILE *f, char *title, char *name, int *year);
void replace_structs(film_t (*films)[MAX_LENGTH + 1], const int ind_1, const int ind_2);
int get_structs_and_sort(FILE *f, film_t (*films)[], int *len, char sort_field);
int binary_search(film_t (*films)[], int len, char sort_field, char *key);
void print_structs(int len, film_t films[]);

#endif // ___MY_STRUCTS___