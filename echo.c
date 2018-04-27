/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for the cd func
*/

#include "my.h"

int	echo(char **arr, char **envp, env_st_t *env_st)
{
	if (arr[1] == NULL)
		return (0);
	for (int ct = 1; arr[ct] != NULL; ct ++) {
		my_printf("%s", arr[ct]);
		if (arr[ct + 1] != NULL)
			my_putchar(' ');
	}
	my_putchar('\n');
	return (0);
}