#include <stdarg.h>
#include "main.h"
#include <stddef.h>

/**
 * check_str - Prints a string
 * @str: The string to print
 * @count: The number of characters printed
 */
void check_str(char *str, int *count)
{
	if (!(*str))
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		str++;
		(*count)++;
	}

}

/**
 * print_arg - A helper function to print args
 * @format: A list of types of arguments passed to the function
 * @args: The arguments to be printed
 * @count: The number of characters printed
 */
void print_arg(const char *format, int *count, va_list args)
{
	char *str;

	switch (*format)
	{
		case 'c':
			_putchar(va_arg(args, int));
			(*count)++;
			break;
		case 's':
			str = va_arg(args, char *);
			check_str(str, count);
			break;
		case '%':
			_putchar('%');
			(*count)++;
			break;
		case ('d' || 'i'):
			print_number(va_arg(args, int), count);
			break;
		case 'b':
			print_binary(va_arg(args, unsigned int), count);
			break;
		case 'u':
			print_ui(va_arg(args, unsigned int), count);
			break;
		case 'o':
			print_octal(va_arg(args, unsigned int), count);
			break;
		case 'x':
			print_hex(va_arg(args, unsigned int), 0, count);
			break;
		case 'X':
			print_hex(va_arg(args, unsigned int), 1, count);
			break;
		default:
			_putchar('%');
			_putchar(*format);
			(*count) += 2;
			break;
	}
}

/**
 * _printf - The program produces output according to a format
 * @format: A character string, the format to follow.
 *
 * Return: The number of charcaters printed or 0 always (Success)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			print_arg(format, &count, args);
		}

		format++;
	}

	va_end(args);

	return (count);
}
