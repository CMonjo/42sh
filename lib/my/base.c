/*
** EPITECH PROJECT, 2017
** base.c
** File description:
** change the base
*/

#include "my.h"

void	base(unsigned long long nbr, char *str)
{
	int len = my_strlen(str);
	unsigned long long nb = nbr % len;

	nbr = nbr / len;
	if (nbr != 0)
		base(nbr, str);
	my_putchar(str[nb]);
}
