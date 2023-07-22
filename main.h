#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

void _putchar(char c);
int _printf(const char *format, ...);
void  print_arg(const char *format, int *count, va_list args);
int print_number(int num, int *count);
int print_binary(unsigned int b, int *count);
int print_ui(unsigned int u, int *count);
int print_octal(unsigned int o, int *count);
void print_hex(unsigned int h, int uppercase, int *count);

#endif /*MAIN_H*/
