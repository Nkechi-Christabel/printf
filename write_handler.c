#include "main.h"
#include <stdint.h>
#include <stddef.h>

/**
 * _putchar - A custom function to store characters in the buffer.
 *
 * Description: It stores single characters in the buffer.
 * @c: The character to be stored
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void _putchar(char c, char *buffer, int *buffer_index)
{
	buffer[*buffer_index] = c;
	(*buffer_index)++;

	if (*buffer_index >= BUFFER_SIZE - 1)
	{
		_write_buffer(buffer, buffer_index);
		*buffer_index = 0;
	}

}

/**
 * _write_buffer - Helper function to write the buffer to STDOUT_FILENO
 * @buffer: The buffer containing characters to be printed
 * @buffer_index: The current index in the buffer
 */
void _write_buffer(char *buffer, int *buffer_index)
{
	write(1, buffer, *buffer_index);
}
