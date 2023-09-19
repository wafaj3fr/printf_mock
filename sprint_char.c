#include "main.h"

int print_c(va_list list)
{
	char c = va_arg(list, int);
	write(1, &c, 1);
	return 1;
}
