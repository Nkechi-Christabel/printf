#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

void _putchar(char c, char *buffer, int *buffer_index);
void _write_buffer(char *buffer, int *buffer_index);
int _printf(const char *format, ...);
void print_arg(const char *format, int *count, va_list args, char *buffer,
		int *buffer_index);
void print_number(int num, int *count, char *buffer, int *buffer_index);
void print_binary(unsigned int b, int *count, char *buffer, int *buffer_index);
void print_ui(unsigned int u, int *count, char *buffer, int *buffer_index);
void print_octal(unsigned int o, int *count, char *buffer, int *buffer_index);
void print_hex(unsigned int h, int uppercase, int *count, char *buffer,
		int *buffer_index);

#endif /*MAIN_H*/
