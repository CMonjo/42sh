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

char *concat_alias(char *dest, char *src)
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

char *alias_parse_parenthesis(char **tab)
{
	int i = 0;
	char *dest = NULL;
	char *tmp = NULL;

	for (; tab[i] != NULL; i++);
	if (i > 3) {
		dest = concat_alias("(", dest);
		dest = concat_alias(dest, tab[2]);
		i = 3;
		while (tab[i] != NULL) {
			tmp = NULL;
			dest = concat_alias(dest, " ");
			tmp = concat_alias(tmp, tab[i]);
			dest = concat_alias(dest, tmp);
			i++;
		}
		dest = concat_alias(dest, ")");
	}
	return(dest);
}

char *alias_parse(char **tab)
{
	int i = 0;
	char *dest = NULL;
	char *tmp = NULL;

	for (; tab[i] != NULL; i++);
	if (i > 2) {
		dest = concat_alias(dest, tab[2]);
		i = 3;
		while (tab[i] != NULL) {
			tmp = NULL;
			dest = concat_alias(dest, " ");
			tmp = concat_alias(tmp, tab[i]);
			dest = concat_alias(dest, tmp);
			i++;
		}
	}
	return(dest);
}


char *alias_check_string(char *long_str, char *parents)
{
	if (parents == NULL)
		return(long_str);
	else
		return(parents);
}
