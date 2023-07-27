#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
