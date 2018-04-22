/*
** EPITECH PROJECT, 2018
** env_other.c
** File description:
** other function and env of minishell
*/

#include "my.h"

int	check_env(char *envp, char *name)
{
	int ctb = 0;

	while (envp[ctb] != '=') {
		if ((envp[ctb] - name[ctb]) != 0)
			return (0);
		if ((envp[ctb] - name[ctb]) == 0 && envp[ctb + 1] == '=')
			return (1);
		ctb ++;
	}
	return (0);
}

int	error_set_env(char **str, env_st_t* env_st)
{
	int ct = 0;

	while (str[ct] != NULL)
		ct ++;
	if (ct == 1) {
		env(str, env_st->envp_cpy, env_st);
		return (1);
	}
	if (str[1][0] > 47 && str[1][0] < 58) {
		my_putstr_err(NULL,
		"setenv: Variable name must begin with a letter.\n");
		env_st->status = 1;
		return (1);
	}
	if (ct > 3) {
		my_putstr_err(str[0], ": Too many arguments.\n");
		env_st->status = 1;
		return (1);
	}
	return (0);
}

int	strat_set_env(char **str, char **envp, env_st_t* env_st, int b)
{
	if (b == 1) {
		unset_env_name(str, envp, env_st);
		return (0);
	}
	if (str[2] == NULL) {
		set_name(str, envp, env_st);
		return (0);
	}
	if (str[3] == NULL) {
		env_st->len_h ++;
		set_name_value(str, envp, env_st);
		return (0);
	}
	return (0);
}

int	set_env(char **str, char **envp, env_st_t* env_st)
{
	char **new_env;
	int b = 0;

	if (error_set_env(str, env_st) == 1)
		return (0);
	new_env = copy_env(envp, env_st, 0);
	if (check_name(str, env_st) == -1)
		return (0);
	env_st->status = 0;
	b = check_val(new_env, str[1], env_st);
	strat_set_env(str, new_env, env_st, b);
	return (0);
}

int	env(char **str, char **envp, env_st_t *env_st)
{
	int ct = 0;
	(void)str;

	while (envp[ct] != NULL) {
		my_printf("%s\n", env_st->envp_cpy[ct]);
		ct ++;
	}
	return (0);
}
