#include "main.h"

/**** PRINT UNSIGNED NUMBER *****/

/**
 * print_unsigned - print an unsigned number
 * @size: specifier of size
 * @width: width
 * @precision: specification of precision
 * @buffer: buffer array to handle print
 * @flags: calculation of active flags
 * @types: arguments listed
 *
 * Return: number of chars printed.
 */

int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE -2;
	unsigned long int num = va_arg(types, unsigned long int);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--]= '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) +'0';
		num /= 10;
	}

	a++;
	return (write_unsgnd(0,a,buffer,flags,width,precision,size));
}

/***** PRINT HEXA NUM IN LOWER OR UPPER *****/
/**
 * print_hexa - print a hexadecimal number in lower or upper
 * @size: specification of size
 * @size: size specifier
 * @width: width getter
 * @flag_ch: calculation of active flags
 * @flags: calculation of active flags
 * @precision: specification of precision
 * @types: arguments listed
 * @buffer: buffer array to handle p[rint
 * @map_to: array of values to map the number
 *
 * Return: number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int init_num = init_num;
	unsigned long int num = va_arg(types, unsigned long int);

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)

	{
		buffer[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}
	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision,size));
}

/***** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL *****/
/**
 * print_hexa_upper - print an unsigned number in upper hexadecimal notation
 * @flags: active flags calculation
 * @types: arguments listed
 * @buffer: buffer array to handle print
 * @size: specifer of size
 * @width: width getter
 * @precision: specification of precision
 *
 * Return: the number of chars printed
 */

int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X',  width, precision, size));
}

/***** PRINT UNSIGNED NUMBER IN OCTAL *****/
/**
 * print_octal -print an unsigned number in octal notation
 * @size: size specification
 * @precision: spefication of precision
 * @width: width getter
 * @flags: calculation of active flags
 * @buffer: buffer array to handle print
 * @types: arguments listed
 *
 * Return: number of chars printed
 */

int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE -2;
	unsigned long int init_num = init_num;
	unsigned long int num = va_arg(types, unsigned long int);

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';
	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/***** PRINT UNSIGNED NUMBER IN HEXADECIMAL *****/

/**
 * print_hexadecimal - print an unsigned number in hexacedimal notation
 * @types: arguments listed
 * @buffer: buffer array handle print
 * @flags: calculation of active flags
 * @width: width getter
 * @precision: specification of precision
 * @size: spefication of size
 *
 * Return: the number of chars printed
 */

int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}
