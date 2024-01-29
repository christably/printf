#include "main.h"
/**
 * _printf - prints anything
 * @format: format string
 * Return: bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ce;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ce, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ce);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (f_get(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, ce);
		p = get_precision(p, &params, ce);
		if (get_modifier(p, &params))
			p++;
		if (!spec_get(p))
			sum += printft(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += printf_get(p, ce, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ce);
	return (sum);
}
