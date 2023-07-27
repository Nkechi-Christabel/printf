#include "main.h"
#include <limits.h>


/**
 * print_numlong - Prints an integer
 * @n: The number to print
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void print_numlong(unsigned long n, int *count, char *buffer,
		int *buffer_index)
{
	if (n / 10 != 0)
		print_numlong(n / 10, count, buffer, buffer_index);

	_putchar(n % 10 + '0', buffer, buffer_index);
	(*count)++;
}

/**
 * print_long - Prints an integer
 * @n: The number to print
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void print_long(long n, int *count, char *buffer, int *buffer_index)
{
	long num;
	char digits[20];
	int i = 0;

	if (n == LONG_MIN || n == INT_MIN)
	{
		do {
			digits[i++] = '0' - (n % 10);
			n /= 10;
		} while (n != 0);

		_putchar('-', buffer, buffer_index);
		(*count)++;

		while (i > 0)
		{
			i--;
			_putchar(digits[i], buffer, buffer_index);
			(*count)++;
		}
		return;
	}

	if (n < 0)
	{
		_putchar('-', buffer, buffer_index);
		num = -n;
		(*count)++;
	}
	else
		num = n;

	if (num / 10 != 0)
		print_long(num / 10, count, buffer, buffer_index);

	_putchar(num % 10 + '0', buffer, buffer_index);
	(*count)++;
}

/**
 * print_numshort - Prints an integer
 * @n: The number to print
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void print_numshort(unsigned short n, int *count, char *buffer,
		int *buffer_index)
{
	if (n / 10 != 0)
		print_numshort(n / 10, count, buffer, buffer_index);

	_putchar(n % 10 + '0', buffer, buffer_index);
	(*count)++;
}
