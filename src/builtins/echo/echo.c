/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for the cd func
*/

#include "main.h"

void	skip_print_quotes(char **arr, int ct, int ctb, char c)
{
	while (arr[ct][ctb] != c) {
		my_printf("%c", arr[ct][ctb]);
		ctb ++;
	}
	ctb ++;
	while (arr[ct][ctb] != '\0') {
		if (arr[ct][ctb] == 39 || arr[ct][ctb] == 34) {
			skip_print_quotes(arr, ct, ctb, arr[ct][ctb]);
			return;
		}
		my_printf("%c", arr[ct][ctb]);
		ctb ++;
	}
}

int	echo(char **arr, UNUSED char **envp, UNUSED env_st_t *env_st)
{
	if (arr[1] == NULL)
		return (0);
	for (int ct = 2; arr[ct] != NULL; ct ++) {
		if (arr[ct][0] == 39 || arr[ct][0] == 34)
			skip_print_quotes(arr, ct, 1, arr[ct][0]);
		else
			my_printf("%s", arr[ct]);
		if (arr[ct + 1] != NULL)
			my_putchar(' ');
	}
	my_putchar('\n');
	return (0);
}
