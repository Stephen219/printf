#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define BUFF_SIZE 1024


int _printf(const char *format, ...);
void print_buffer(char *buffer, int *buff_ind);
void add_char_to_buffer(
		char *buffer, int *buff_ind, char c, int *number_of_chars_printed);
void handle_char_format(
		char *buffer,
		int *buff_ind, int *number_of_chars_printed, va_list list_args);
void handle_string_format(
		char *buffer,
		int *buff_ind, int *number_of_chars_printed, va_list list_args);
void handle_integer_format(
		char *buffer,
		int *buff_ind, int *number_of_chars_printed, va_list list_args);

void handle_binary_integer_format(
		char *buffer, int *buff_ind,
		int *number_of_chars_printed, va_list list_args);
#endif
