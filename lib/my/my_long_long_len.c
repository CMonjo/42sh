/*
** EPITECH PROJECT, 2017
** my_put_long_long.c
** File description:
** my_put_long more than int
*/

#include "my.h"

int	my_long_long_len(long long nb)
{
	int len = 0;

	if (nb == 0)
		len ++;
	while (nb > 0) {
		nb = nb / 10;
		len ++;
	}
	return (len);
}
