/*
** EPITECH PROJECT, 2017
** flag_base_bis.c
** File description:
** base for other length
*/

#include <stdarg.h>
#include "my.h"

int	flag_ll_x(va_list ap, int ct, char *str, char *str_temp)
{
	char base_hexa_x[] = "0123456789abcdef";
	(void)str_temp;
	(void)str;

	flag_has_x(str_temp);
	base(va_arg(ap, unsigned long long), base_hexa_x);
	return (ct);
}

int	flag_ll_xx(va_list ap, int ct, char *str, char *str_temp)
{
	(void)str_temp;
	(void)str;
	(void)ap;

	return (ct);
}

int	flag_ll_o(va_list ap, int ct, char *str, char *str_temp)
{
	char base_oct[] = "01234567";
	(void)str_temp;
	(void)str;

	base(va_arg(ap, unsigned long long), base_oct);
	return (ct);
}

int	flag_ll_b(va_list ap, int ct, char *str, char *str_temp)
{
	char base_bin[] = "01";
	(void)str_temp;
	(void)str;

	base(va_arg(ap, unsigned long long), base_bin);
	return (ct);
}

int	flag_hh_d(va_list ap, int ct, char *str, char *str_temp)
{
	long long rst = (char)va_arg(ap, unsigned long long);
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
