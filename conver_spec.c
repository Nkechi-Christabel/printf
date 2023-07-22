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
 * print_binary - Converts unsigned integer to binary
 * @b: The number to print
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

/**
 * print_ui - Prints unsigned interger
 * @u: The number to print
 * @count: The number of chracters printed
 *
 * Return: 0 always (success)
 */
int print_ui(unsigned int u, int *count)
{
	if (u / 10 != 0)
		print_ui(u / 10, count);

	_putchar(u % 10 + '0');

	(*count)++;

	return (0);
}

/**
 * print_octal - Prints integer in octal
 * @o: The number to print
 * @count: The number of chracters printed
 *
 * Return: 0 always (success)
 */
int print_octal(unsigned int o, int *count)
{
	if (o / 8 != 0)
		print_octal(o / 8, count);

	_putchar(o % 8 + '0');

	(*count)++;

	return (0);
}

/**
 * print_hex - Prints Unsigned hexadecimal
 * @h: The number to print
 * @uppercase: Determinant if the hexadecimals should
 * uppercase or not
 * @count: The number of chracters printed
 */
void print_hex(unsigned int h, int uppercase, int *count)
{
	char *hexString;

	if (uppercase)
		hexString = "0123456789ABCDEF";
	else
		hexString = "0123456789abcdef";

	if (h / 16 != 0)
		print_hex(h / 16, uppercase, count);

	_putchar(hexString[h % 16]);

	(*count)++;
}
