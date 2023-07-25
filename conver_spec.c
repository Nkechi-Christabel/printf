#include "main.h"
#include <math.h>
#include <stdbool.h>

/**
 * print_number - Prints an integer
 * @num: The number to print
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 * @flag: contains the flags
 */
void print_number(int num, int *count, char *buffer, int *buffer_index,
		int flag)
{
	unsigned int n;
	char num_str[12];
	int num_len = 0, i;
	bool flag_plus = (flag & FLAG_PLUS) != 0;
	bool flag_space = (flag & FLAG_SPACE) != 0;

	if (num >= 0)
	{
		n = num;
	}
	else
	{
		buffer[(*buffer_index)++] = '-';
		(*count)++;
		n = -num;
	}
	if (flag_plus)
	{
		buffer[(*buffer_index)++] = '+';
		(*count)++;
	}
	else
	{
		if (flag_space)
		{
			buffer[(*buffer_index)++] = ' ';
			(*count)++;
		}
	}

	do {
		num_str[num_len++] = n % 10 + '0';
		n /= 10;
	} while (n != 0);

	for (i = num_len - 1; i >= 0; i--)
	{
		buffer[(*buffer_index)++] = num_str[i];
		(*count)++;
	}
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
	char num_str[12];
	int num_len = 0, i;
	bool flag_plus = (flag & FLAG_PLUS) != 0;
	bool flag_space = (flag & FLAG_SPACE) != 0;

	if (flag_plus)
	{
		buffer[(*buffer_index)++] = '+';
		(*count)++;
	}
	else if (flag_space)
	{
		buffer[(*buffer_index)++] = ' ';
		(*count)++;
	}
	do
	{
		num_str[num_len++] = u % 10 + '0';
		u /= 10;
	} while (u != 0);

	for (i = num_len - 1; i >= 0; i--)
	{
		buffer[(*buffer_index)++] = num_str[i];
		(*count)++;
	}
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
	char num_str[12];
	int num_len = 0, i;
	bool flag_hash = (flag & FLAG_HASH) != 0;
	bool flag_space = (flag & FLAG_SPACE) != 0;

	if (flag_hash)
	{
		buffer[(*buffer_index)++] = '0';
		(*count)++;
	}
	else if (flag_space)
	{
		buffer[(*buffer_index)++] = ' ';
		buffer[(*buffer_index)++] = '0';
		(*count) += 2;
	}

	do
	{
		num_str[num_len++] = o % 8 + '0';
		o /= 8;
	} while (o != 0);

	for (i = num_len - 1; i >= 0; i--)
	{
		buffer[(*buffer_index)++] = num_str[i];
		(*count)++;
	}
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
	char num_str[12];
	int num_len = 0, i;
	bool flag_hash = (flag & FLAG_HASH) != 0;
	bool flag_space = (flag & FLAG_SPACE) != 0;
	char *hexString = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (flag_hash)
	{
		buffer[(*buffer_index)++] = '0';
		buffer[(*buffer_index)++] = uppercase ? 'X' : 'x';
		(*count) += 2;
	}
	else if (flag_space)
	{
		buffer[(*buffer_index)++] = ' ';
		buffer[(*buffer_index)++] = '0';
		buffer[(*buffer_index)++] = uppercase ? 'X' : 'x';
		(*count) += 3;
	}

	do
	{
		num_str[num_len++] = hexString[h % 16];
		h /= 16;
	} while (h != 0);

	for (i = num_len - 1; i >= 0; i--)
	{
		buffer[(*buffer_index)++] = num_str[i];
		(*count)++;
	}
}
