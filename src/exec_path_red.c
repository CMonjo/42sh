/*
** EPITECH PROJECT, 2018
** path.c
** File description:
** pathing for the minishell1
*/

#include "main.h"

void	check_path_env_red(char *name, env_st_t* env_st, char **str_arr,
tree_t* temp)
{
	int ct = 0;
	char *str;

	if (check_val(env_st->envp_cpy, "PATH", env_st) == 0) {
		check_path_bsc(name, str_arr, env_st, temp);
		return;
	}
	ct = check_same(env_st->envp_cpy, env_st);
	while (env_st->envp_cpy[env_st->ind][ct] != '\0') {
		str = my_strcat(pathing(env_st->envp_cpy, &ct, env_st->ind),
		name, 0);
		ct -= env_st->envp_cpy[env_st->ind][ct] == '\0' ? 1 : 0;
		if (access(str, F_OK) != -1) {
			strat_exec_red(str, str_arr, env_st, temp);
			return;
		}
		ct ++;
	}
	my_printf("%s: Command not found.\n", str_arr[0]);
	env_st->status = 1;
}
