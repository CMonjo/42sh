/*
** EPITECH PROJECT, 2018
** alias.c
** File description:
** set alias in the sheel
*/

#include "main.h"

char *my_calloc(int nbchars)
{
	char *str = (char*)malloc(sizeof(char)*nbchars);

	if (str == NULL)
		return (NULL);
	for (int i = 0; i < nbchars; i++) {
		str[i] = '\0';
	}
	return (str);
}
