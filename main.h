#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

void _putchar(char c);
int _printf(const char *format, ...);
void  print_arg(const char *format, int *count, va_list args);
int print_number(int num, int *count);
int print_binary(unsigned int b, int *count);

#endif /*MAIN_H*/
