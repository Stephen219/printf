#include "main.h"
/**
 * handle_binary_integer_format - Handles binary representation of an integer.
 * @buffer: The buffer for storing characters.
 * @buff_ind: A pointer to the buffer index.
 * @number_of_chars_printed: A pointer to the number of characters printed.
 * @list_args: A va_list of arguments.
 */


void handle_binary_integer_format(
		char *buffer, int *buff_ind, int *number_of_chars_printed, va_list list_args)
{
	int i;
	unsigned int integer = va_arg(list_args, unsigned int);
	int binary[32];

	for (i = 31; i >= 0; i--)
	{
		binary[i] = (integer & 1) + '0';
		integer >>= 1;
	}
	for (i = 0; i < 32; i++)
	{
		add_char_to_buffer(buffer, buff_ind, binary[i], number_of_chars_printed);
	}
}

