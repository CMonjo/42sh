/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/endif/endif.c
*/

#include "main.h"

int	endif_build(char **arr, UNUSED char **envp, env_st_t *env_st)
{
	if (arr[1] != NULL) {
		env_st->status = 0;
		return (0);
	} else {
		my_putstr_err(arr[0], ": Too many arguments.\n");
		env_st->status = 1;
	}
	return (0);
}