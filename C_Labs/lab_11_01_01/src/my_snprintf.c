#include <stdio.h>
#include <stdarg.h>


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


    i = 0;

    va_list cur_param;
    va_start(cur_param, format);
        
    
    while (format_len)
    {
        if (format[i] == '%' && format[i + 1] == 's')
        {
            char *cur_str = va_arg(cur_param, char *);

            int k = 0;


            if (!cur_str)
                cur_str = "(null)\0";
            
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
            unsigned short cur_digit = (unsigned short) va_arg(cur_param, int);

            int buf = 0;
            int count = 0;

            unsigned short factor_001 = 1;
            unsigned short factor_010 = 2;
            unsigned short factor_100 = 4;
            

            if (!cur_digit)
            {
                if (b_size && buff)
                    buff[j++] = '0';
                
                ++len;
            }
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
                    if (b_size && buff)
                        buff[j++] += buf % 10 + '0';

                    buf /= 10;

                    --count;
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
        if (j >= b_size - 1)
            buff[b_size - 1] = '\0';
        else
            buff[--j] = '\0';
    }
    
    va_end(cur_param);

    return --len;
}
