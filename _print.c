#include "main.h"

int (*pick_f(const char *format))(va_list)
{
	int i;
	spec pick[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_n},
		{NULL, NULL}
	};

	for (i = 0; pick[i].f_spec; i++)
	{
		if (pick[i].f_spec[0] == *format)
		{
			return pick[i].f;
		}
	}

	return NULL;
}

int _printf(const char *format, ...)
{
	va_list list;
	int (*f)(va_list);
	unsigned int count = 0;
	unsigned int i = 0;

	if (format == NULL)
	{
		return -1;
	}

	va_start(list, format);

	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}

		if (format[i] == '\0')
		{
			break;
		}

		f = pick_f(&format[i + 1]);
		if (f != NULL)
		{
			count += f(list);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			if (format[i + 1] == '%')
			{
				i += 2;
			}
			else
			{
				i++;
			}
		}
	}

	va_end(list);
	return count;
}
