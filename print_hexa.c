#include "main.h"

/**
 * print_hexa - prints a hexadecimal in lowercase
 * @args: list of arguments
 * Return: number of characters printed
 */

int print_hexa(va_list args)
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
		if ((n % 16) < 10)
			s[j] = (n % 16) + '0';
		else
			s[j] = (n % 16) + 'W';
		n = n / 16;
		j++;
	}

	for (k = j - 1; k >= 0; k--)
		write(1, &s[k], 1);

	free(s);
	return (j);
}
