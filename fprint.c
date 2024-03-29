#include "main.h"
/**
 * chris_char - prints char
 * @ce: arg pointer
 * @params: params struct
 * Return: num chars
 */
int chris_char(va_list ce, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ce, int);

	if (params->m_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->m_flag)
		sum += _putchar(ch);
	return (sum);
}
/**
 * print_int - prints int
 * @ap: args pointer
 * @params: paras struct
 * Return: chars printed
 */
int print_int(va_list ce, params_t *params)
{
	long l;

	if (params->l_mod)
		l = va_arg(ce, long);
	else if (params->h_mod)
		l = (short int)va_arg(ce, int);
	else
		l = (int)va_arg(ce, int);
	return (print_number(convert(l, 10, 0, params), params));
}
/**
 * print_string - prints string
 * @ap: args pointer
 * @params: params struct
 * Return: chars printed
 */
int print_string(va_list ce, params_t *params)
{
	char *str = va_arg(ce, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->m_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->m_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @ce: args pointer
 * @params: params struct
 * Return: chars printed
 */
int print_percent(va_list ce, params_t *params)
{
	(void)ce;
	(void)params;
	return (_putchar('%'));
}
/**
 * sprintt - c format spf
 * @ce: args pointer
 * @params: params struct
 * Return: chars printed
 */
int sprintt(va_list ce, params_t *params)
{
	char *str = va_arg(ce, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
