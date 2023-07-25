#include <limits.h>
#include <stdio.h>
#include "main.h"

int main() {
<<<<<<< HEAD
    int num = -42;
=======
    int num = 42;
   unsigned int ui = (unsigned int)INT_MAX + 1024;
>>>>>>> a69e4cc29acdc4fe8c8279f5b946309c40036aa5

   int *ptr = (void *)0x7ffe637541f0;;
   _printf("Pointer address: %p\n", ptr);

    _printf("Integer with '+' flag:% +d\n", num);
    _printf("Integer with 'space' flag:% d\n", num);
    _printf("Integer with '#' flag:% #x\n", ui);
    _printf("Integer with '#' flag:% #o\n", ui);


    return 0;
}

