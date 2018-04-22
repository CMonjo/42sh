/*
** EPITECH PROJECT, 2017
** my_put_unsg_ll.c
** File description:
** my put base
*/

#include "my.h"

void	my_put_unsg_ll(unsigned long long nb)
{
	int n;

	n = nb % 10;
	nb = nb / 10;
	if (nb > 0)
		my_put_long_long(nb);
	my_putchar(n + '0');
}
