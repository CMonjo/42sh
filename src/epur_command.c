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

char	*start_sep_command(int ct, char *command, int *b)
{
	if (ct != 0 && command[ct - 1] != 32 && command[ct - 1] != '<'
	&& command[ct - 1] != '>' && command[ct - 1] != '|'
	&& command[ct - 1] != '&') {
		(*b) = 1;
		return (epur_command(ct, command));
	}
	if (command[ct + 1] != '\0' && command[ct + 1] != '<'
	&& command[ct + 1] != '>' && command[ct + 1] != 32
	&& command[ct + 1] != '|' && command[ct + 1] != '&') {
			(*b) = 1;
			return (epur_command(ct + 1, command));
	}
	return (command);
}
