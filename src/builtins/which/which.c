/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/which/which.c
*/

#include "main.h"

int	which_alias(char *str, env_st_t *env_st)
{
	alias_t *alias = env_st->alias;

	while (alias != NULL) {
		if (my_strcmp(alias->bind, str) == 0) {
			my_printf("%s: 	 aliased to %s\n",
			alias->bind, alias->command_bind);
			return (1);
		}
		alias = alias->next;
	}
	return (0);
}

int	which_path(char *str, env_st_t *env_st)
{
	(void)str;
	(void)env_st;
	return (0);
}

int	which(char **arr, char **envp, env_st_t *env_st)
{
	if (arr[1] == NULL) {
		env_st->status = 1;
		my_printf("which: Too few arguments.\n");
		return (1);
	}
	for (int ct = 0; arr[ct] != NULL; ct ++) {
		if (which_alias(arr[ct], env_st) != 1)
			which_path(arr[ct], env_st);
	}
	return (0);
}