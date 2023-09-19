#include "main.h"

// Define print functions for various format specifiers
int print_c(va_list list)
{
    char c = va_arg(list, int);
    write(1, &c, 1); // Use write to print the character
    return 1;
}
