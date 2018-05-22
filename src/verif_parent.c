/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** main.c
*/

#include "main.h"

int	nb_char_in_str(char *str, char c)
{
	int i = 0;
	int ct = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			ct = ct + 1;
		i = i + 1;
	}
	return (ct);
}

int	verif_parent_next_rev(char *str, int ct)
{
	int ctb = 0;
	int i = my_strlen(str) - 1;

	while (i != -1) {
		if (str[i] == ')')
			ctb = ctb + 1;
		if (ctb == ct)
			break;
		i = i - 1;
	}
	return (i);
}

int	verif_parent_next(char *str, int ct)
{
	int ctb = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == '(')
			ctb = ctb + 1;
		if (ctb == ct)
			break;
		i = i + 1;
	}
	return (i);
}

char	*rm_char(char *str, int ct)
{
	char *dest = malloc(sizeof(char) * (my_strlen(str)));
	int i = 0;
	int w = 0;

	while (str[i] != '\0') {
		if (i != ct) {
			dest[w] = str[i];
			w = w + 1;
		}
		i = i + 1;
	}
	free(str);
	dest[w] = '\0';
	return (dest);
}