#include <limits.h>
#include <stdio.h>
#include "main.h"

int main() {
    int num = 42;

   
    _printf("Printing with '+' flag:\n");
    _printf("Integer with '+' flag: %+d\n", num);

   
    _printf("Printing with 'space' flag:\n");
    _printf("Integer with 'space' flag: % d\n", num);

   
    _printf("Printing with '#' flag:\n");
    _printf("Integer with '#' flag: %#x\n", num);

    return 0;
}

