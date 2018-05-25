/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/foreach/foreach.c
*/

#include "main.h"

char	**command_exec(char **arr_command, char *new_command)
{
	int tab_len = 0;
	char **new_arr;

	for (int ct = 0; arr_command != NULL
	&& arr_command[ct] != NULL; ct ++) {
		tab_len ++;
	}
	new_arr = malloc(sizeof(char *) * (tab_len + 2));
	for (int ct = 0; arr_command != NULL
	&& arr_command[ct] != NULL; ct ++) {
		new_arr[ct] = my_strdup(arr_command[ct]);
	}
	new_arr[tab_len] = my_strdup(new_command);
	new_arr[tab_len + 1] = NULL;
	if (arr_command != NULL)
		free_tab(arr_command);
	return (new_arr);
}

void	exec_command_ele(char **arr_command,
int nb_ele, char **foreach, env_st_t *env_st)
{
	char *var = my_strdup(foreach[1]);
	char *command;
	int ctb = 3;

	if (arr_command == NULL)
		return;
	for (int ct = 0; ct != nb_ele; ct ++, ctb ++) {
		command = my_strcat("set ", var, 0);
		command = my_strcat(command, "=", 0);
		command = my_strcat(command, foreach[ctb], 0);
		set(word_array(command), env_st->envp_cpy, env_st);
		for (int ctb = 0; arr_command[ctb] != NULL; ctb ++)
			main_b_tree(arr_command[ctb], env_st, 0, 1);
		free(command);
	}
	free(var);
	free_tab(foreach);
}

char	**foreach_loop(char **arr, UNUSED char **envp, env_st_t *env_st)
{
	char *str = malloc(sizeof(char) * 1);
	int ele = count_ele(arr);
	char **arr_command = NULL;

	str[0] = '\0';
	while (end_foreach_while(word_array(str), env_st, 1) != 0) {
		str = my_getline();
		if (isatty(0) == 1 && str == NULL)
			exit(0);
		if (ele > 0 && my_strlen(str) > 0
		&& end_foreach_while(word_array(str), env_st, 0) != 0) {
			arr_command = command_exec(arr_command, str);
		}
		else if (my_strlen(str) <= 0 && isatty(0) != 1) {
			exec_command_ele(arr_command, 1, arr, env_st);
			exit(0);
		}
		prompt_foreach();
	}
	return (arr_command);
}

int	foreach(char **arr, UNUSED char **envp, env_st_t *env_st)
{
	int ele = count_ele(arr);
	char **arr_command = NULL;

	if (error_foreach(arr, env_st) == 1)
		return (1);
	prompt_foreach();
	arr_command = foreach_loop(arr, envp, env_st);
	if (isatty(0) == 1 && ele > 0)
		my_printf("\n");
	exec_command_ele(arr_command, ele, arr, env_st);
	return (0);
}