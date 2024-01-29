#include "main.h"
/**
 * chrisdigit - checks for digit chars
 * @c: chars to check
 * Return: 1 if digit, 0 otherwise
 */
int chrisdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - returns length of string
 * @s: string length to check
 * Return: int length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
/**
 * print_number - prints num
 * @str: base number
 * @params: params struct
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->m_flag)
		return (print_rs(str, params));
	else
		return (print_ls(str, params));
}
/**
 * print_rs - print num
 * @str: base number
 * @params: params struct
 * Return: chars printed
 */
int print_rs(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->z_flag && !params->m_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->m_flag)
		str++;
	else
		neg = 0;
	if ((params->p_flag && !neg2) ||
		(!params->p_flag && params->s_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->p_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->p_flag && params->s_flag && !neg2 &&
		!params->unsign && params->z_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->p_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->p_flag && params->s_flag && !neg2 &&
		!params->unsign && !params->z_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}
/**
 * print_ls - print num
 * @str: base num as string
 * @params: params struct
 * Return: chars printed
 */
int print_ls(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->z_flag && !params->m_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->m_flag)
		str++;
	else
		neg = 0;

	if (params->p_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->s_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
