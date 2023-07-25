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
					printf("%c", va_arg(args, int));
					lp++;
					break;
				case 's':
					printf("%s", va_arg(args, char *));
					lp++;
					break;
				case 'd':
				case 'i':
					printf("%d", va_arg(args, int));
					lp++;
					break;
				case 'u':
					printf("%u", va_arg(args, int));
					lp++;
					break;
				case 'o':
					printf("%o", va_arg(args, int));
					lp++;
					break;
				case 'x':
				case 'X':
					printf("%x", va_arg(args, int *));
					lp++;
					break;
				case 'p':
					printf("%p", va_arg(args, int *));
					lp++;
					break;
				case '%':
					printf("%%");
					lp++;
					break;
				default:
					 printf("%%%c", *format);
					 lp++;
					break;
			}
		} else 
		{
			printf("%c", *format);
			lp++;
		}
		format++;
	}
	va_end(args);
	return (lp);
}
