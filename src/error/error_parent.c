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
		&& command[ct + 1] != NULL && command[ct + 1][0] == ')') {
			my_printf("Invalid null command.\n");
			return (1);
		}
		if (command[ct][0] == '('
		&& command[ct + 1] != NULL
		&& check_sep_char(command[ct + 1]) != -1) {
			my_printf("Badly placed ()'s.\n");
			return (1);
		}
	}
	return (0);
}

void	error_parent_next(int *parent_left, int *parent_right, char *command)
{
	for (int ct = 0; command[ct] != '\0'; ct ++) {
		if (command[ct] == ')')
			*parent_right += 1;
		if (command[ct] == '(')
			*parent_left += 1;
		if (command[ct] == 34 || command[ct] == 39) {
			ct ++;
			error_backstick_quote(command, command[ct - 1], &ct);
		}
	}
}

int	error_parent_next_next(int parent_left, int parent_right)
{
	if (parent_right == 0) {
		my_printf("Too many %c's.\n", '(');
		return (1);
	}
	if ((parent_right / parent_left) == 0) {
		my_printf("Too many %c's.\n", '(');
		return (1);
	}
	if ((parent_left / parent_right) == 0) {
		my_printf("Too many %c's.\n", ')');
		return (1);
	}
	return (0);
}

int	error_parent(char *command)
{
	int parent_left = 0;
	int parent_right = 0;

	error_parent_next(&parent_left, &parent_right, command);
	if (parent_left == 0 && parent_right == 0)
		return (0);
	if (parent_left == 0) {
		my_printf("Too many %c's.\n", ')');
		return (1);
	}
	return (error_parent_next_next(parent_left, parent_right));
}
