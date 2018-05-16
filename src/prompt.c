/*
** EPITECH PROJECT, 20111
** prompt.c
** File description:
** the prompte function of the minishell1
*/

#include "main.h"

name_env_t const tab_name_b[] = {{"cd", cd}, {"env", env},
			{"exit", exit_env}, {"setenv", set_env},
			{"unsetenv", unset_env}, {"alias", alias},
			{"echo", echo}, {"repeat", repeat}, {"which", which},
			{"where", where}, {"foreach", foreach}, {"end", end},
			{"cat", cat}, {"grep", grep}};

int	check_bult_in(char *str)
{
	char *bul_in[] = {"cd", "env", "exit", "setenv", "unsetenv",
	"alias", "echo", "repeat", "which", "where"};

	for (int ct = 0; ct != 11; ct ++) {
		if (my_strcmp(str, bul_in[ct]) == 0)
			return (ct);
	}
	return (-1);
}

int	pipe_check_exec(char **command, char **envp, env_st_t *env_st, tree_t* temp)
{
	int ct = 0;

	while (ct < 11) {
		if (command[0] != NULL
		&& my_strcmp(command[0], tab_name_b[ct].name) == 0) {
			dup2(temp->fd_in, 0);
			dup2(temp->fd_out, 1);
			(tab_name_b[ct].name_str)(command, envp, env_st);
			return (0);
		}
		ct ++;
	}
	exec(envp, env_st, command, temp);
	return (0);
}

void	pass_quotes(char *str, int *ct, char quote)
{
	(*ct) ++;
	while (str[*ct] != quote)
		(*ct) ++;
	(*ct) ++;
}

int	check_stars(char *str)
{
	for (int ct = 0; str[ct] != '\0'; ct ++) {
		if (str[ct] == '\'' || str[ct] == '\"')
			pass_quotes(str, &ct, str[ct]);
		if (str[ct] == '*')
			return (1);
	}
	return (0);
}
int	check_same_alias(char *command, env_st_t *env_st)
{
	alias_t* alias = env_st->alias;

	while (alias != NULL) {
		if (my_strcmp(alias->bind, command) == 0
		&& my_strcmp(alias->command_bind, command) == 0)
			return (1);
		alias = alias->next;
	}
	return (0);
}

int	check_alias_local_var(char *command, char *str, env_st_t *env_st)
{
	alias_t* alias = env_st->alias;

	/*if (str[0] == '$') {
		//local variables
	}*/
	if (check_same_alias(command, env_st) == 1)
		return (0);
	if (alias != NULL && error_alias_loop(command, str, env_st) == 1)
		return (1);
	while (alias != NULL) {
		if (my_strcmp(alias->bind, command) == 0) {
			check_gnl(alias->command_bind,
			env_st->envp_cpy, env_st,
			my_list_command(alias->command_bind, env_st, 0, 1));
			return (1);
		}
		alias = alias->next;
	}
	return (0);
}

int	check_gnl(char *name, char **envp, env_st_t *env_st, tree_t* temp)
{
	int ct = 0;
	char **str;

	if ((str = word_array(name)) == NULL)
		return (0);
	if (check_stars(name) == 1) {
		star_handle(str, envp, env_st);
		return (0);
	}
	if (check_alias_local_var(str[0], str[0], env_st) == 1
	|| error_alias_dangerous(str, env_st) == 1)
		return (1);
	while (ct < 11) {
		if (str[0] != NULL
		&& my_strcmp(str[0], tab_name_b[ct].name) == 0) {
			(tab_name_b[ct].name_str)(str, envp, env_st);
			return (0);
		}
		ct ++;
	}
	exec(envp, env_st, str, temp);
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
