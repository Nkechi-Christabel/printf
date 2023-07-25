#include <limits.h>
#include <stdio.h>
#include "main.h"

int main() {
    int num = -42;

   
    _printf("Integer with '+' flag:%+d\n", num);
    _printf("Integer with 'space' flag:% d\n", num);
    _printf("Integer with '#' flag:% #x\n", num);
    _printf("Integer with '#' flag:% #o\n", num);


    return 0;
}

