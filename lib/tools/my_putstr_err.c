/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** show my string
*/

#include "tools.h"

int my_putstr_err(char *str, char *msg)
{
	if (str != NULL) {
		for (int ct = 0; str[ct] != '\0'; ct ++)
			my_putchar_err(str[ct]);
	}
	for (int ct= 0; msg[ct] != '\0'; ct ++)
		my_putchar_err(msg[ct]);
	return (0);
}
