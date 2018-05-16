/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/where/where_bis.c
*/

#include "main.h"

int	where_alias(char *str, env_st_t *env_st)
{
	alias_t *alias = env_st->alias;

	while (alias != NULL) {
		if (my_strcmp(alias->bind, str) == 0) {
			my_printf("%s is aliased to %s\n",
			alias->bind, alias->command_bind);
			return (1);
		}
		alias = alias->next;
	}
	return (0);
}

int	where_builtin(char *str)
{
	if (check_bult_in(str) != -1) {
		my_printf("%s is a shell built-in\n", str);
		return (1);
	}
	return (0);
}

int	where_path(char *str, env_st_t *env_st)
{
	if (access(str, F_OK) != -1) {
		my_printf("%s\n", str);
		return (0);
	}
	env_st->status = 1;
	return (0);
}