#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct printer - Struct print
 *
 * @symbol: The operator
 * @print: The function associated
 */

typedef struct printer
{
	char *symbol;
	void (*print)(va_list);
} printer_t;

int print_char(va_list);
int print_string(va_list);
int print_int(va_list);

#endif
