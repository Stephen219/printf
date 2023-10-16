#include "main.h"

/**
 * print_buffer - Print the buffer contents and reset the buffer index.
 * @buffer: The buffer to print from.
 * @buff_ind: Pointer to the buffer index.
 */

void print_buffer(char *buffer, int *buff_ind)
{
	write(1, buffer, *buff_ind);
	*buff_ind = 0;
}
/**
 * add_char_to_buffer - Adds a character to the buffer and flush it.
 * @buffer: The buffer for storing characters.
 * @buff_ind: A pointer to the buffer index.
 * @c: The character to add to the buffer.
 * @chars_printed: number of chars printed.
 */

void add_char_to_buffer(
		char *buffer, int *buff_ind, char c, int *chars_printed)
{
	buffer[(*buff_ind)++] = c;
	if (*buff_ind == BUFF_SIZE)
	{
		print_buffer(buffer, buff_ind);
	}
	*chars_printed++;
}

/**
 * handle_char_format - Handles the 'c' format specifier.
 * @buffer: The buffer for storing characters.
 * @buff_ind: A pointer to the buffer index.
 * @chars_printed: A pointer to the number of characters printed.
 * @list_args: A va_list of arguments.
 */

void handle_char_format(char *buffer,
		int *buff_ind, int *chars_printed, va_list list_args)
{
	char c = va_arg(list_args, int);

	add_char_to_buffer(buffer, buff_ind, c, chars_printed);
}


/**
 * handle_string_format - Handles the 's' format specifier.
 * @buffer: The buffer for storing characters.
 * @buff_ind: A pointer to the buffer index.
 * @chars_printed: A pointer to the number of characters printed.
 * @list_args: A va_list of arguments.
 */

void handle_string_format(
		char *buffer, int *buff_ind, int *chars_printed, va_list list_args)
{
	int i = 0;
	char *s = va_arg(list_args, char *);
	int length = strlen(s);

	for (i = 0; i < length; i++)
	{
		add_char_to_buffer(buffer, buff_ind, s[i], chars_printed);
	}
}


/**
 * handle_integer_format - Handles the 'd' and 'i' format specifiers.
 * @buffer: The buffer for storing characters.
 * @buff_ind: A pointer to the buffer index.
 * @chars_printed: A pointer to the number of characters printed.
 * @list_args: A va_list of arguments.
 */
void handle_integer_format(
		char *buffer, int *buff_ind, int *chars_printed, va_list list_args)
{
	int length;
	int i = 0;
	int integer = va_arg(list_args, int);
	char int_str[12];

	snprintf(int_str, sizeof(int_str), "%d", integer);
	length = strlen(int_str);
	for (i = 0; i < length; i++)
	{
		add_char_to_buffer(buffer, buff_ind, int_str[i], chars_printed);
	}
}
