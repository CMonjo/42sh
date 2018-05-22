/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** the prompte function of the minishell1
*/

#include "main.h"

int	error_alias_loop_detec(char *first, alias_t* alias, env_st_t *env_st)
{
	if (my_strcmp(alias->command_bind, first) == 0) {
		env_st->status = 1;
		my_printf("Alias loop.\n");
		return (1);
	}
	return (0);
}

int	error_alias_loop(char *first, char *str, env_st_t *env_st)
{
	alias_t* alias = env_st->alias;

	while (alias != NULL) {
		if (my_strcmp(alias->bind, str) == 0
		&& my_strcmp(alias->command_bind, str) == 0)
			return (0);
		if (my_strcmp(alias->bind, str) == 0
		&& error_alias_loop_detec(first, alias, env_st) == 1)
			return (1);
		else if (my_strcmp(alias->bind, str) == 0) {
			str = my_strdup(alias->command_bind);
			alias = env_st->alias;
		} else
			alias = alias->next;
	}
	return (0);
}

int	error_alias_dangerous(char **arr, env_st_t *env_st)
{
	int tab_len = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		tab_len ++;
	if (tab_len < 3)
		return (0);
	if (my_strcmp(arr[0], "alias") == 0
	&& my_strcmp(arr[1], "alias") == 0) {
		env_st->status = 1;
		my_putstr_err(NULL, "alias: Too dangerous to alias that.\n");
		return (1);
	}
	return (0);
}
