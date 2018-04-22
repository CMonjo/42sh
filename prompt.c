/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** the prompte function of the minishell1
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

name_env_t const tab_name_b[] = {{"cd", cd}, {"env", env},
			{"exit", exit_env}, {"setenv", set_env},
			{"unsetenv", unset_env}};

int	check_bult_in(char *str)
{
	char *bul_in[] = {"cd", "env", "exit", "setenv", "unsetenv"};

	for (int ct = 0; ct != 5; ct ++) {
		if (my_strcmp(str, bul_in[ct]) == 0)
			return (ct);
	}
	return (-1);
}

int	pipe_check_exec(char **command, char **envp, env_st_t *env_st)
{
	int ct = 0;

	while (ct < 5) {
		if (command[0] != NULL
		&& my_strcmp(command[0], tab_name_b[ct].name) == 0) {
			(tab_name_b[ct].name_str)(command, envp, env_st);
			return (0);
		}
		ct ++;
	}
	exec(envp, env_st, command);
	return (0);
}

int	check_gnl(char *name, char **envp, env_st_t *env_st)
{
	int ct = 0;
	char **str;

	if ((str = word_array(name)) == NULL)
		return (0);
	while (ct < 5) {
		if (str[0] != NULL
		&& my_strcmp(str[0], tab_name_b[ct].name) == 0) {
			(tab_name_b[ct].name_str)(str, envp, env_st);
			return (0);
		}
		ct ++;
	}
	exec(envp, env_st, str);
	return (0);
}

char	*my_getline(void)
{
	size_t size = 0;
	char *str = NULL;
	int readed = 0;

	readed = getline(&str, &size, stdin);
	if (readed <= 0) {
		return (NULL);
	}
	str[readed - 1] = '\0';
	return (str);
}