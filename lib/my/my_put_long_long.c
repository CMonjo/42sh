/*
** EPITECH PROJECT, 2017
** my_put_long_long.c
** File description:
** my_put_long more than int
*/

#include "my.h"

long long	my_put_long_long(long long nb)
{
	int n;

	if (nb < 0) {
		nb = nb * (-1);
		my_putchar('-');
	}
	n = nb % 10;
	nb = nb / 10;
	if (nb > 0)
		my_put_long_long(nb);
	my_putchar(n + '0');
	return (0);
}
