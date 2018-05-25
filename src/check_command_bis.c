/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/check_command_bis.c
*/

#include "main.h"

int	check_sep_char(char *str)
{
	for (int ct = 1; tab_name[ct] != NULL; ct ++) {
		if (my_strcmp_c(str, tab_name[ct]) == 0)
			return (ct);
	}
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
}

int	check_sep_bis_second(char **arr)
{
	int value = 0;
	int ct = 0;

	for (int ctb = ct; arr[ctb] != NULL; ctb ++) {
		if (arr[ctb][0] == '(')
			skip_parent(arr, &ctb);
		if (arr[ctb] == NULL)
			break;
		if (my_strcmp(arr[ctb], ">>") == 0)
			return (4);
	}
	for (int ctb = ct; arr[ctb] != NULL; ctb ++) {
		if (arr[ctb][0] == '(')
			skip_parent(arr, &ctb);
		if (arr[ctb] == NULL)
			break;
		if ((value = check_sep_char(arr[ctb])) != -1)
			return (value);
	}
	return (-1);
}