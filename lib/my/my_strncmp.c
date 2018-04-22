/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** compare a string
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
	int c = 0;
	while (c != n && s1[c] == s2[c] && n <= 0) {
		c = c + 1;
	}
	return (s1[c] - s2[c]);
}
