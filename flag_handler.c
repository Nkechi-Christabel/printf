#include "main.h"

/**
 * check_flags - The function checks if format is a flag
 * @format: The format to check for a flag
 */
void check_flags(const char *format)
{
	flag_plus = 0;
	flag_space = 0;
	flag_hash = 0;

	while (*format == '+' || *format == ' ' || *format == '#')
	{
		if (*format == '+')
			flag_plus = 1;

		else if (*format == ' ')
			flag_space = 1;

		else if (*format == '#')
			flag_hash = 1;

		format++;
	}
}
