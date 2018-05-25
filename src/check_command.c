/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** check_command.c
*/

#include "main.h"

int	check_sep_bis(char **arr)
{
	int ct = 0;

	for (int ctb = ct; arr[ctb] != NULL; ctb ++) {
		if (arr[ctb][0] == '(')
			skip_parent(arr, &ctb);
		if (arr[ctb] == NULL)
			break;
		if (my_strcmp(arr[ctb], ">") == 0)
			return (7);
	}
	return (check_sep_bis_second(arr));
}

int	check_sep(char **arr)
{
	int ct = 0;

	if (arr == NULL)
		return (-2);
	for (int ctb = 0; arr[ctb] != NULL; ctb ++) {
		if (my_strcmp(arr[ctb], "if") == 0
		|| my_strcmp(arr[ctb], "foreach") == 0)
			return (-3);
	}
	for (int ctb = ct; arr[ctb] != NULL; ctb ++) {
		if (arr[ctb][0] == '(')
			skip_parent(arr, &ctb);
		if (arr[ctb] == NULL)
			break;
		if (my_strcmp(arr[ctb], ";") == 0)
			return (0);
	}
	return (check_sep_bis(arr));
}

char	*check_command_bis(int ct, char *command, int *b)
{
	for (int ctb = 0; tab_name[ctb] != NULL; ctb ++)
		if (command[ct] == tab_name[ctb][0]) {
			return (start_sep_command(ct, command, b));
		}
	return (command);
}

char	*check_command(char *command, int b)
{
	for (int ct = 0; command[ct] != '\0'; ct ++) {
		command = check_command_bis(ct, command, &b);
		if (b == 1) {
			ct = 0;
			b = 0;
		}
	}
	return (command);
}
