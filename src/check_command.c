/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** check_command.c
*/

#include "main.h"

int	check_sep_char(char *str)
{
	for (int ct = 1; tab_name[ct] != NULL; ct ++)
		if (my_strcmp_c(str, tab_name[ct]) == 0)
			return (ct);
	return (-1);
}

void	skip_parent(char **arr, int *ctb)
{
	int nb_parent = 0;
	int nb_parent_out = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++) {
		if (arr[ct][0] == ')')
			break;
		if (arr[ct][0] == '(')
			nb_parent ++;
	}
	(*ctb) ++;
	while (nb_parent_out != nb_parent) {
		if (arr[*ctb][0] == ')')
			nb_parent_out ++;
		(*ctb) ++;
	}
	//printf("COMMAND   : %s\n", arr[*ctb]);
}

int	check_sep(char **arr)
{
	int value = 0;
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
	/*for (int ctb = 0; arr[ctb] != NULL; ctb ++)
		if (my_strcmp(arr[ctb], "||") == 0)
			return (1);
	for (int ctb = 0; arr[ctb] != NULL; ctb ++)
		if (my_strcmp(arr[ctb], "&&") == 0)
			return (2);*/
	for (int ctb = ct; arr[ctb] != NULL; ctb ++) {
		if (arr[ctb][0] == '(')
			skip_parent(arr, &ctb);
		if (arr[ctb] == NULL)
			break;
		if (my_strcmp(arr[ctb], ">") == 0)
			return (7);
	}
	for (int ctb = ct; arr[ctb] != NULL; ctb ++) {
		if (arr[ctb][0] == '(')
			skip_parent(arr, &ctb);
		if (arr[ctb] == NULL)
			break;
		if (my_strcmp(arr[ctb], ">>") == 0)
			return (4);
	}
	for (int ctb = ct; arr[ctb] != NULL; ctb ++) {
		//printf("SEP  :  %s\n", arr[ctb]);
		if (arr[ctb][0] == '(')
			skip_parent(arr, &ctb);
		if (arr[ctb] == NULL)
			break;
		if ((value = check_sep_char(arr[ctb])) != -1)
			return (value);
	}
	return (-1);
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
