/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** fill_struct_pars.c
*/

#include "main.h"

tree_t	*fill_struct_comand(char *command, int fd_in, int fd_out)
{
	tree_t* new_node = malloc(sizeof(tree_t));

	new_node->fd_in = fd_in;
	new_node->fd_out = fd_out;
	new_node->commande_parseur = my_strdup(command);
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

char	**my_separator_command(char *av, char *sep)
{
	char *command;
	char **command_arr = malloc(sizeof(char *) * 4);
	int len = 0;

	for (int ct = 0; av[ct] != sep[0]; ct ++) {
		if (av[ct] == '(') {
			skip_parent_command(av, &ct);
			len = ct - 2;
		} else
			len ++;
	}
	command = malloc(sizeof(char) * (len + 1));
	remove_parent_command(command, av, sep[0], len);
	len ++;
	if (my_strlen(sep) == 2)
		len ++;
	command_arr[0] = my_strdup(sep);
	command_arr[1] = my_strdup(command);
	command_arr[2] = my_second_command(av, len, sep[0]);
	command_arr[3] = NULL;
	return (command_arr);
}

tree_t* fill_tree_command(char *command, env_st_t* info, int fd_in, int fd_out)
{
	tree_t* temp = info->tree;
	char **arr;
	int ct = check_sep(word_array(command));

	arr = my_separator_command(command, (char *)tab_name[ct]);
	temp = fill_struct_comand((char *)tab_name[ct], fd_in, fd_out);
	temp->left = my_list_command(arr[1], info, fd_in, fd_out);
	temp->right = my_list_command(arr[2], info, fd_in, fd_out);
	return (temp);
}

tree_t* fill_tree_parent_command(char *command,
env_st_t* info, int fd_in, int fd_out)
{
	tree_t* temp = info->tree;
	char *command_tmp;
	int ct = check_sep(word_array(command));

	command_tmp = malloc(sizeof(char) * (my_strlen(command) - 1));
	remove_parent_command(command_tmp,
	command, '\0', my_strlen(command) - 2);
	if ((ct = check_sep(word_array(command_tmp))) != -1 && ct != -2)
		return (fill_tree_command(command_tmp, info, fd_in, fd_out));
	temp = fill_struct_comand(command_tmp, fd_in, fd_out);
	return (temp);
}

tree_t*	my_list_command(char *command, env_st_t* info, int fd_in, int fd_out)
{
	tree_t* temp = info->tree;
	int ct = 0;

	if ((ct = check_sep(word_array(command))) != -1
	&& ct != -2 && ct != -3)
		return (fill_tree_command(command, info, fd_in, fd_out));
	if (ct == -3)
		return (fill_struct_comand(command, fd_in, fd_out));
	if (ct == -2)
		return (NULL);
	for (int ct = 0; command[ct] != '\0'; ct ++) {
		if (command[ct] == '\'' || command[ct] == '\"')
			pass_quotes(command, &ct, command[ct]);
		if (command[ct] == '(')
			return (fill_tree_parent_command(command,
			info, fd_in, fd_out));
	}
	temp = fill_struct_comand(command, fd_in, fd_out);
	return (temp);
}
