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
	"unset", "foreach", "yes", "fg", "bg", "if", "builtins"};

	for (int ct = 0; ct != 19; ct ++) {
		if (my_strcmp(str, bul_in[ct]) == 0)
			return (ct);
	}
	return (-1);
}

int	check_gnl(char *name, char **envp, env_st_t *env_st, tree_t* temp)
{
	char **str;

	if ((str = word_array(name)) == NULL)
		return (0);
	if (check_stars(name) == 1 || check_bracket(name) == 1 ||
	check_inter(name) == 1)
		return (glob_execution(str, envp, env_st, name));
	if (check_alias_local_var(str[0], str[0], env_st) == 1
	|| error_alias_dangerous(str, env_st) == 1)
		return (1);
	if (check_gnl_next(str, envp, env_st) == 1)
		return (0);
	exec(envp, env_st, str, temp);
	return (0);
}