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

	params->p_flag = 0;
	params->s_flag = 0;
	params->h_flag = 0;
	params->z_flag = 0;
	params->m_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_mod = 0;
	params->l_mod = 0;
	(void)ce;
}
