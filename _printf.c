#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	char buffer[BUFF_SIZE];
	int buff_ind = 0;
	int number_of_chars_printed = 0;
	va_list list_args;

	va_start(list_args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			add_char_to_buffer(buffer, &buff_ind, *format, &number_of_chars_printed);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == '%')
				add_char_to_buffer(buffer, &buff_ind, *format, &number_of_chars_printed);
			else if (*format == 'c')
				handle_char_format(buffer, &buff_ind, &number_of_chars_printed, list_args);
			else if (*format == 's')
				handle_string_format(
						buffer, &buff_ind, &number_of_chars_printed, list_args);
			else if (*format == 'd' || *format == 'i')
			{
				handle_integer_format(
						buffer, &buff_ind, &number_of_chars_printed, list_args);
			}
		}
		format++;
	}
	if (buff_ind > 0)
	{
		print_buffer(buffer, &buff_ind);
	}
	va_end(list_args);
	return (number_of_chars_printed);
}

