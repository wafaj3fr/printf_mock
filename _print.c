#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _print(const char *format, ...)
{
	va_list list;
	va_start(list, format);
	int count = 0;
	char c, *s;
	int d;

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		// else if (*format < 32 || *format >= 127)
		// {
		//     putchar('x');
		// }
		else
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(list, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(list, char*);
				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				d = va_arg(list, int);
				if (d < 0)
				{
					putchar('-');
					count++;
					d = -d;
				}
				int divisor = 1;
				while (d / divisor > 9)
				{
					divisor *= 10;
				}
				while (divisor >= 1)
				{
					int digit = d / divisor;
					putchar('0' + digit);
					count++;
					d %= divisor;
					divisor /= 10;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		format++;
	}
	putchar('\n');
	va_end(list);
	return (count);
}

int main(void)
{
	char c = 'A';
	char b = 'b';
	int d = 12;
	char *str = "This is a string";
	_print("This is a couple of characters %c %c", c, b);
	_print("%s", str);
	// _print("%S\n", "Best\nSchool");
	_print("%d", d);
}
