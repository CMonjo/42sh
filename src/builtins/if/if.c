/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/if/if.c
*/

#include "main.h"

if_t const tab_if_sep[] = {
	{"==", if_equal},
	{">=", if_equal_sup},
	{"<=", if_equal_inf},
	{"<", if_inf},
	{">", if_sup},
	{"!=", if_no_equal},
};

char	*if_command(char **arr)
{
	char *command;
	int ct = 0;

	while (arr[ct][0] != ')')
		ct ++;
	command = my_strdup(arr[ct + 1]);
	for (int ctb = ct + 2; arr[ctb] != NULL; ctb ++) {
		command = my_strcat(command, " ",0);
		command = my_strcat(command, arr[ctb], 0);
	}
	printf("COMMANDE  :%s\n", command);
	return (command);
}

int	error_if(char **arr, env_st_t *env_st)
{
	int ct = 0;

	if (arr[1] == NULL) {
		env_st->status = 1;
		my_printf("if: Too few arguments.\n");
		return (1);
	}
	while (arr[ct][0] != ')')
		ct ++;
	if (arr[ct + 1] == NULL) {
		env_st->status = 1;
		my_printf("if: Empty if.\n");
		return (1);
	}
	return (0);
}

int	if_build_next_next(int ct, char **arr, env_st_t *env_st, int ctb)
{
	if ((tab_if_sep[ct].name_str)(arr[2], arr[ctb]) == 0) {
		if (my_strcmp(arr[6], "then") == 0)
			return (0);
		main_b_tree(if_command(arr), env_st, 0, 1);
	} else if (my_strcmp(arr[6], "then") == 0) {
		prompt_if();
		then_loop(arr, env_st->envp_cpy, env_st);
	}
	return (0);
}

int	if_build_next(char *sep, char **arr, env_st_t *env_st, int ctb)
{
	int b = 0;

	for (int ct = 0; ct != 6; ct ++)
		if (my_strcmp(sep, tab_if_sep[ct].name) == 0) {
			if_build_next_next(ct, arr, env_st, ctb);
			b ++;
		}
	return (b);
}

int	if_build(char **arr, UNUSED char **envp, env_st_t *env_st)
{
	int b = 0;
	char *sep = malloc(sizeof(char) * 1);
	int ctb = 3;

	if (error_if(arr, env_st) == 1 || error_if_syntax(arr, env_st) == 1)
		return (1);
	if (arr[1][0] != '(')
		return (0);
	sep[0] = '\0';
	while (arr[ctb + 1][0] != ')') {
		sep = my_strcat(sep, arr[ctb], 0);
		ctb ++;
	}
	b = b + if_build_next(sep, arr, env_st, ctb);
	if (b == 0) {
		env_st->status = 1;
		my_printf("if: Expression Syntax.\n");
		return (1);
	}
	return (0);
}