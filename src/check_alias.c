/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/check_alias.c
*/

#include "main.h"

void	pass_alias_unalias(char **arr, int *ct)
{
	(*ct) ++;
	while (arr[*ct] != NULL && check_bult_in(arr[*ct]) == -1
	&& check_sep_char(arr[*ct]) == -1)
		(*ct) ++;
}

int	check_same_alias(char *command, env_st_t *env_st)
{
	alias_t* alias = env_st->alias;

	while (alias != NULL) {
		if (alias->active == 1 && my_strcmp(alias->bind, command) == 0
		&& my_strcmp(alias->command_bind, command) == 0)
			return (1);
		alias = alias->next;
	}
	return (0);
}

int	check_alias_local_var(char *command, char *str, env_st_t *env_st)
{
	alias_t* alias = env_st->alias;

	if (check_same_alias(command, env_st) == 1)
		return (0);
	if (alias != NULL && error_alias_loop(command, str, env_st) == 1)
		return (1);
	while (alias != NULL) {
		if (alias->active == 1
		&& my_strcmp(alias->bind, command) == 0) {
			check_gnl(alias->command_bind,
			env_st->envp_cpy, env_st,
			my_list_command(alias->command_bind, env_st, 0, 1));
			return (1);
		}
		alias = alias->next;
	}
	return (0);
}
