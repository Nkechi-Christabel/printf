#include "main.h"
#include <math.h>
#include <limits.h>


/**
 * print_number_flag - Helper function to print the sign character
 * ('+', '-' or ' ')
 * @n: The number to print
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 * @flag: Contains the flags
 */
void print_number_flag(int n, int *count, char *buffer, int *buffer_index,
		int flag)
{
	if (n >= 0)
	{
		if (flag == 1)
		{
			_putchar('+', buffer, buffer_index);
			(*count)++;
		}
		else if (flag == 2)
		{
			_putchar(' ', buffer, buffer_index);
			(*count)++;
		}
		else if (flag == 5)
		{
			_putchar('+', buffer, buffer_index);
			(*count)++;
		}
	}

}

/**
 * print_number - Prints an integer
 * @num: The number to print
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 * @flag: Contains the flags
 */
void print_number(int num, int *count, char *buffer, int *buffer_index,
		int flag)
{
	int n;

	if (num == INT_MIN)
	{
		print_long(num, count, buffer, buffer_index);
		return;
	}



	if (num < 0)
	{
		_putchar('-', buffer, buffer_index);
		n = -num;
		(*count)++;
	}
	else
		n = num;

	if (flag == 7)
	{
		n = (unsigned short)n;
		flag = 0;
	}

	if (n / 10 != 0)
		print_number(n / 10, count, buffer, buffer_index, flag);

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
	if (o > 0)
	{
		if (flag == 3 || flag == 4)
		{
			_putchar('0', buffer, buffer_index);
			(*count)++;
			flag = 0;
		}
	}

	if (flag == 6)
	{
		o = (unsigned long)o;
		flag = 0;
	}
	else if (flag == 7)
	{
		o = (unsigned short)o;
		flag = 0;
	}
	if (o / 8 != 0)
		print_octal(o / 8, count, buffer, buffer_index, flag);

	_putchar(o % 8 + '0', buffer, buffer_index);

	(*count)++;
}

