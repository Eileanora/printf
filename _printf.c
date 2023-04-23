#include "functions.h"

/**
 * _printf - print a string with format specifiers
 * @format: string to print
 * Return: number of characters printed
*/
int _printf(char *format, ...)
{
	va_list args;
	int i, j;

	const char *seperator = "";
	printer_t _printer[] = {
		{"i", print_int},
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	/* case 1*/
	if (format == NULL)
		return (-1);
	
	va_start(args, format);
	/* iterate untill we find a percentage sign */
	va_end(args);
	return (0);
}
