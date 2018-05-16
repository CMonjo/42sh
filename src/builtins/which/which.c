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

int	which_builtin(char *str)
{
	if (check_bult_in(str) != -1) {
		my_printf("%s: shell built-in command.\n", str);
		return (1);
	}
	return (0);
}

int	which_path(char *str, env_st_t *env_st)
{
	if (access(str, F_OK) != -1) {
		my_printf("%s\n", str);
		return (0);
	}
	my_putstr_err(str, ": Command not found.\n");
	env_st->status = 1;
	return (0);
}

int	which_check_path_bsc(char **envp, char *name, char **str_arr,
env_st_t* env_st)
{
	int ct = 0;
	char *str;

	while (envp[0][ct] != '=')
		ct ++;
	ct ++;
	for (int ctb = ct; envp[0][ctb] != '\0'; ctb ++) {
		str = my_strcat(pathing(envp, &ctb, 0), name, 0);
		if (envp[0][ctb] == '\0')
			ct --;
		if (access(str, F_OK) != -1) {
			my_printf("%s\n", str);
			return (0);
		}
	}
	env_st->status = 1;
	return (0);
}

void	which_path_command(char **envp, char *name,
	env_st_t* env_st, char **str_arr)
{
	int ct = 0;
	char *str;

	if (check_val(envp, "PATH", env_st) == 0) {
		which_check_path_bsc(env_st->envp_bsc, name, str_arr, env_st);
		return;
	}
	ct = check_same(envp, env_st);
	for (int ctb = ct; envp[env_st->ind][ctb] != '\0'; ctb ++) {
		str = my_strcat(pathing(envp, &ctb, env_st->ind), name, 0);
		if (envp[env_st->ind][ctb] == '\0')
			ctb --;
		if (access(str, F_OK) != -1) {
			my_printf("%s\n", str);
			return;
		}
	}
	my_putstr_err(name, ": Command not found.\n");
	env_st->status = 1;
}

int	which_command(char **envp, env_st_t* env_st, char *str)
{
	int b = 0;

	for (int ct = 0; str[ct] != '\0'; ct ++)
		if (str[ct] == '/')
			b = 1;
	if (b == 1) {
		which_path(str, env_st);
	} else {
		which_path_command(envp, str, env_st, NULL);
	}
	return (0);
}

int	which(char **arr, char **envp, env_st_t *env_st)
{
	if (arr[1] == NULL) {
		env_st->status = 1;
		my_printf("which: Too few arguments.\n");
		return (1);
	}
	for (int ct = 1; arr[ct] != NULL; ct ++) {
		if (which_builtin(arr[ct]) != 1 && which_alias(arr[ct], env_st) != 1)
			which_command(envp, env_st, arr[ct]);
	}
	return (0);
}