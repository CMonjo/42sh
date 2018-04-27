/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** counting the number of char in string
*/

#include "tools.h"

int	my_strlen(char *str)
{
	int a = 0;

	if (str == NULL)
		return (0);
	while (str[a] != '\0') {
		a = a + 1;
	}
	return (a);
}
