#include <stdarg.h>
#include "main.h"
#include <stddef.h>

/**
 * check_str - Prints a string
 * @str: The string to print
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void check_str(char *str, int *count, char *buffer, int *buffer_index)
{
	if (!(*str))
		str = "(null)";

	while (*str)
	{
		_putchar(*str, count, buffer, buffer_index);
		str++;

		(*count)++;
	}

}

/**
 * print_arg - A helper function to print args
 * @format: A list of types of arguments passed to the function
 * @args: The arguments to be printed
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void print_arg(const char *format, int *count, va_list args, char *buffer,
		int *buffer_index)
{
	char *str;

	switch (*format)
	{
		case 'c':
			_putchar(va_arg(args, int), count, buffer, buffer_index);
			(*count)++;
			break;
		case 's':
			str = va_arg(args, char *);
			check_str(str, count, buffer, buffer_index);
			break;
		case '%':
			_putchar('%', count, buffer, buffer_index);
			(*count)++;
			break;
		case 'd': case 'i':
			print_number(va_arg(args, int), count, buffer, buffer_index);
			break;
		case 'b':
			print_binary(va_arg(args, unsigned int), count, buffer, buffer_index);
			break;
		case 'u':
			print_ui(va_arg(args, unsigned int), count, buffer, buffer_index);
			break;
		case 'o':
			print_octal(va_arg(args, unsigned int), count, buffer, buffer_index);
			break;
		case 'x':
			print_hex(va_arg(args, unsigned int), 0, count, buffer, buffer_index);
			break;
		case 'X':
			print_hex(va_arg(args, unsigned int), 1, count, buffer, buffer_index);
			break;
		default:
			_putchar('%', count, buffer, buffer_index);
			_putchar(*format, count, buffer, buffer_index);
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
	int buffer_index = 0;
	char buffer[BUFFER_SIZE];
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format, &count, buffer, &buffer_index);
		}
		else
		{
			format++;
			print_arg(format, &count, args, buffer, &buffer_index);
		}

		format++;
	}

	if (buffer_index > 0)
		_write_buffer(buffer, &count, &buffer_index);

	va_end(args);

	return (count);
}
