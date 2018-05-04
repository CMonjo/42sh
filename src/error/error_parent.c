/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** error_sep.c
*/

#include "main.h"

int	error_null_parent(char **command)
{
	for (int ct = 0; command[ct] != NULL; ct ++) {
		if (command[ct][0] == '('
		&& command[ct + 1] != NULL && command[ct + 1][0] == ')')
			return (1);
	}
	return (0);
}

void	error_parent(char *command)
{
	int parent_left = 0;
	int parent_right = 0;

	if (error_null_parent(word_array(command)) == 1) {
		my_printf("Invalid null command.\n");
		exit(1);
	}
	for (int ct = 0; command[ct] != '\0'; ct ++) {
		if (command[ct] == 41)
			parent_right ++;
		if (command[ct] == 40)
			parent_left ++;
		if (command[ct] == 34 || command[ct] == 39) {
			ct ++;
			error_backstick_quote(command, command[ct - 1], &ct);
		}
	}
	if (parent_left == 0 && parent_right == 0)
		return;
	if (parent_left == 0) {
		my_printf("Too many %c's.\n", 41);
		exit(1);
	}
	if (parent_right == 0) {
		my_printf("Too many %c's.\n", 40);
		exit(1);
	}
	if ((parent_right / parent_left) == 0) {
		my_printf("Too many %c's.\n", 40);
		exit(1);
	}
	if ((parent_left / parent_right) == 0) {
		my_printf("Too many %c's.\n", 41);
		exit(1);
	}
}
