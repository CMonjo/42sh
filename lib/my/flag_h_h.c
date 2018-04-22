/*
** EPITECH PROJECT, 2017
** flag_h_h.c
** File description:
** hh flags cast an int in char
*/

#include <stdarg.h>
#include "my.h"

int	flag_hh_x(va_list ap, int ct, char *str, char *str_temp)
{
	char base_hexa_x[] = "0123456789abcdef";
	(void)str_temp;
	(void)str;

	flag_has_x(str_temp);
	base((char)va_arg(ap, unsigned int), base_hexa_x);
	return (ct);
}

int	flag_hh_xx(va_list ap, int ct, char *str, char *str_temp)
{
	char base_hexa_X[] = "0123456789ABCDEF";
	(void)str_temp;
	(void)str;

	flag_has_x(str_temp);
	base((char)va_arg(ap, unsigned int), base_hexa_X);
	return (ct);
}

int	flag_hh_o(va_list ap, int ct, char *str, char *str_temp)
{
	(void)str_temp;
	(void)str;
	(void)ap;

	return (ct);
}

int	flag_hh_b(va_list ap, int ct, char *str, char *str_temp)
{
	char base_bin[] = "01";
	(void)str_temp;
	(void)str;

	base((char)va_arg(ap, unsigned int), base_bin);
	return (ct);
}

int	flag_hh_u(va_list ap, int ct, char *str, char *str_temp)
{
	long long rst = (char)va_arg(ap, unsigned int);
	int len_f = my_long_long_len(rst);
	int ctp = 0;
	int nbr = 0;
	(void)str;

	while (str_temp[ctp] != '\0') {
		ctp ++;
		if (str_temp[ctp] >= 48 || str_temp[ctp]  <= 57)
			nbr = nbr * 10 + (str_temp[ctp] - 48);
	}
	flag_nbr_disp(nbr, len_f);
	nbr_disp_thd(rst);
	return (ct);
}
