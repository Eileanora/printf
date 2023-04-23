#include "functions.h"

/**
 * _printf - print a string with format specifiers
 * @format: string to print
 * Return: number of characters printed
*/
int _printf(char *format, ...)
{
	va_list args;
	int i, bytes = 0;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
			bytes += percent(format, i, args), i++;
		else if (format[i] == '\\')
			bytes += backslash(format, i), i++;
		else
			bytes += print_any_char(format[i]);
	}
	va_end(args);
	return (bytes);
}
