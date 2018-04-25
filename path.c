/*
** EPITECH PROJECT, 2018
** path.c
** File description:
** pathing for the minishell1
*/

#include "my.h"

char*	pathing(char **envp, int *ct, int ctb)
{
	char *str;
	int ctp = *ct;
	int len = 0;

	while (envp[ctb][ctp] != ':' && envp[ctb][ctp] != '\0') {
		len ++;
		ctp ++;
	}
	ctp = 0;
	str = malloc(sizeof(char) * (len + 2));
	while (envp[ctb][*ct] != ':' && envp[ctb][*ct] != '\0') {
		str[ctp] = envp[ctb][*ct];
		(*ct) ++;
		ctp ++;
	}
	str[ctp] = '/';
	str[ctp + 1] = '\0';
	return (str);
}

int	check_path_bsc(char **envp, char *name, char **str_arr,
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
}

int	check_same(char **envp, env_st_t* env_st)
{
	int ct = 0;

	while (envp[env_st->ind][ct] != '=')
		ct ++;
	return (ct + 1);
}

void	check_path_env(char **envp, char *name,
	env_st_t* env_st, char **str_arr, tree_t* temp)
{
	int ct = 0;
	char *str;

	if (check_val(envp, "PATH", env_st) == 0) {
		check_path_bsc(env_st->envp_bsc, name, str_arr, env_st, temp);
		return;
	}
	ct = check_same(envp, env_st);
	for (int ctb = ct; envp[env_st->ind][ctb] != '\0'; ctb ++) {
		str = my_strcat(pathing(envp, &ctb, env_st->ind), name, 0);
		if (envp[env_st->ind][ctb] == '\0')
			ctb --;
		if (access(str, F_OK) != -1) {
			if (strat_exec(str, envp, str_arr, env_st, temp) == 1)
				env_st->status = 0;
			return;
		}
	}
	my_putstr_err(str_arr[0], ": Command not found.\n");
	env_st->status = 1;
}
