#include <limits.h>
#include <stdio.h>
#include "main.h"

int main() {

    int num = 0;
    int count;
   unsigned int ui = (unsigned int)INT_MAX + 1024;

   int *ptr = (void *)0x7ffe637541f0;
   _printf("Pointer address: %p\n", ptr);

    _printf("Integer with '+' flag:%+d\n", num);
    _printf("Integer with 'space' flag:% d\n", num);
    _printf("Integer with '#' flag:% #x\n", ui);
    _printf("Integer with '#' flag:% #o\n", ui);

    count = _printf("Integer with '+' flag:%+d\n", num);

    printf("count is %d", count);

    return 0;
}
