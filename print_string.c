#include "main.h"

int print_s(va_list list)
{
    const char *str = va_arg(list, const char *);
    int count = 0;
    while (*str)
    {
        write(1, str, 1);
        str++;
        count++;
    }
    return count;
}

