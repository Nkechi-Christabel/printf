#include <unistd.h>

/**
 * _putchar - A custom function to print out chracters.
 *
 * Description: It writes single chracters to standard output STDOUT_FILENO.
 * @c: The charcter to be printed
 *
 */
void _putchar(char c)
{
	(write(STDOUT_FILENO, &c, 1));
}

