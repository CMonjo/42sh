/*
** EPITECH PROJECT, 2017
** prompt.c
** File description:
** the prompte function of the minishell1
*/

#include "main.h"

name_env_t const tab_name_b[] = {
	{"cd", cd},
	{"env", env},
	{"exit", exit_command},
	{"setenv", set_env},
	{"unsetenv", unset_env},
	{"alias", alias},
	{"unalias", unalias},
	{"echo", echo},
	{"repeat", repeat},
	{"which", which},
	{"where", where},
	{"set", set},
	{"unset", unset},
	{"foreach", foreach},
	{"bg", jobs},
	{"fg", jobs},
	{"if", if_build},
	{"builtins", builtins},
	{"yes", yes},
	{"end", end},
	{"endif", endif_build},
	{"else", else_build},
	{"cat", cat},
	{"grep", grep},
};

int	pipe_check_exec(char **command, char **envp, env_st_t *env_st,
tree_t* temp)
{
	int ct = 0;
	int fd_save_1 = dup(0);
	int fd_save = dup(1);

	if (command == NULL)
		return (0);
	while (ct < 22) {
		if (command[0] != NULL
		&& my_strcmp(command[0], tab_name_b[ct].name) == 0) {
			dup2(temp->fd_in, 0);
			dup2(temp->fd_out, 1);
			(tab_name_b[ct].name_str)(command, envp, env_st);
			dup2(fd_save, 1);
			dup2(fd_save_1, 0);
			return (0);
		}
		ct ++;
	}
	exec(envp, env_st, command, temp);
	return (0);
}

int	check_gnl(char *name, char **envp, env_st_t *env_st, tree_t* temp)
{
	char **str;

	if ((str = word_array(name)) == NULL)
		return (0);
	if (check_stars(name) == 1 || check_bracket(name) == 1 ||
	check_inter(name) == 1)
		return (glob_execution(str, envp, env_st, name));
	if (check_alias_local_var(str[0], str[0], env_st) == 1
	|| error_alias_dangerous(str, env_st) == 1)
		return (1);
	if (check_gnl_next(str, envp, env_st) == 1)
		return (0);
	exec(envp, env_st, str, temp);
	return (0);
}

int	check_gnl_next(char **str, char **envp, env_st_t *env_st)
{
	int ct = 0;

	while (ct < 22) {
		if (str[0] != NULL
		&& my_strcmp(str[0], tab_name_b[ct].name) == 0) {
			(tab_name_b[ct].name_str)(str, envp, env_st);
			return (1);
		}
		ct ++;
	}
	return (0);
}