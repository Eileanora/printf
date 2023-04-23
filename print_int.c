#include "main.h"
/**
 * print_rec - print a number recursively
 * @n: number to print
 * Return: number of characters printed
*/
int print_rec(int n)
{
	if (n == 0)
		return (0);
	fflush(stdout);
	print_rec(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return (1);
}
/**
 * print_int - print an integer
 * @args: list of arguments
 * Return: number of characters printed
*/
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int i = 0, j = 0, k = 0;
	char *s;

	if (n < 0)
	{
		n = n * -1;
		i++;
	}
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
		s[j] = (n % 10) + '0';
		n = n / 10;
		j++;
	}
	if (i == 1)
	{
		s[j] = '-';
		j++;
	}
	for (k = j - 1; k >= 0; k--)
		write(1, &s[k], 1);
	free(s);
	return (j);
}
