#ifndef ___MY_SNPRINTF___
#define ___MY_SNPRINTF___

#include <stdint.h>


int dec_to_bin(uint16_t x, char *ans_str);
int my_snprintf(char *restrict buff, size_t b_size, const char *restrict format, ...);

#endif // ___MY_SNPRINTF___