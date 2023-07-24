#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int i = 0;
	va_list vl;

	va_start(vl, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printf("%c", va_arg(vl, int));
					break;
				case 's':
					printf("%s", va_arg(vl, char*));
					break;
				case '%':
					printf("%%");
					break;
				case 'd':
				case 'i':
					printf("%d", va_arg(vl, int));
					break;
				case 'p':
					printf("%p", va_arg(vl, int *));
					break;
				case 'x':
				case 'X':
					printf("%x", va_arg(vl, int *));
					break;
				case 'u':
					printf("%u", va_arg(vl, int));
					break;
				case 'o':
					printf("%o", va_arg(vl, int));
					break;
				case 'r':
					printf("%r");
					break;
				default:
					printf("%c", format[i]);
					break;
			}
		}
		else
		{
			printf("%c", format[i]);
		}
		i++;
	}
	return (i - 1);
	va_end(vl);
}
