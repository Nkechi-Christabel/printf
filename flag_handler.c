#include "main.h"

/**
 * check_flags - The function checks if format is a flag
 * @format: The format to check for a flag
 *
 * Return: 1, 2, 3, or 0 always (Success)
 */
int check_flags(const char *format)
{
	int flags = 0;

	while (*format == '+' || *format == ' ' || *format == '#')
	{
		if (*format == '+')
		{
			flags |= FLAG_PLUS;
		}

		else if (*format == ' ')
		{
			flags |= FLAG_SPACE;
		}

		else if (*format == '#')
		{
			flags |= FLAG_HASH;
		}

		format++;
	}

	return (flags);
}
