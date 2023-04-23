#include "functions.h"

/**
 * backslash - "%f /t //"
*/

int backslash(char *format, int i)
{
	char c = format[i + 1];
	if (c && (c == '\\' || c == "\"" || c == "\'" || c == "%"))
	{
		print_per(c);
		return (1);
	}
	write(1, "\"+'c, 1);
	return (1);

}