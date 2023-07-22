#include <stdio.h>
#include <stdarg.h>
#include "main.h"



int num_digits(int num) {
    int count = 0;
    if (num == 0) return 1;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

/**
 * print_arg - A helper function to print args
 * @format: A list of types of arguments passed to the function
 * @count: The number of characters printed
 * @args: The arguments to be printed
 */
void  print_arg(const char *format, int *count, va_list args)
{
	char *str, num_str[12];
	int num, num_chars, i;

	switch (*format)
	{
		case 'c':
			_putchar(va_arg(args, int));
			(*count)++;
			break;

		case 's':
			str = va_arg(args, char *);
			while (*str)
			{
				_putchar(*str);
				str++;
				(*count)++;
			}
			break;

		case 'd':
		case 'i':
			num = va_arg(args, int);
			num_chars = num_digits(num);

			i = num_chars - 1;
			while (num != 0) {
				num_str[i] = '0' + (num % 10);
				num /= 10;
				i--;
			}
			num_str[num_chars] = '\0';

			 i = 0;
                    while (num_str[i] != '\0') {
                        _putchar(num_str[i]);
                        i++;
                        count++;
                    }
			break;

		case '%':
			_putchar('%');
			(*count)++;
			break;

		default:
			_putchar('%');
			putchar(*format);
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

	va_start(args, format);

	while (format && *format)
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
