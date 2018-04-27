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

char	*my_second_command(char *av, int len)
{
	int len_2 = 0;
	int ctb = 0;
	char *command_two;

	for (int ct = len; av[ct] != '\0'; ct ++)
		len_2 ++;
	command_two = malloc(sizeof(char) * (len_2 + 1));
	for (int ct = len; av[ct] != '\0'; ct ++, ctb ++) {
		command_two[ctb] = av[ct];
	}
	command_two[len_2] = '\0';
	return (command_two);
}

char	**my_separator_command(char *av, char *sep)
{
	char *command;
	char **command_arr = malloc(sizeof(char *) * 4);
	int len = 0;

	for (int ct = 0; av[ct] != sep[0]; ct ++)
		len ++;
	command = malloc(sizeof(char) * (len + 1));
	for (int ct = 0; av[ct] != sep[0]; ct ++)
		command[ct] = av[ct];
	command[len] = '\0';
	len ++;
	if (my_strlen(sep) == 2)
		len ++;
	command_arr[0] = my_strdup(sep);
	command_arr[1] = my_strdup(command);
	command_arr[2] = my_second_command(av, len);
	command_arr[3] = NULL;
	return (command_arr);
}

tree_t*	my_list_command(char *command, env_st_t* info)
{
	tree_t* temp = info->tree;
	char **arr;
	int b = 0;
	int ct = 0;

	if ((ct = check_sep(word_array(command))) != -1 && ct != -2) {
		//printf("\n\n\nBOUCOULILAH\n\n\n");
		arr = my_separator_command(command, (char *)tab_name[ct]);
		temp = fill_struct_comand((char *)tab_name[ct], 0, 1);
		//printf("\n\n\nBOUCOULILAH    COMMANDE GAUCHE   '%s'   COMMANDE DROITE   '%s'\n\n\n", arr[1], arr[2]);
		temp->left = my_list_command(arr[1], info);
		temp->right = my_list_command(arr[2], info);
		b = 1;
	}
	if (ct == -2) {
		temp = NULL;
		return (temp);
	}
	if (b == 0) {
		temp = fill_struct_comand(command, 0, 1);
	}
	return (temp);
}