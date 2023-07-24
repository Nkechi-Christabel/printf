#include "main.h"
#include <stdint.h>
#include <stdlib.h>

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
	int i;
	uintptr_t ptr_val = (uintptr_t)p, temp_val = ptr_val;
	int num_chars = 0;
	unsigned int digit;

	if (ptr_val == 0)
		num_chars = 1;

	else
	{
		while (temp_val)
		{
			temp_val /= 16;
			num_chars++;
		}
	}
	if (*buffer_index + num_chars + 2 >= BUFFER_SIZE)
	{
		_write_buffer(buffer, buffer_index);
		*buffer_index = 0;
	}

	buffer[(*buffer_index)++] = '0';
	buffer[(*buffer_index)++] = 'x';

	for (i = num_chars - 1; i >= 0; i--)
	{
		digit = ptr_val % 16;
		if (digit < 10)
			buffer[(*buffer_index) + i] = '0' + digit;
		else
			buffer[(*buffer_index) + i] = 'a' + digit - 10;

		ptr_val /= 16;
	}
	buffer[(*buffer_index) + num_chars] = '\0';
	(*buffer_index) += num_chars + 1;
	(*count) += num_chars + 2;
}
