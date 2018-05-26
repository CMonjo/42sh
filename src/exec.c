/*
** EPITECH PROJECT, 2018
** exec.c
** File description:
** the exec of the minishel1
*/

#include "main.h"

int	exec_erno(char *name, char **envp, char **str, env_st_t* env_st)
{
	int val;

	if ((val = execve(name, str, envp)) == -1) {
		if (errno == 13)
			my_putstr_err(name, ": Permission denied.\n");
		if (errno == 8)
			my_putstr_err(name,
			": Exec format error. Wrong Architecture.\n");
		env_st->status = 1;
		return (-1);
	}
	exit(0);
	return (0);
}

int	strat_exec(char *name, char **str,
env_st_t* env_st, tree_t* temp)
{
	int w = 0;
	int val;

	if (scripting(word_array(name), str, env_st->envp_cpy, env_st) == 1)
		return (1);
	if ((val = fork()) == -1)
		return (0);
	if (val == 0) {
		dup2(temp->fd_in, 0);
		dup2(temp->fd_out, 1);
		if (exec_erno(name, env_st->envp_cpy, str, env_st) == -1)
			return (0);
	} else
		wait(&w);
	return (status(w, env_st));
}

int	exec_arg(UNUSED char **envp, env_st_t* env_st, char **str, tree_t* temp)
{
	if (access(str[0], F_OK) != -1) {
		if (strat_exec(str[0], str, env_st, temp) == 1)
			env_st->status = 0;
		return (0);
	}
	my_putstr_err(str[0], ": Command not found.\n");
	env_st->status = 1;
	return (0);
}

int	exec(char **envp, env_st_t* env_st, char **str, tree_t* temp)
{
	int ct = 0;
	int b = 0;

	while (str[0][ct] != '\0') {
		if (str[0][ct] == '/')
			b = 1;
		ct ++;
	}
	if (b == 1) {
		exec_arg(envp, env_st, str, temp);
	} else {
		check_path_env(envp, str[0], env_st, str, temp);
	}
	return (0);
}
