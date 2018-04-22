/*
** EPITECH PROJECT, 2017
** flag_nbr.c
** File description:
** flag with number
*/

#include <stdarg.h>
#include "my.h"

int	flag_h_nbr(va_list ap, int ct, char *str, char *str_temp)
{
	long long rst = (short)va_arg(ap, int);
	int len_f = my_long_long_len(rst);
	int ctp = 0;
	int nbr = 0;
	(void)str;

	while (str_temp[ctp] != '\0') {
		ctp ++;
		if (str_temp[ctp] >= 48 || str_temp[ctp] <= 57)
			nbr = nbr * 10 + (str_temp[ctp] - 48);
	}
	flag_nbr_disp(nbr, len_f);
	nbr_disp_thd(rst);
	return (ct);
}

int	flag_long_long(va_list ap, int ct, char *str, char *str_temp)
{
	long long rst = va_arg(ap, long long);
	int len_f = my_long_long_len(rst);
	int ctp = 0;
	int nbr = 0;
	(void)str;

	while (str_temp[ctp] != '\0') {
		ctp ++;
		if (str_temp[ctp] >= 48 && str_temp[ctp] <= 57)
			nbr = nbr * 10 + (str_temp[ctp] - 48);
	}
	flag_nbr_disp(nbr, len_f);
	nbr_disp_thd(rst);
	return (ct);
}

int	flag_unsg_short(va_list ap, int ct, char *str, char *str_temp)
{
	long long rst = (unsigned short)va_arg(ap, unsigned int);
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

int	flag_unsg_l(va_list ap, int ct, char *str, char *str_temp)
{
	unsigned long long rst = va_arg(ap, unsigned long);
	int len_f = my_long_long_len(rst);
	int ctp = 0;
	int nbr = 0;
	(void)str;

	while (str_temp[ctp] != '\0') {
		ctp ++;
		if (str_temp[ctp] >= 48 || str_temp[ctp] <= 57)
			nbr = nbr * 10 + (str_temp[ctp] - 48);
	}
	flag_nbr_disp(nbr, len_f);
	nbr_disp_thd(rst);
	return (ct);
}

int	flag_unsg_ll(va_list ap, int ct, char *str, char *str_temp)
{
	unsigned long long rst = va_arg(ap, unsigned long long);
	int len_f = my_long_long_len(rst);
	int ctp = 0;
	int nbr = 0;
	(void)str;

	while (str_temp[ctp] != '\0') {
		ctp ++;
		if (str_temp[ctp] >= 48 || str_temp[ctp] <= 57)
			nbr = nbr * 10 + (str_temp[ctp] - 48);
	}
	flag_nbr_disp(nbr, len_f);
	nbr_disp_thd(rst);
	return (ct);
}
