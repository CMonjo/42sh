/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

char *concat_set(char *dest, char *src)
{
	char *newdest = NULL;

	if (src == NULL)
		return (dest);
	newdest = my_calloc(my_strlen(dest) + my_strlen(src) + 1);
	if (dest != NULL) {
		for (int i = 0; newdest != NULL && dest[i] != '\0'; i++)
			newdest[i] = dest[i];
	}
	for (int i = 0; newdest != NULL && src[i] != '\0'; i++)
		newdest[my_strlen(newdest)] = src[i];
	dest = my_calloc(my_strlen(newdest)+1);
	for (int i = 0; dest != NULL && newdest[i] != '\0'; i++)
		dest[i] = newdest[i];
	free(newdest);
	return (dest);
}

char *set_parse(char **tab)
{
	int i = 0;
	char *dest = NULL;
	char *tmp = NULL;

	for (; tab[i] != NULL; i++);
	if (i > 2) {
		dest = concat_set(dest, tab[2]);
		i = 3;
		while (tab[i] != NULL) {
			tmp = NULL;
			dest = concat_set(dest, " ");
			tmp = concat_set(tmp, tab[i]);
			dest = concat_set(dest, tmp);
			i++;
		}
	}
	return(dest);
}
