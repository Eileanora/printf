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
	fflush(stdout);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

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
		{"d", print_int}
	};
	int j = 0, bytes = 0;
	
	while (j < 4)
	{
		if (c && c == _printer[j].symbol[0])
		{
			bytes = _printer[j].print(args);
			break;
		}
		j++;
	}
	if (j == 4)
		if (c == '%')
			bytes = print_any_char(c);
		else
			bytes = print_any_char('%') + print_any_char(c);
	return (bytes);
}
/**
 * _printf - print a string with format specifiers
 * @format: string to print
 * Return: number of characters printed
*/
int _printf(char *format, ...)
{
	va_list args;
	int i, bytes = 0;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
			bytes += percent(format, i, args), i++;
		else if (format[i] == '\\')
			bytes += backslash(format, i), i++;
		else
			bytes += print_any_char(format[i]);
	}
	va_end(args);
	return (bytes);
}


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}