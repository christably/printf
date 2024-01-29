#include "main.h"
/**
 * convert - func converter
 * @num: number
 * @b: base
 * @f: args flags
 * @params: params struct
 * Return: string
 */
char *convert(long int num, int b, int f, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(f & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * _unsigned - print unsigned ints
 * @ce: args pointer
 * @params: params struct
 * Return: bytes printed
 */
int _unsigned(va_list ce, params_t *params)
{
	unsigned long l;

	if (params->l_mod)
		l = (unsigned long)va_arg(ce, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ce, unsigned int);
	else
		l = (unsigned int)va_arg(ce, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}
/**
 * print_add - prints address
 * @ce: args pointer
 * @params: params struct
 * Return: bytes printed
 */
int print_add(va_list ce, params_t *params)
{
	unsigned long int n = va_arg(ce, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
