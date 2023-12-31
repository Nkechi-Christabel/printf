#include "main.h"

/**
 * check_flags - The function checks if format is a flag
 * @format: The format to check for a flag
 *
 * Return: 1, 2, 3, or 0 always (Success)
 */
int check_flags(const char *format)
{

	while (*format == '+' || *format == ' ' || *format == '#' ||
			*format == 'l' || *format == 'h')
	{
		if (*format == '+')
		{
			if (*(format + 1) == ' ')
				return (5);
			else if (*(format + 1) == '#')
				return (4);
			else
				return (1);
		}
		else if (*format == ' ')
		{
			if (*(format + 1) == '#')
				return (4);
			else if (*(format + 1) == '+')
				return (5);
			else
				return (2);
		}
		else if (*format == '#')
		{
			if (*(format + 1) == ' ')
				return (4);
			else if (*(format + 1) == '+')
				return (4);
			else
				return (3);
		}
		else if (*format == 'l')
			return (6);
		else if (*format == 'h')
			return (7);

	}
	return (0);
}
