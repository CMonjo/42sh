/*
** EPITECH PROJECT, 2017
** prompt.c
** File description:
** the prompte function of the minishell1
*/

#include "main.h"

void	pass_quotes(char *str, int *ct, char quote)
{
	(*ct) ++;
	while (str[*ct] != quote && str[*ct] != '\0')
		(*ct) ++;
}

int	check_bult_in(char *str)
{
	char *bul_in[] = {"cd", "env", "exit", "setenv", "unsetenv",
	"alias", "unalias", "echo", "repeat", "which", "where", "set",
	"unset", "foreach", "yes", "fg", "bg", "if", "builtins",
	"end", "endif", "else"};

	for (int ct = 0; ct != 22; ct ++) {
		if (my_strcmp(str, bul_in[ct]) == 0)
			return (ct);
	}
	return (-1);
}