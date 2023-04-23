#include "main.h"

/**
 * print_octal - prints an octal number
 * @args: list of arguments
 * Return: number of characters printed
 */

int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int j = 0, k = 0;
	char *s;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	s = malloc(sizeof(char) * 100);
	if (s == NULL)
		return (0);
	while (n > 0)
	{
		s[j] = (n % 8) + '0';
		n = n / 8;
		j++;
	}

	for (k = j - 1; k >= 0; k--)
		write(1, &s[k], 1);

	free(s);
	return (j);
}
