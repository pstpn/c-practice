#ifndef ___MY_TOOLS___
#define ___MY_TOOLS___

#include "my_def.h"

int does_the_field_exist(char *field, char correct_fields[NUMBER_OF_FIELDS][MAX_FIELD_LENGTH + 1]);
int strcmp_al(const char *str_1, const char *str_2);
int is_correct_digit(const char *str);
int is_correct_key(char *key);
int get_param(char *param, char *ptr);

#endif // ___MY_TOOLS___