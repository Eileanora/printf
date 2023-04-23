#include "main.h"
/**
 * percent - check the character after a percent
 * @format: format string
 * @i: index of format string
 * @args: list of arguments
 * Return: number of bytes printed
*/
int percent(char *format, int i, va_list args)
{
	char c = format[i + 1];
		printer_t _printer[] = {
		{"i", print_int},
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hexa},
		{"X", print_hexa_uper}
	};
	int j = 0, bytes = 0;

	while (j < 8)
	{
		if (c && c == _printer[j].symbol[0])
		{
			bytes = _printer[j].print(args);
			break;
		}
		j++;
	}
	if (j == 8)
	{
		if (c == '%')
			bytes = print_any_char(c);
		else
			bytes = print_any_char('%') + print_any_char(c);
	}
	return (bytes);
}
