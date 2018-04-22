/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** reverse the string you want
*/

#include "my.h"

char	swap(int a, int b, char *str)
{
	int c = str[a];

	str[a] = str[b];
	str[b] = c;
	return (0);
}
char	*my_revstr(char *str)
{
	int b = 0;
	int a = (my_strlen(str) - 1);

	while (b < a) {
		swap(a, b, str);
		b = b + 1;
		a = a - 1;
	}
	return (str);
}
