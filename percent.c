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
		{"%", print_per}
	};
	int j = 0, bytes = 0;
	
	while (j < 4)
	{
		if (c && c == _printer[j].symbol)
		{
			bytes = _printer[j].print(args);
			break;
		}
		j++;
	}
	return (bytes);
}
