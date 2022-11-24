#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define SIZE 30
#define STRING "Test: %ho  %s"
#define INT_VAL 7284
#define IN_STR ""


int my_snprintf(char *restrict buff, size_t b_size, const char *restrict format, ... )
{
    size_t format_len = 0;
    size_t i = 0, j = 0;


    while (format[i] != '\0')
    {
        if (format[i] == '%')
            i += (format[i + 1] == 'h') ? 2 : 1;
        else
            ++format_len;

        ++i;
    }

    ++format_len;

    i = 0;

    if (!b_size)
    {
        buff = NULL;
        return format_len;
    }

    va_list cur_param;
    va_start(cur_param, format);
        
    
    while (format_len)
    {
        if (format[i] == '%' && format[i + 1] == 's')
        {
            char *cur_str = va_arg(cur_param, char *);

            int k = 0;


            while (cur_str[k] != '\0')
                buff[j++] = cur_str[k++];

            i += 2;
        }
        else if (format[i] == '%' && format[i + 1] == 'h' && format[i + 2] == 'o')
        {
            unsigned short cur_digit = (unsigned short) va_arg(cur_param, int);

            int buf = 0;
            int count = 0;

            unsigned short factor_001 = 1;
            unsigned short factor_010 = 2;
            unsigned short factor_100 = 4;
            

            if (!cur_digit)
                buff[j++] = '0';
            else
            {
                for (; cur_digit; ++count)
                {
                    buf *= 10;

                    buf += (cur_digit & factor_001) ? factor_001 : 0;
                    buf += (cur_digit & factor_010) ? factor_010 : 0;
                    buf += (cur_digit & factor_100) ? factor_100 : 0;

                    cur_digit >>= 3;
                }

                while (count)
                {
                    buff[j++] += buf % 10 + '0';
                    buf /= 10;
                    --count;
                }
            }
            
            i += 3;
        }
        else
        {
            buff[j++] = format[i++];
            --format_len;
        }

        if (j > b_size - 1)
        {
            buff[b_size - 1] = '\0';
            return b_size - 1;
        }
    }

    buff[j] = '\0';
    
    va_end(cur_param);

    return j;
}


int main(void)
{
    char *buf = malloc(SIZE + 1);
    char *my_buf = malloc(SIZE + 1);

    char *string = STRING;

    int out = snprintf(buf, SIZE, string, INT_VAL, IN_STR);
    int my_out = my_snprintf(my_buf, SIZE, string, INT_VAL, IN_STR);


    printf("SNPRINTF:\nCOUNT: %d\nSTR: \"%s\"\n\n", out, buf);
    printf("MY_SNPRINTF:\nCOUNT: %d\nSTR: \"%s\"\n", my_out, my_buf);

    free(buf);
    free(my_buf);

    return 0;
}
