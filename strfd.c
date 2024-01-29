#include "main.h"
/**
 * get_precision - gets precision
 * @p: format string
 * @params: params struct
 * @ce: args pointer
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ce)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ce, int);
		p++;
	}
	else
	{
		while (chrisdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
