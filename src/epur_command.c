/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** epur_command.c
*/

#include "main.h"

char	*epur_command(int ctp, char *command)
{
	char *str = malloc(sizeof(char) * (my_strlen(command) + 2));
	int ct = 0;

	for (int i = 0; command[ct] != '\0'; i ++) {
		if (ct == ctp) {
			str[i] = 32;
			ctp = -1;
		}
		else {
			str[i] = command[ct];
			ct ++;
		}
	}
	str[my_strlen(command) + 1] = '\0';
	return (str);
}

char	*epur_command_sep(char sep, char *command, int ct, int *b)
{
	if (command[ct + 1] == sep && command[ct + 2] != '\0'
	&& command[ct + 2] != ' ') {
		(*b) = 1;
		return (epur_command(ct + 2, command));
	}
	if (command[ct + 1] != sep && command[ct + 1] != '\0'
	&& command[ct + 1] != ' ') {
		(*b) = 1;
		return (epur_command(ct + 1, command));
	}
	return (command);
}

char	*start_sep_command(int ct, char *command, int *b)
{
	char const *tab_sep_err[8] = {";", "(", ")", "&", "|", "<", ">"};

	if (ct != 0 && command[ct - 1] != 32 && command[ct - 1] != '<'
	&& command[ct - 1] != '>' && command[ct - 1] != '|'
	&& command[ct - 1] != '&') {
		(*b) = 1;
		return (epur_command(ct, command));
	}
	for (int ctb = 0; tab_sep_err[ctb] != NULL; ctb ++)
		if (command[ct] == tab_sep_err[ctb][0])
			return (epur_command_sep(tab_sep_err[ctb][0],
			command, ct, b));
	return (command);
}
