#include "main.h"
/**
 * _printf - this is the custom printf functioon to be called in the main
 * @format: the first arg of the variadic function prinf
 * @...: the other args
 * Return: the number of bytes printed as int for a succces execution
 */


int _printf(const char *format, ...)
{
	int chars_printed = 0;
	va_list list_args;

	if (format == NULL)
	{
		return (-1);
	}
	else
	{
		va_start(list_args, format);

		while (*format)
		{
			if (*format != '%')
				write(1, format, 1);
				chars_printed++;
			else
				format++;
				if (*format == '\0')
					break;
				else if (*format == 'c')
					char c = va_arg(list_args, int);

					write(1, &c, 1);
					chars_printed++;
				else if (*format == '%')
					write(1, format, 1);
					chars_printed++;
				else if (*format == 's')
					char *s = va_arg(list_args, char *);

					write(1, s, strlen(s));
					chars_printed += strlen(s);
			format++;
		}
		va_end(list_args);
	}
	return (chars_printed);
}
