/*
** EPITECH PROJECT, 2017
** flag_disp.c
** File description:
** display the flag
*/

#include "my.h"
#include <stdlib.h>

void	flag_nbr_disp_err(int nbr, int len_f)
{
	nbr = nbr - len_f;
	while (nbr != 0 && nbr > 0) {
		nbr --;
		my_putchar_err(' ');
	}
}

int	flag_s_err(va_list ap, int ct, char *str, char *str_temp)
{
	int len;
	int ctp = 0;
	int nbr = 0;

	str = my_strdup(va_arg(ap, char*));
	len = my_strlen(str);
	while (str_temp[ctp] != '\0') {
		ctp ++;
		if (str_temp[ctp] >= 48 && str_temp[ctp] <= 57)
			nbr = nbr * 10 + (str_temp[ctp] - 48);
	}
	flag_nbr_disp_err(nbr, len);
	my_putstr_err(str, NULL);
	free(str);
	return (ct);
}
