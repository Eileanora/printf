#include "functions.h"
/**
 * print_per - print percentage sign
 * 
*/
int percent(char *format, int i, va_list args)
{
	char c = format[i + 1];
		printer_t _printer[] = {
		{"i", print_int},
		{"c", print_char},
		{"s", print_string},
		{"d", print_int}
	};
	int j = 0, bytes = 0;
	
	while (j < 4)
	{
		if (c && c == _printer[j].symbol[0])
		{
			bytes = _printer[j].print(args);
			break;
		}
		j++;
	}
	if (j == 4)
	{
		bytes = print_any_char('%');
		bytes += print_any_char(c);
	}
	return (bytes);
}
