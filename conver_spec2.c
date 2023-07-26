#include "main.h"
#include <stdlib.h>
#include <string.h>


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

	if (h > 0)
	{
		if (flag == 3 || flag == 4)
		{
			buffer[(*buffer_index)++] = '0';
			buffer[(*buffer_index)++] = 'x';
			(*count) += 2;
			flag = 0;
		}
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


/**
 * print_str_nonChar - The function handles the conversion specifier 'S'.
 * Description: Non printable characters (0 < ASCII value < 32 or >= 127)
 * are printed this way: \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters).
 * @s: The string to print
 * @count: The number of chracters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void print_str_nonChar(char *s, int *count, char *buffer, int *buffer_index)
{
	while (*s)
	{
		if (*s < 32 || *s >= 127)
		{
			buffer[(*buffer_index)++] = '\\';
			buffer[(*buffer_index)++] = 'x';
			buffer[(*buffer_index)++] = "0123456789ABCDEF"[(*s >> 4) & 0xF];
			buffer[(*buffer_index)++] = "0123456789ABCDEF"[*s & 0xF];

			(*count) += 4;
		}

		else
		{
			_putchar(*s, buffer, buffer_index);

			(*count)++;
		}

		s++;
	}
}

/**
 * print_ptr - The function handles the conversion of specifies 'p'.
 * @p: The address to print
 * @count: The number of characters printed
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void print_ptr(void *p, int *count, char *buffer, int *buffer_index)
{
	unsigned long ptr_val = (unsigned long)p;
	unsigned int num_chars = 0, digit;
	const char hexString[] = "0123456789abcdef";
	char *str;

	if (!p)
	{
		str = "(nil)";
		while (*str)
		{
			_putchar(*str, buffer, buffer_index);
			str++;
			(*count)++;
		}

		return;
	}

	_putchar('0', buffer, buffer_index);
	_putchar('x', buffer, buffer_index);

	(*count) += 2;

	while (ptr_val)
	{
		ptr_val /= 16;
		num_chars++;
	}

	ptr_val = (unsigned long)p;

	while (num_chars > 0)
	{
		digit = ptr_val >> (4 * (num_chars - 1)) & 0xF;

		_putchar(hexString[digit], buffer, buffer_index);
		(*count)++;
		num_chars--;
	}
}

