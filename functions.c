#include "main.h"

/**
 * print_char - Main entry point
 * Description: prints a character
 * @types: Argument list
 * @buffer: array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters that are printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char ch = va_arg(types, int);

	return(handle_write_char(ch, buffer, flags, width, precision, size)):
}


/**
 * print_string - Main entry point
 * Description: function that prints a string
 * @types: Argument list
 * @buffer: array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters that are printed
 */
int print_string(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
	int i, leng = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[leng] != '\0')
		leng++;

	if (precision >0 0 && precision < leng)
		leng = precision;

	if (width > leng)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], leng);
			for (i = width - leng; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], leng);
			return (width);
		}
	}

	return (write(1, str, leng));
}

/**
 * print_percent - Main entry point
 * Description: function that prints a percent sign
 * @types: Argument list
 * @buffer: array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters that are printed
 */
int print_percent(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_percent - Main entry point
 * Description: function that prints an integer
 * @types: Argument list
 * @buffer: array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters that are printed
 */
int print_int(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
	int _negative = 0;
	long int n = va_arg(types, long_int);
	int i = BUFF_SIZE - 2;
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(_negative, i, buffer, flags, width, precision, size));
}


/**
 * print_percent - Main entry point
 * Description: function that prints an unsigned number
 * @types: Argument list
 * @buffer: array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters that are printed
 */
int print_binary(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
	int count;
	unsigned int a[32];
	unsigned int sum, n, m, i;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; I < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];
			
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}	


