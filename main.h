#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

extern int flag_plus;
extern int flag_space;
extern int flag_hash;

/*Print to Stdoutput*/
void _putchar(char c, char *buffer, int *buffer_index);
void _write_buffer(char *buffer, int *buffer_index);

/*Printf function*/
int _printf(const char *format, ...);

/*Switch cases*/
void print_arg(const char *format, int *count, va_list args, char *buffer,
		int *buffer_index);
void print_arg2(const char *format, int *count, va_list args, char *buffer,
		int *buffer_index);

/*Conversion specifier*/
void check_str(char *str, int *count, char *buffer, int *buffer_index);
void check_flags(const char *format);
void print_number(int num, int *count, char *buffer, int *buffer_index);
void print_binary(unsigned int b, int *count, char *buffer, int *buffer_index);
void print_ui(unsigned int u, int *count, char *buffer, int *buffer_index);
void print_octal(unsigned int o, int *count, char *buffer, int *buffer_index);
void print_hex(unsigned int h, int uppercase, int *count, char *buffer,
		int *buffer_index);
void print_str_nonChar(char *s, int *count, char *buffer, int *buffer_index);
void print_ptr(void *p, int *count, char *buffer, int *buffer_index);

#endif /*MAIN_H*/
