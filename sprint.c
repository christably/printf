#include "main.h"
/**
 * print_ft - prints char add
 * @st: begining add
 * @sp: ending add
 * @et: except add
 * Return: number bytes printed
 */
int print_ft(char *st, char *sp, char *et)
{
	int sum = 0;

	while (st <= sp)
	{
		if (st != et)
			sum += _putchar(*st);
		st++;
	}
	return (sum);
}
/**
 * print_v - prints string in reverse
 * @ce: string
 * @params: params struct
 * Return: bytes printed
 */
int print_v(va_list ce, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ce, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}
/**
 * print_rt - prints string
 * @ce: string
 * @params: params struct
 * Return: number bytes printed
 */
int print_rt(va_list ce, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ce, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
