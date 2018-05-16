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

	for (int ct = 0; arr_command != NULL && arr_command[ct] != NULL; ct ++) {
		tab_len ++;
	}
	new_arr = malloc(sizeof(char *) * (tab_len + 2));
	for (int ct = 0; arr_command != NULL && arr_command[ct] != NULL; ct ++) {
		new_arr[ct] = my_strdup(arr_command[ct]);
	}
	new_arr[tab_len] = my_strdup(new_command);
	new_arr[tab_len + 1] = NULL;
	if (arr_command != NULL)
		free_tab(arr_command);
	return (new_arr);
}

void	write_file_foreach(char *file_tmp, char **envp, env_st_t *env_st)
{
	tree_t* temp = env_st->tree;

	temp = fill_struct_comand(my_strcat("cat ", file_tmp, 0), 0, 1);
	exec(envp, env_st,
	word_array(my_strcat("cat ", file_tmp, 0)), temp);
	temp = fill_struct_comand(my_strcat("rm ", file_tmp, 0), 0, 1);
	exec(envp, env_st,
	word_array(my_strcat("rm ", file_tmp, 0)), temp);
}

void	exec_command_ele(char **arr_command, int nb_ele, char **envp, env_st_t *env_st)
{
	int fd = 0;
	char *file_tmp = NULL;

	for (int ct = 1; ct != nb_ele;ct ++) {
		fd = open((file_tmp = create_file()), O_RDWR | O_CREAT, 0666);
		for (int ctb = 0; arr_command[ctb] != NULL; ctb ++)
			main_b_tree(arr_command[ctb], env_st, 0, fd);
		write_file_foreach(file_tmp, envp, env_st);
	}
}

char	**foreach_loop(int fd, char **arr, UNUSED char **envp, env_st_t *env_st)
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
			main_b_tree(str, env_st, 0, fd);
			arr_command = command_exec(arr_command, str);
		}
		else if (isatty(0) != 1)
			break;
		prompt_foreach();
	}
	return (arr_command);
}

int	foreach(char **arr, UNUSED char **envp, env_st_t *env_st)
{
	int fd = 0;
	char *file_tmp = NULL;
	int ele = count_ele(arr);
	char **arr_command = NULL;

	fd = open((file_tmp = create_file()), O_RDWR | O_CREAT, 0666);
	if (error_foreach(arr, env_st) == 1)
		return (1);
	prompt_foreach();
	arr_command = foreach_loop(fd, arr, envp, env_st);
	close(fd);
	write_file_foreach(file_tmp, envp, env_st);
	if (arr_command != NULL)
		exec_command_ele(arr_command, ele, envp, env_st);
	return (0);
}