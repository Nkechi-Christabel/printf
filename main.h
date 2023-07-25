#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/*Buffer*/
#define BUFFER_SIZE 1024

/*Flags*/
#define FLAG_PLUS (1 << 0)
#define FLAG_SPACE (1 << 1)
#define FLAG_HASH       (1 << 2)

/*Print to Stdoutput*/
void _putchar(char c, char *buffer, int *buffer_index);
void _write_buffer(char *buffer, int *buffer_index);

/*Printf function*/
int _printf(const char *format, ...);

/*Switch cases*/
void print_arg(const char *format, int *count, va_list args, char *buffer,
		int *buffer_index, int flag);
void print_arg2(const char *format, int *count, va_list args, char *buffer,
		int *buffer_index, int flag);

/*Conversion specifier*/
void check_str(char *str, int *count, char *buffer, int *buffer_index);
int check_flags(const char *format);
void print_number(int num, int *count, char *buffer, int *buffer_index, int flag);
void print_binary(unsigned int b, int *count, char *buffer, int *buffer_index);
void print_ui(unsigned int u, int *count, char *buffer, int *buffer_index, int flag);
void print_octal(unsigned int o, int *count, char *buffer, int *buffer_index, int flag);
void print_hex(unsigned int h, int uppercase, int *count, char *buffer,
		int *buffer_index, int flag);
void print_str_nonChar(char *s, int *count, char *buffer, int *buffer_index);
void print_ptr(void *p, int *count, char *buffer, int *buffer_index);

#endif /*MAIN_H*/
