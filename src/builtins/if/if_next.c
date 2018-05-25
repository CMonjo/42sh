/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/if/if.c
*/

#include "main.h"

int	error_if_syntax_next_next(char **arr, env_st_t *env_st)
{
	if (arr[2][0] >= '0' && arr[2][0] <= '9') {
		if (error_if_syntax_next(arr, env_st) == 1)
			return (1);
	} else {
		env_st->status = 1;
		my_printf("if: Expression Syntax.\n");
		return (1);
	}
	return (1);
}

int	error_if_syntax_next(char **arr, env_st_t *env_st)
{
	for (int ct = 0; arr[2][ct] != '\0'; ct ++)
		if (arr[2][ct] < '0' || arr[2][ct] > '9') {
			env_st->status = 1;
			my_printf("if: Badly formed number.\n");
			return (1);
		}
	main_b_tree(if_command(arr), env_st, 0, 1);
	return (0);
}

int	error_if_syntax_next_next_next(char **arr, env_st_t *env_st, int b)
{
	if (b == 0)
		return (1);
	if (b == 1) {
		if (error_if_syntax_next_next(arr, env_st) == 1)
			return (1);
	}
	return (0);
}

int	error_if_syntax(char **arr, env_st_t *env_st)
{
	int b = 0;

	for (int ct = 2; arr[ct][0] != ')'; ct ++)
		b ++;
	if (error_if_syntax_next_next_next(arr, env_st, b) == 1)
		return (1);
	if (b == 2) {
		env_st->status = 1;
		my_printf("if: Expression Syntax.\n");
		return (1);
	}
	return (0);
}