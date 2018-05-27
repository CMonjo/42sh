/*
** EPITECH PROJECT, 2017
** prompt.c
** File description:
** the prompte function of the minishell1
*/

#include "main.h"

int	builtins(UNUSED char **arr, UNUSED char **envp,
UNUSED env_st_t *env_st)
{
	char *bul_in[] = {"alias", "ascii", "bg", "builtins", "cat", "cd",
	"color", "echo", "else", "end", "endif", "env", "exit", "fg",
	"foreach", "grep", "history", "if", "repeat", "set",
	"setenv", "unalias", "unset", "unsetenv", "where", "which", "yes"};
	int i = 0;
	int ct = 0;

	while (i != 27) {
		my_printf("%s", bul_in[i]);
		ct = ct + 1;
		i = i + 1;
		if (ct == 9) {
			my_putchar('\n');
			ct = 0;
		}
		if (i != 27 && ct != 0)
			my_printf("\t");
	}
	my_putchar('\n');
	return (0);
}
