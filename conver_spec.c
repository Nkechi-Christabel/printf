#include "main.h"

/**
 * print_number - Prints an integer
 * @num: The number to print
 * @count: The number of characters printed
 * Return: 0 always (success)
 */
int print_number(int num, int *count)
{
	unsigned int n;

	if (num < 0)
	{
		_putchar('-');
		(*count)++;
		n = -num;
	}
	else
		n = num;

	if (n / 10 != 0)
		print_number(n / 10, count);

	_putchar(n % 10 + '0');
	(*count)++;
	return (0);
}

/**
 * print_binary - Converts unsigned int to binary
 * @num: The number to print
 * @count: The number of chracters printed
 *
 * Return: 0 always (success)
 */

int print_binary(unsigned int b, int *count)
{
	if (b / 2 != 0)
		print_binary(b / 2, count);

	_putchar('0' + (b % 2));

	(*count)++;

	return (0);
}
