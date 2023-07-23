#include "main.h"

/**
 * check_flags - The function checks if format is a flag
 * @format: The format to check for a flag
 */
void check_flags(const char *format)
{
	while (*format == '+' || *format == ' ' || *format == '#')
	{
		if (*format == '+')
			flag.plus = 1;

		else if (*format == ' ')
			flag.space = 1;

		else if (*format == '#')
			flag.hash = 1;

		format++;
	}
}
