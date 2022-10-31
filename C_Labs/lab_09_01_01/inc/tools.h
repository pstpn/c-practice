#ifndef ___MY_TOOLS____
#define ___MY_TOOLS____

#include <stdio.h>

#include "../inc/my_def.h"


int does_the_field_exist(char *field, char correct_fields[NUMBER_OF_FIELDS][MAX_FIELD_LENGTH + 1]);
int is_correct_digit(const char *str);

#endif // ___MY_TOOLS____