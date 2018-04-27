/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** error_sep.c
*/

#include "main.h"

int	check_sep_nbr_msg(char *command, char sep, int ct)
{
	int command_sep = 0;

	while (command[ct] == sep || command[ct] == ' ' || command[ct] == '\t') {
		if (command[ct] == sep)
			command_sep ++;
		ct ++;
	}
	if (sep == '|' && command_sep > 2) {
		my_printf("Invalid null command.\n");
		exit(1);
		return (1);
	}
	if ((sep == '>' || sep == '<') && command_sep > 2) {
		my_printf("Missing name for redirect.\n");
		exit(1);
		return (1);
	}
	return (0);
}

int	check_sep_nbr(char *command, int ct)
{
	char const *tab_sep_err[4] = {"|", "<", ">"};

	for (int ctb = 0; tab_sep_err[ctb] != NULL; ctb ++) {
		if (tab_sep_err[ctb][0] == command[ct])
			if (check_sep_nbr_msg(command, command[ct], ct) == 1)
				return (1);
	}
	return (0);
}

int 	check_long_sep(char *command)
{
	for (int ct = 0; command[ct] != '\0'; ct ++) {
		if (check_sep_nbr(command, ct) == 1)
			return (1);
	}
	return (0);
}
