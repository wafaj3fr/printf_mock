#include "main.h"

int print_n(va_list list)
{
	int n = va_arg(list, int);
	int count = 0;
	char buffer[20];
	int len = snprintf(buffer, sizeof(buffer), "%d", n);
	if (len > 0)
	{
		write(1, buffer, len);
		count += len;
	}
	return count;
}
