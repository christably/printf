#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define FIELD_BUF_SIZE 50
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * @minus_flag: for _flag
 * @width: field width
 * @precision: field precision
 * @h_mod: for h_modifier
 * @l_mod: for l_modifier
 * struct parameters - params struct
 * @unsign: when value is unsigned flag
 * @p_flag: for plus_flag
 * @s_flag: for hashtag_flag
 * @h_flag: for _flag
 * @z_flag: for _flag
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int p_flag		: 1;
	unsigned int s_flag		: 1;
	unsigned int h_flag	: 1;
	unsigned int z_flag		: 1;
	unsigned int m_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_mod		: 1;
	unsigned int l_mod		: 1;
} params_t;

/**
 * struct specifier - stucr
 * @specifier: format
 * @f: function
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* cput.c module */
int _puts(char *str);
int _putchar(int c);

/* fprint.c module */
int chris_char(va_list ce, params_t *params);
int print_int(va_list ce, params_t *params);
int print_string(va_list ce, params_t *params);
int print_percent(va_list ce, params_t *params);
int sprintt(va_list ce, params_t *params);

/* nmb.c module */
char *convert(long int num, int b, int f, params_t *params);
int _unsigned(va_list ce, params_t *params);
int print_add(va_list ce, params_t *params);

/* spec.c module */
int (*spec_get(char *s))(va_list ce, params_t *params);
int printf_get(char *s, va_list ce, params_t *params);
int f_get(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ce);

/* numc.c module */
int hex_print(va_list ce, params_t *params);
int print_HEX(va_list ce, params_t *params);
int print_binary(va_list ce, params_t *params);
int oct_print(va_list ce, params_t *params);

/* sprint.c module */
int print_ft(char *st, char *sp, char *et);
int print_v(va_list ce, params_t *params);
int print_rt(va_list ce, params_t *params);

/* nump.c module */
int chrisdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_rs(char *str, params_t *params);
int print_ls(char *str, params_t *params);

/* params.c module */
void chris_params(params_t *params, va_list ce);

/* strfd.c modoule */
char *get_precision(char *p, params_t *params, va_list ce);

/* print.c module */
int _printf(const char *format, ...);

#endif
