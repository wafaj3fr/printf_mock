#include <limits.h>
#include "main.h"

/**
 * pick_f - functions that matches specifiers to there functions
 * @format: the format
 * Return: pointer to the function selected
*/

int (*pick_f(const char *format))(va_list)
{
	int i;
	spec pick[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_n},
		{"i", print_n},
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
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	return (0);
}
