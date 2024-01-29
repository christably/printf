#include "main.h"
/**
 * chris_params - clears n reset buf
 * @params: params struct
 * @ce: args pointer
 * Return: void
 */
void chris_params(params_t *params, va_list ce)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)ce;
}
