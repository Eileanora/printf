#include "functions.h"

/**
 * print_char - print a character
 * @args: list of arguments
 * Return: number of characters printed
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	fflush(stdout);
	write(1, &c, 1);
	return (1);
}
