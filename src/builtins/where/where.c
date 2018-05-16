/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/where/where.c
*/

#include "main.h"

int	where_alias(char *str, env_st_t *env_st)
{
	alias_t *alias = env_st->alias;

	while (alias != NULL) {
		if (my_strcmp(alias->bind, str) == 0) {
			my_printf("%s is aliased to %s\n",
			alias->bind, alias->command_bind);
			return (1);
		}
		alias = alias->next;
	}
	return (0);
}

int	where_builtin(char *str)
{
	if (check_bult_in(str) != -1) {
		my_printf("%s is a shell built-in\n", str);
		return (1);
	}
	return (0);
}

int	where_path(char *str, env_st_t *env_st)
{
	if (access(str, F_OK) != -1) {
		my_printf("%s\n", str);
		return (0);
	}
	env_st->status = 1;
	return (0);
}

/*int	check_path_bsc(char **envp, char *name, char **str_arr,
env_st_t* env_st, tree_t* temp)
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
			strat_exec(str, envp, str_arr, env_st, temp);
			env_st->status = 0;
			return (0);
		}
	}
	my_putstr_err(str_arr[0], ": Command not found.\n");
	env_st->status = 1;
	return (0);
}*/

void	where_path_command(char **envp, char *name,
	env_st_t* env_st, char **str_arr)
{
	int ct = 0;
	char *str;

	if (check_val(envp, "PATH", env_st) == 0) {
		//check_path_bsc(env_st->envp_bsc, name, str_arr, env_st, temp);
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
	env_st->status = 1;
}

int	where_command(char **envp, env_st_t* env_st, char *str)
{
	int b = 0;

	for (int ct = 0; str[ct] != '\0'; ct ++)
		if (str[ct] == '/')
			b = 1;
	if (b == 1) {
		where_path(str, env_st);
	} else {
		where_path_command(envp, str, env_st, NULL);
	}
	return (0);
}

int	where(char **arr, char **envp, env_st_t *env_st)
{
	my_printf("TEST\n");
	return (0);
	if (arr[1] == NULL) {
		env_st->status = 1;
		my_printf("where: Too few arguments.\n");
		return (1);
	}
	for (int ct = 1; arr[ct] != NULL; ct ++) {
		where_builtin(arr[ct]);
		where_alias(arr[ct], env_st);
		where_command(envp, env_st, arr[ct]);
	}
	return (0);
}