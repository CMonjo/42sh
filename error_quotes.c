/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** error_sep.c
*/

#include "my.h"

void	error_backstick_quote(char *str, char c, int *ct)
{
	while (str[*ct] != '\0') {
		if (str[*ct] == c)
			return;
		(*ct) ++;
	}
	if (c == 39) {
		my_printf("Unmatched '%c'.\n", c);
		exit(1);
	}
	my_printf("Unmatched %c.\n", c);
	exit(1);
}