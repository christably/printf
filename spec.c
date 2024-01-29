#include "main.h"
/**
 * spec_get - finds format func
 * @s: format string
 * Return: bytes printed
 */
int (*spec_get(char *s))(va_list ce, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
/**
 * printf_get - finds format func
 * @s: format string
 * @ce: args pointer
 * @params: params struct
 * Return: num of bytes printed
 */
int printf_get(char *s, va_list ce, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ce, params));
	return (0);
}
/**
 * f_get - finds the flag func
 * @s: format string
 * @params: the params struct
 * Return: if flag was valid
 */
int f_get(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->p_flag = 1;
			break;
		case ' ':
			i = params->s_flag = 1;
			break;
		case '#':
			i = params->h_flag = 1;
			break;
		case '-':
			i = params->m_flag = 1;
			break;
		case '0':
			i = params->z_flag = 1;
			break;
	}
	return (i);
}
/**
 * get_modifier - finds modifier func
 * @s: format string
 * @params: params struct
 * Return: if modifier valid
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}
	return (i);
}
/**
 * get_width - from format string
 * @s: format string
 * @params: params struct
 * @ce: the arg pointer
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ce)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ce, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
