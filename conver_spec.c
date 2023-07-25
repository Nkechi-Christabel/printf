#include "main.h"
#include <math.h>

/**
 * print_number - Prints an integer
 * @num: The number to print
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 * @flag: contains the flags
 */
void print_number(int num, int *count, char *buffer, int *buffer_index)
{
	unsigned int n;

	if (num < 0)
	{
		_putchar('-', buffer, buffer_index);
		(*count)++;
		n = -num;
	}
	else
		n = num;

	if (n / 10 != 0)
		print_number(n / 10, count, buffer, buffer_index);

	_putchar(n % 10 + '0', buffer, buffer_index);
	(*count)++;
}

/**
 * print_binary - Converts unsigned integer to binary
 * @b: The number to print
 * @count: The number of chracters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void print_binary(unsigned int b, int *count, char *buffer, int *buffer_index)
{
	if (b / 2 != 0)
		print_binary(b / 2, count, buffer, buffer_index);

	_putchar('0' + (b % 2), buffer, buffer_index);

	(*count)++;
}

/**
 * print_ui - Prints unsigned interger
 * @u: The number to print
 * @count: The number of chracters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 * @flag: contains the flags
 */
void print_ui(unsigned int u, int *count, char *buffer, int *buffer_index,
		int flag)
{
	if (flag == 1)
	{
		buffer[(*buffer_index)++] = '+';
		(*count)++;
		flag = 0;
	}
	else if (flag == 2)
	{
		buffer[(*buffer_index)++] = ' ';
		(*count)++;
		flag = 0;
	}

	if (u / 10 != 0)
		print_ui(u / 10, count, buffer, buffer_index, flag);

	_putchar(u % 10 + '0', buffer, buffer_index);

	(*count)++;
}

/**
 * print_octal - Prints integer in octal
 * @o: The number to print
 * @count: The number of chracters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 * @flag: contains the flags
 */
void print_octal(unsigned int o, int *count, char *buffer, int *buffer_index,
		int flag)
{

	if (flag == 3)
	{
		buffer[(*buffer_index)++] = '0';
		(*count)++;
		flag = 0;
	}
	if (flag == 4)
	{
		buffer[(*buffer_index)++] = ' ';
		buffer[(*buffer_index)++] = '0';
		(*count) += 2;
		flag = 0;
	}

	if (o / 8 != 0)
		print_octal(o / 8, count, buffer, buffer_index, flag);

	_putchar(o % 8 + '0', buffer, buffer_index);

	(*count)++;
}

/**
 * print_hex - Prints Unsigned hexadecimal
 * @h: The number to print
 * @uppercase: Determinant if the hexadecimals should
 * uppercase or not
 * @count: The number of chracters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 * @flag: contains the flags
 */
void print_hex(unsigned int h, int uppercase, int *count, char *buffer,
		int *buffer_index, int flag)
{
	char *hexString;

	if (flag == 3)
	{
		buffer[(*buffer_index)++] = '0';
		buffer[(*buffer_index)++] = 'x';
		(*count) += 2;
		flag = 0;
	}
	else if (flag == 4)
	{

		buffer[(*buffer_index)++] = ' ';
		buffer[(*buffer_index)++] = '0';
		buffer[(*buffer_index)++] = 'x';
		(*count) += 3;
		flag = 0;
	}


	if (uppercase)
		hexString = "0123456789ABCDEF";
	else
		hexString = "0123456789abcdef";

	if (h / 16 != 0)
		print_hex(h / 16, uppercase, count, buffer, buffer_index, flag);

	_putchar(hexString[h % 16], buffer, buffer_index);

	(*count)++;
}
