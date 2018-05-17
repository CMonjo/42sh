/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/foreach/error_foreach.c
*/

#include "main.h"

int	error_foreach_alphanumeric(char **arr, env_st_t *env_st)
{
	int b = 0;

	for (int ct = 0; arr[1][ct] != '\0'; ct ++) {
		if ((arr[1][ct] > 47 && arr[1][ct] < 58) || arr[1][ct] == '_')
			b = 1;
		if (b == 0 && (arr[1][ct] < 65 ||
		(arr[1][ct] > 90 && arr[1][ct] < 97)
		|| arr[1][ct] > 122)) {
			my_putstr_err(NULL, "foreach: Variable name must cont");
			my_putstr_err(NULL, "ain alphanumeric characters.\n");
			env_st->status = 1;
			return (1);
		}
		b = 0;
	}
	return (0);
}

int	error_foreach_args(char **arr, env_st_t *env_st, int tab_len)
{
	if (arr[2][0] != '(' || arr[tab_len - 1][0] != ')') {
		env_st->status = 1;
		my_putstr_err(NULL, "foreach: Words not parenthesized.\n");
		return (1);
	}
	if ((arr[1][0] < 65 ||
		(arr[1][0] > 90 && arr[1][0] < 97)
		|| arr[1][0] > 122) && arr[1][0] != '_') {
		my_putstr_err(NULL,
		"foreach: Variable name must begin with a letter.\n");
		env_st->status = 1;
		return (1);
	}
	return (0);
}

int	error_foreach(char **arr, env_st_t *env_st)
{
	int tab_len = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		tab_len ++;
	if (tab_len < 4) {
		env_st->status = 1;
		my_putstr_err(NULL, "foreach: Too few arguments.\n");
		return (1);
	}
	if (error_foreach_args(arr, env_st, tab_len) == 1 ||
	error_foreach_alphanumeric(arr, env_st) == 1)
		return (1);
	return (0);
}