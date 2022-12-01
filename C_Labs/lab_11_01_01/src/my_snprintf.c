#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#include "../inc/my_def.h"
#include "../inc/tools.h"


int my_snprintf(char *restrict buff, size_t b_size, const char *restrict format, ...)
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

    size_t len = format_len;

    va_list cur_param;
    va_start(cur_param, format);


    i = 0;

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] == 's')
        {
            char *cur_str = va_arg(cur_param, char *);

            int k = 0;

            
            if (!b_size || !buff)
                while (cur_str[k++] != '\0')
                    ++len;
            else
                while (cur_str[k] != '\0')
                {
                    ++len;
                    buff[j++] = cur_str[k++];
                }

            i += 2;
        }
        else if (format[i] == '%' && format[i + 1] == 'h' && format[i + 2] == 'o')
        {
            uint16_t cur_digit = (uint16_t) va_arg(cur_param, int);
            char bin_buf[BIN_STR_LEN + 1] = { '\0' };
            

            if (!cur_digit)
            {
                if (b_size && buff)
                    buff[j++] = '0';
                
                ++len;
            }
            else
            {
                int cur_len = dec_to_bin(cur_digit, bin_buf);


                if (cur_len % 3 == 1)
                    for (int j = 0; j < 2; ++j)
                    {
                        for (int k = cur_len - 1; k >= 0; --k)
                            bin_buf[k + 1] = bin_buf[k];

                        bin_buf[0] = '0';
                        ++cur_len;
                    }
                else if (cur_len % 3 == 2)
                {
                    for (int k = cur_len - 1; k >= 0; --k)
                        bin_buf[k + 1] = bin_buf[k];

                    bin_buf[0] = '0';
                }

                for (int i = 0; bin_buf[i] != '\0'; i += 3)
                {
                    int cur_oct_digit = 0;

                    cur_oct_digit += (bin_buf[i] == '1') ? 4 : 0;
                    cur_oct_digit += (bin_buf[i + 1] == '1') ? 2 : 0;
                    cur_oct_digit += (bin_buf[i + 2] == '1') ? 1 : 0;

                    buff[j++] = cur_oct_digit + '0';
                    ++len;
                }
            }
            
            i += 3;
        }
        else
        {
            if (b_size && buff)
                buff[j++] = format[i];

            --format_len;
            ++i;
        }
    }

    if (buff)
    {
        if (b_size > len)
            buff[len - 1] = '\0';
        else
            buff[b_size - 1] = '\0';
    }
    
    va_end(cur_param);

    return --len;
}
