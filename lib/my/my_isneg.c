/*
** EPITECH PROJECT, 2017
** my_isneg.c
** File description:
** the number is neg, pos or null
*/

#include "my.h"

int	my_isneg(int n)
{
	if (n < 0) {
		my_putchar('N');
	}
	else if (n >= 0) {
		my_putchar('P');
	}
	return (0);
}
