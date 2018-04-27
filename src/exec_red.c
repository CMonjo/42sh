/*
** EPITECH PROJECT, 2018
** exec.c
** File description:
** the exec of the minishel1
*/

#include "main.h"

int	exec_red_erno(char *name, char **str, env_st_t* env_st)
{
	int val = 0;

	if ((val = execve(name, str, env_st->envp_cpy)) == -1) {
		if (errno == 13) {
			my_putstr_err(name, ": Permission denied.\n");
		}
		env_st->status = 1;
		return (-1);
	}
	exit(0);
	return (0);
}

int	strat_exec_red(char *name, char **str, env_st_t* env_st, tree_t* temp)
{
	int w = 0;
	int val = 0;

	if ((val = fork()) == -1)
		return (0);
	if (val == 0) {
		dup2(temp->fd_in, temp->fd_out);
		if (exec_red_erno(name, str, env_st) == -1)
			return (0);
	} else
		wait(&w);
	return (status(w, env_st));
}

int	exec_arg_red(env_st_t* env_st, char **str, tree_t* temp)
{
	if (access(str[0], F_OK) != -1) {
		if (strat_exec_red(str[0], str, env_st, temp) == 1)
			env_st->status = 0;
		return (0);
	}
	my_putstr_err(str[0], ": Command not found.\n");
	env_st->status = 1;
	return (0);
}

int	exec_red(env_st_t* env_st, char **str, tree_t* temp)
{
	int ct = 0;
	int b = 0;

	while (str[0][ct] != '\0') {
		if (str[0][ct] == '/')
			b = 1;
		ct ++;
	}
	if (b == 1) {
		exec_arg_red(env_st, str, temp);
	} else {
		check_path_env_red(str[0], env_st, str, temp);
	}
	return (0);
}
