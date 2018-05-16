/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/end/end.c
*/

#include "main.h"

int	end_foreach_while(char **arr, env_st_t *env_st, int b)
{
	if (arr == NULL || my_strcmp(arr[0], "end") != 0)
		return (1);
	if (arr[1] != NULL && b == 0) {
		env_st->status = 1;
		my_printf("foreach: Too many arguments.s.\n");
		return (1);
	}
	return (0);
}

int	end(char **arr, char **envp, env_st_t *env_st)
{
	if (arr [1] != NULL) {
		env_st->status = 1;
		my_printf("foreach: Too many arguments.s.\n");
		return (1);
	}
	my_printf("end: Not in while/foreach.\n");
	env_st->status = 1;
	return (0);
}