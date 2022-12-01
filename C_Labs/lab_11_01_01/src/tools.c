#include <stdint.h>


int dec_to_bin(uint16_t x, char *ans_str)
{
	int i = 0;


	do
	{
		ans_str[i++] = x % 2 + '0';
		x = x / 2;
	} while (x != 0);

	ans_str[i] = '\0';
    
	int k = i - 2;
	int m = k / 2;


	for (int j = 0; j <= m; ++j)
	{
		char tmp = ans_str[j];
		ans_str[j] = ans_str[k - j + 1];
		ans_str[k - j + 1] = tmp;
	}

	return i;
}