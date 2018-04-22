/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** strcmp comparing two strings
*/

#include "my.h"

int	my_strcmp_c(char *s1, char const *s2)
{
	int c = 0;

	while (s1[c] != '\0' && s2[c] != '\0' && s1[c] == s2[c]) {
		c = c + 1;
	}
	return (s1[c] - s2[c]);
}

int	my_strcmp(char *s1, char *s2)
{
	int c = 0;

	while (s1[c] != '\0' && s2[c] != '\0' && s1[c] == s2[c]) {
		c = c + 1;
	}
	return (s1[c] - s2[c]);
}
