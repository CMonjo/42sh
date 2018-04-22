/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** my_put_number
*/

#include "my.h"

int	my_put_nbr(int nb)
{
	int n;

	if (nb == -2147483648)
		my_putstr("-2147483648", my_strlen("-2147483648"));
	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	n = nb % 10;
	nb = nb / 10;
	if (nb > 0)
		my_put_nbr(nb);
	my_putchar(n + '0');
	return (0);
}
