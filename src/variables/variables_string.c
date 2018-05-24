/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/variables_string.c
*/

#include "main.h"

char	*first_string(char *str, int *ct)
{
	char *command = malloc(sizeof(char) * ((*ct) + 1));

	for (int ctb = 0; ctb != (*ct); ctb ++)
		command[ctb] = str[ctb];
	command[*ct] = '\0';
	return (command);
}

char	*variable_name_string(char *str, int *ct)
{
	char *command;
	int len = 0;
	int ctb = 0;

	(*ct) ++;
	for (int ctb = (*ct); str[ctb] != '\0'
	&& str[ctb] != ' ' && str[ctb] != '\t'; ctb ++)
		len ++;
	command = malloc(sizeof(char) * (len + 1));
	while (str[*ct] != '\0' && str[*ct] != ' ' && str[*ct] != '\t') {
		command[ctb] = str[*ct];
		ctb ++;
		(*ct) ++;
	}
	command[ctb] = '\0';
	return (command);
}

char	*second_string(char *str, int *ct)
{
	char *command = malloc(sizeof(char) * (my_strlen(str) - (*ct) + 1));
	int ctb = 0;

	for (int ctp = (*ct); str[ctp] != '\0'; ctb ++, ctp ++) {
		command[ctb] = str[ctp];
	}
	command[ctb] = '\0';
	return (command);
}