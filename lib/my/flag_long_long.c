/*
** EPITECH PROJECT, 2017
** flag_long_long.c
** File description:
** flag long long my printf
*/

#include<stdarg.h>
#include "my.h"

int	flag_long(va_list ap, int ct, char *str, char *str_temp)
{
	long long rst = va_arg(ap, int);
	int len_f = my_long_long_len(rst);
	int ctp = 0;
	int nbr = 0;
	(void)str;

	while (str_temp[ctp] != '\0') {
		ctp ++;
		if (str_temp[ctp] >= 48 || str_temp[ctp] <= 57)
			nbr = nbr * 10 + (str_temp[ctp] - 48);
	}
	if (nbr < len_f)
		flag_nbr_disp(nbr, len_f);
	nbr_disp_thd(rst);
	return (ct);
}
