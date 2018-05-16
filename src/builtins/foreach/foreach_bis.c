/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/foreach/foreach_bis.c
*/

#include "main.h"

int	count_ele(char **arr)
{
	int ele = 0;
	int nb_parent = 0;
	int nb_back_parent = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		if (arr[ct][0] == '(')
			nb_parent ++;
	for (int ct = 3; nb_back_parent != nb_parent; ct ++) {
		if (arr[ct][0] == ')')
			nb_back_parent ++;
		ele ++;
	}
	return (ele - 1);
}

void	prompt_foreach(void)
{
	if (isatty(0) == 1)
		my_printf("foreach? ");
}