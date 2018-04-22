/*
** EPITECH PROJECT, 2017
** flag_base.c
** File description:
** flag base and int
*/

#include <stdarg.h>
#include "my.h"

int	flag_x(va_list ap, int ct, char *str, char *str_temp)
{
	char base_hexa_x[] = "0123456789abcdef";
	(void)str_temp;
	(void)str;

	flag_has_x(str_temp);
	base(va_arg(ap, unsigned int), base_hexa_x);
	return (ct);
}

int	flag_p(va_list ap, int ct, char *str, char *str_temp)
{
	char base_hexa_x[] = "0123456789abcdef";
	(void)str_temp;
	(void)str;

	my_putstr("0x", 2);
	base(va_arg(ap, unsigned long long), base_hexa_x);
	return (ct);
}

int	flag_xx(va_list ap, int ct, char *str, char *str_temp)
{
	(void)str_temp;
	(void)str;
	(void)ap;

	return (ct);
}

int	flag_o(va_list ap, int ct, char *str, char *str_temp)
{
	char base_oct[] = "01234567";
	(void)str_temp;
	(void)str;

	flag_has_o(str_temp);
	base(va_arg(ap, unsigned int), base_oct);
	return (ct);
}

int	flag_b(va_list ap, int ct, char *str, char *str_temp)
{
	char base_bin[] = "01";
	(void)str_temp;
	(void)str;

	base(va_arg(ap, unsigned int), base_bin);
	return (ct);
}
