#include "functions.h"
/**
 * print_rec - print a number recursively
 * @n: number to print
 * Return: number of characters printed
*/
int print_rec(int n)
{
	if (n == 0)
		return (0);
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
	/*nums can be positive and negative*/
	int n = va_arg(args, int);
	int i = 0;
	fflush(stdout);

	/* handle negative values */
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	/* handle 0 */
	if (n == 0)
	{
		write(1, "0", 1);
		i++;
	}
	/* handle positive values */
	if (n > 0)
	{
		i += print_rec(n);
	}
	return (i);
}
