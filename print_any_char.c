#include "functions.h"

/**
 * print_any_char - prints any character
 * @c: character to print
 * Return: 1
*/
int print_any_char(char c)
{
	fflush(stdout);
	write(1, &c, 1);
	return (1);
}
