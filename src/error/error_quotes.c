/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** error_sep.c
*/

#include "main.h"

int	error_backstick_quote(char *str, char c, int *ct)
{
	(*ct) ++;
	while (str[*ct] != '\0') {
		if (str[*ct] == c)
			return (0);
		(*ct) ++;
	}
	if (c == 39) {
		my_printf("Unmatched '%c'.\n", c);
		return (-1);
	}
	my_printf("Unmatched %c.\n", c);
	return (-1);
}
