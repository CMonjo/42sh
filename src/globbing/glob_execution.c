/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/globbing/glob_execution.c
*/

#include "main.h"

int	check_stars(char *str)
{
	for (int ct = 0; str[ct] != '\0'; ct ++) {
		if (str[ct] == '\'' || str[ct] == '\"')
			pass_quotes(str, &ct, str[ct]);
		if (str[ct] == '*')
			return (1);
	}
	return (0);
}

int	check_bracket_close(char *str, int ct)
{
	for (ct = ct + 1; str[ct] != '\0'; ct++) {
		if (str[ct] == ']')
			return (1);
		if (str[ct] == '[')
			return (check_bracket_close(str, ct));
	}
	return (0);
}

int	check_bracket(char *str)
{
	for (int ct = 0; str[ct] != '\0'; ct ++) {
		if (str[ct] == '\'' || str[ct] == '\"')
			pass_quotes(str, &ct, str[ct]);
		if (str[ct] == '[' && check_bracket_close(str, ct) == 1)
			return (1);
	}
	return (0);
}

int	check_inter(char *str)
{
	for (int ct = 0; str[ct] != '\0'; ct ++) {
		if (str[ct] == '\'' || str[ct] == '\"')
			pass_quotes(str, &ct, str[ct]);
		if (str[ct] == '?')
			return (1);
	}
	return (0);
}

int	glob_execution(char **str, char **envp, env_st_t *env_st, char *name)
{
	char **array;
	tree_t *tree = env_st->tree;

	array = star_handle(str, name);
	array = bracket_handle(array, name);
	array = inter_handle(array, name);
	tree = my_list_command(array[0], env_st, 0, 1);
	if (is_there_changement(str, array) == 1)
		pipe_check_exec(array, envp, env_st, tree);
	else {
		env_st->status = 1;
		dprintf(2, "%s: No match.\n", array[0]);
	}
	free (array);
	return (0);
}