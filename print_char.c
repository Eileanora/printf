#include "functions.h"

/**
 * print_any_char - prints any character
 * @c: character to print
 * Return: 1
*/

int print_char(va_list args)
{
	char c = va_arg(args, int);

	fflush(stdout);
	write(1, &c, 1);
	return (1);
}
