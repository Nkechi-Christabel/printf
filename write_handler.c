#include <unistd.h>
#include "main.h"

/**
 * _putchar - A custom function to store characters in the buffer.
 *
 * Description: It stores single characters in the buffer.
 * @c: The character to be stored
 * @count: The number of characters stored
 * @buffer: The buffer to store characters
 * @buffer_index: The current index in the buffer
 */
void _putchar(char c, int *count, char *buffer, int *buffer_index)
{
    if (*buffer_index == BUFFER_SIZE)
        _write_buffer(buffer, count, buffer_index);

    buffer[(*buffer_index)++] = c;
    (*count)++;
}

/**
 * _write_buffer - Helper function to write the buffer to STDOUT_FILENO
 * @buffer: The buffer containing characters to be printed
 * @count: The number of characters printed
 * @buffer_index: The current index in the buffer
 */
void _write_buffer(char *buffer, int *count, int *buffer_index)
{
    write(STDOUT_FILENO, buffer, *buffer_index);
    *count += *buffer_index;
    *buffer_index = 0; 
}
