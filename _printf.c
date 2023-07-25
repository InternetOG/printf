#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - Entry point
 *@format: print char
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	int lp = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					lp += printf("%c", va_arg(args, int));
					break;
				case 's':
					lp += printf("%s", va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					lp += printf("%d", va_arg(args, int));
					break;
				case 'u':
					lp += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					lp += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					lp += printf("%x", va_arg(args, int *));
					break;
				case 'X':
					lp += printf("%X", va_arg(args, int *));
					break;
				case 'p':
					lp += printf("%p", va_arg(args, void *));
					break;
				case '%':
					lp += printf("%%");
					break;
				default:
					 lp += printf("%%%c", *format);
					break;
			}
		} else 
		{
			lp += printf("%c", *format);
		}
		format++;
	}
	va_end(args);
	return (lp);
}
