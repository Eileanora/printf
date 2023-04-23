#include "functions.h"

/**
 * backslash - check the character after a backslash
 * @format: format string
 * @i: index of format string
 * Return: 1 if character is valid, 0 if not
*/

int backslash(char *format, int i)
{
	char c = format[i + 1];
	if (c && (c == '\\' || c == '\"' || c == '\'' || c == '%'))
	{
		print_any_char(c);
		return (1);
	}
	/* check if it's \n , \t , and so on and print them */
	if (c && (c == 'n' || c == 't' || c == 'r' || c == 'b' || c == 'f'))
	{
		if (c == 'n')
			print_any_char('\n');
		if (c == 't')
			print_any_char('\t');
		if (c == 'r')
			print_any_char('\r');
		if (c == 'b')
			print_any_char('\b');
		if (c == 'f')
			print_any_char('\f');
		return (1);
	}
	return (0);
}
