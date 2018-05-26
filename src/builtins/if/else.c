/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/if/else.c
*/

#include "main.h"

int	else_build(char **arr, UNUSED char **envp, env_st_t *env_st)
{
	prompt_else();
	else_loop(arr, envp, env_st);
	return (0);
}