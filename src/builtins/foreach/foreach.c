/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/foreach/foreach.c
*/

#include "main.h"

int	error (char **arr, env_st_t *env_st)
{
	int tab_len = 0;
	int b = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		tab_len ++;
	if (tab_len < 4) {
		env_st->status = 1;
		my_putstr_err(NULL, "foreach: Too few arguments.\n");
		return (1);
	}
	if (arr[2][0] != '(' || arr[tab_len - 1][0] != ')') {
		env_st->status = 1;
		my_putstr_err(NULL, "foreach: Words not parenthesized.\n");
		return (1);
	}
	if ((arr[1][0] < 65 ||
		(arr[1][0] > 90 && arr[1][0] < 97)
		|| arr[1][0] > 122) && arr[1][0] != '_') {
		my_putstr_err(NULL,
		"foreach: Variable name must begin with a letter.\n");
		env_st->status = 1;
		return (1);
	}
	for (int ct = 0; arr[1][ct] != '\0'; ct ++) {
		if ((arr[1][ct] > 47 && arr[1][ct] < 58) || arr[1][ct] == '_')
			b = 1;
		if (b == 0 && (arr[1][ct] < 65 ||
		(arr[1][ct] > 90 && arr[1][ct] < 97)
		|| arr[1][ct] > 122)) {
			my_putstr_err(NULL, "foreach: Variable name must cont");
			my_putstr_err(NULL, "ain alphanumeric characters.\n");
			env_st->status = 1;
			return (1);
		}
		b = 0;
	}
	for (int ct = 0; arr[1][ct] != '\0'; ct ++) {
		if ((arr[1][ct] > 47 && arr[1][ct] < 58) || arr[1][ct] == '_')
			b = 1;
		if (b == 0 && (arr[1][ct] < 65 ||
		(arr[1][ct] > 90 && arr[1][ct] < 97)
		|| arr[1][ct] > 122)) {
			my_putstr_err(NULL, "setenv: Variable name must cont");
			my_putstr_err(NULL, "ain alphanumeric characters.\n");
			env_st->status = 1;
			return (1);
		}
		b = 0;
	}
	return (0);
}

int	count_ele(char **arr)
{
	int ele = 0;
	int b = 0;
	int nb_parent = 0;
	int nb_back_parent = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		if (arr[ct][0] == '(')
			nb_parent ++;
	for (int ct = 3; nb_back_parent != nb_parent; ct ++) {
		if (arr[ct][0] == ')')
			nb_back_parent ++;
		ele ++;
	}
	return (ele - 1);
}

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
	//free_tab(arr_command);
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

void	prompt_foreach(void)
{
	if (isatty(0) == 1)
		my_printf("foreach? ");
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

int	foreach(char **arr, char **envp, env_st_t *env_st)
{
	char *str = malloc(sizeof(char) * 1);
	int fd = 0;
	char *file_tmp = NULL;
	int ele = count_ele(arr);
	char **arr_command = NULL;

	fd = open((file_tmp = create_file()), O_RDWR | O_CREAT, 0666);
	str[0] = '\0';
	if (error(arr, env_st) == 1)
		return (1);
	prompt_foreach();
	while (end_foreach_while(word_array(str), env_st, 1) != 0) {
		str = my_getline();
		if (isatty(0) == 1 && str == NULL) {
			exit(0);
		}
		if (ele > 0 && my_strlen(str) > 0 && end_foreach_while(word_array(str), env_st, 0) != 0) {
			main_b_tree(str, env_st, 0, fd);
			arr_command = command_exec(arr_command, str);
		}
		else if (isatty(0) != 1)
			break;
		prompt_foreach();
	}
	close(fd);
	write_file_foreach(file_tmp, envp, env_st);
	if (arr_command != NULL)
		exec_command_ele(arr_command, ele, envp, env_st);
	return (0);
}