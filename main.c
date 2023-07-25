#include <limits.h>
#include <stdio.h>
#include "main.h"

int main() {
    int num = 42;
    int count;
   unsigned int ui = (unsigned int)INT_MAX + 1024;

   int *ptr = (void *)0x7ffe637541f0;;
   _printf("Pointer address: %p\n", ptr);


    _printf("Integer with '+' flag:% +d\n", num);
    _printf("Integer with 'space' flag:% d\n", num);
    _printf("Integer with '#' flag:% #x\n", ui);
    _printf("Integer with '#' flag:% #o\n", ui);
    

        printf("\n---------- Testing solo flags ----------\n");
	count = _printf("Testing plus flag: %+d\n", 42);
	printf("Characters printed: %d\n", count);
	count = _printf("Testing space flag: % d\n", 42);
	printf("Characters printed: %d\n", count);

	count = _printf("Testing hash flag: %#x\n", ui);
	printf("Characters printed: %d\n", count);

	printf("\n---------- Testing flag combinations ----------\n");
	count = _printf("Combination: %+ d\n", 42);
	printf("Characters printed: %d\n", count);

	_printf("Combination: %#o\n", ui);

	_printf("Combination: %X\n", ui);

	_printf("Combination: % #X\n", ui);

	_printf("Combination: %# d\n", 42);

    return 0;
}

