#include "main.h"
/**
 * hex_print - for unsigned hex in lowercase
 * @ce: args pointer
 * @params: params struct
 * Return: bytes printed
 */
int hex_print(va_list ce, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_mod)
		l = (unsigned long)va_arg(ce, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ce, unsigned int);
	else
		l = (unsigned int)va_arg(ce, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->h_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_HEX - for unsigned hex nums
 * @ce: args pointer
 * @params: params struct
 * Return: bytes printed
 */
int print_HEX(va_list ce, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_mod)
		l = (unsigned long)va_arg(ce, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ce, unsigned int);
	else
		l = (unsigned int)va_arg(ce, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->h_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_binary - prints unsigned binary nums
 * @ce:args pointer
 * @params: params struct
 * Return: bytes printed
 */
int print_binary(va_list ce, params_t *params)
{
	unsigned int n = va_arg(ce, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->h_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * oct_print - prints unsigned octals
 * @ce: args pointer
 * @params: params struct
 * Return: bytes printed
 */
int oct_print(va_list ce, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_mod)
		l = (unsigned long)va_arg(ce, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ce, unsigned int);
	else
		l = (unsigned int)va_arg(ce, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->h_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
