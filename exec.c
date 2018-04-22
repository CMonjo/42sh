/*
** EPITECH PROJECT, 2018
** exec.c
** File description:
** the exec of the minishel1
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int	status(int w, env_st_t* env_st)
{
	if ((w % 255) == 1) {
		env_st->status = 1;
		return (0);
	}
	if (SIGFPE == WTERMSIG(w)) {
		my_printf("Floating exception");
		if (WCOREDUMP(w))
			my_printf(" (core dumped)");
		my_printf("\n");
		env_st->status = 136;
		return (136);
	}
	if (WIFSIGNALED(w)) {
		my_printf("Segmentation fault");
		if (WCOREDUMP(w))
			my_printf(" (core dumped)");
		my_printf("\n");
		env_st->status = 139;
		return (139);
	}
	return (1);
}

int	exec_erno(char *name, char **envp, char **str, env_st_t* env_st)
{
	int val;

	if ((val = execve(name, str, envp)) == -1) {
		if (errno == 13)
			my_putstr_err(name, ": Permission denied.\n");
		env_st->status = 1;
		return (-1);
	}
	exit(0);
	return (0);
}

int	strat_exec(char *name, char **envp, char **str, env_st_t* env_st)
{
	int w;
	int val;

	if ((val = fork()) == -1)
		return (0);
	if (val == 0) {
		if (exec_erno(name, envp, str, env_st) == -1)
			return (0);
	} else
		wait(&w);
	return (status(w, env_st));
}

int	exec_arg(char **envp, env_st_t* env_st, char **str)
{
	if (access(str[0], F_OK) != -1) {
		if (strat_exec(str[0], envp, str, env_st) == 1)
			env_st->status = 0;
		return (0);
	}
	my_putstr_err(str[0], ": Command not found.\n");
	env_st->status = 1;
	return (0);
}

int	exec(char **envp, env_st_t* env_st, char **str)
{
	int ct = 0;
	int b = 0;

	while (str[0][ct] != '\0') {
		if (str[0][ct] == '/')
			b = 1;
		ct ++;
	}
	if (b == 1) {
		exec_arg(envp, env_st, str);
	} else {
		check_path_env(envp, str[0], env_st, str);
	}
	return (0);
}