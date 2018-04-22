/*
** EPITECH PROJECT, 2017
** f_nbr.c
** File description:
** fonctions for flags and number
*/

#include "my.h"

int	flag_plus(char *str_temp, long long rst, int b, int nbr)
{
	if (rst >= 0 && str_temp[1] == '+' && b == 0) {
		my_putchar('+');
		nbr --;
	}
	return (nbr);
}

int	flag_plus_bis(char *str_temp, long long rst, int b)
{
	if (str_temp[1] == '+' && b == 1)
		flag_sign(rst);
	return (0);
}

int	nbr_disp(int temp_len, char *str_temp, int nbr, int b)
{
	if (nbr > temp_len && str_temp[1] != '0' && b == 0
	&& str_temp[2] != '0')
		flag_nbr_disp(nbr, temp_len);
	if ((str_temp[1] == '0' || str_temp[2] == '0') && b == 0)
		flag_zero_disp(nbr, temp_len);
	return (0);
}

int	nbr_disp_bis(int temp_len, char *str_temp, int nbr_f, int b)
{
	if (str_temp[1] == '+' && b == 1)
		nbr_f --;
	if (nbr_f > temp_len && b == 1)
		flag_nbr_disp(nbr_f, temp_len);
	return (0);
}

int	nbr_disp_thd(long long rst)
{
	my_put_long_long(rst);
	return (0);
}
