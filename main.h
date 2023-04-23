#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
/**
 * struct printer - Struct print
 *
 * @symbol: The operator
 * @print: The function associated
 */

typedef struct printer
{
	char *symbol;
	int (*print)(va_list);
} printer_t;

int print_char(va_list);
int print_string(va_list);
int print_int(va_list);
int _printf(char *format, ...);
int print_any_char(char c);
int percent(char *format, int i, va_list args);
int backslash(char *format, int i);

#endif