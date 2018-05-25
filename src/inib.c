/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/inib.c
*/

#include "main.h"

int	len_end_str(char *str, int *ct)
{
	int ctb = (*ct);
	int len = 0;

	while (str[ctb] == '\\')
		ctb ++;
	while (str[ctb] != '\0') {
		len ++;
		ctb ++;
	}
	return (len);
}

char *replace_inib(char *str, int *ct)
{
	int nb_back = 0;
	char *command;
	int ct_str = 0;
	int len = 0;

	for (int ctb = (*ct); str[ctb] == '\\'; ctb ++)
		nb_back ++;
	len = (*ct) + nb_back + len_end_str(str, ct);
	command = malloc(sizeof(char) * (len + 1));
	for (; ct_str != (*ct); ct_str ++)
		command[ct_str] = str[ct_str];
	for (int ctb = 0; ctb != (nb_back / 2); ctb ++, ct_str ++)
		command[ct_str] = '\\';
	(*ct) = (*ct) + nb_back;
	for (int ctb = (*ct); str[ctb] != '\0'; ctb ++, ct_str ++)
		command[ct_str] = str[ctb];
	command[ct_str] = '\0';
	free(str);
	return (command);
}

char	*chang_inib(char *str)
{
	for (int ct = 0; str[ct] != '\0'; ct ++)
		if (str[ct] == '\\')
			str = replace_inib(str, &ct);
	return (str);
}