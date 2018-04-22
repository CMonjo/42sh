/*
** EPITECH PROJECT, 2017
** f_nbr_bis.c
** File description:
** more functions about the flags
*/

#include "my.h"

void	flag_zero_disp(int nbr, int len_f)
{
	nbr = nbr - len_f;
	while (nbr != 0) {
		nbr --;
		my_putchar('0');
	}
}

void	flag_sign(long long rst)
{
	if (rst >= 0)
		my_putchar('+');
}

void	flag_has_o(char *str_temp)
{
	if (str_temp[1] == '#')
		my_putchar('0');
}

void	flag_has_x(char *str_temp)
{
	if (str_temp[1] == '#')
		my_putstr("0x", 2);
}

void	flag_has_xx(char *str_temp)
{
	if (str_temp[1] == '#')
		my_putstr("0X", 2);
}
