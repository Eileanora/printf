#include "functions.h"
/**
 * print_string - print a string
 * @args: list of arguments
 * Return: number of characters printed
*/
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}