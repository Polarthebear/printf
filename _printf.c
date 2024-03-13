#include "main.h"

void print_buff(char buffer[], int *buff_ind);


/**
 * _printf - Main entry point
 * Description: A printf function
 * @format: format
 * Return: The printed chars
 */
int _printf(const char *format, ...)
{
	int printed_char = 0, printed = 0, i;
	int buff_ind = 0, precision, width, flags;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buff(buffer, &buff_ind);
			printed_char++;
		}
		else
		{
			print_buff(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_char += printed;
		}
	}

	print_buff(buffer, &buff_ind);

	va_end(list);

	return (printed_char);
}



/*
 * print_buff - Main entry point
 * Description: Print the contents of buffer if it exists
 * @buffer: array of characters
 * @buff_ind: Index to add next char, representing length.
 */
void Print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}

	*buff_ind = 0;
}
