/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for the cd func
*/

#include "my.h"

char	**repeat_command(char **arr, int nb_len)
{
	char **command = malloc(sizeof(char *) * (nb_len - 1));
	int ctb = 0;

	for (int ct = 2; arr[ct] != NULL; ct ++) {
		command[ctb] = my_strdup(arr[ct]);
		ctb ++;
	}
	command[nb_len - 2] = NULL;
	return (command);
}

int	repeat(char **arr, char **envp, env_st_t *env_st)
{
	int tab_len = 0;
	int nbr = 0;
	char **command;
	tree_t* tree = env_st->tree;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		tab_len ++;
	if (tab_len < 3) {
		my_printf("repeat: Too few arguments.\n");
		return (1);
	}
	nbr = my_getnbr(arr[1]);
	command = repeat_command(arr, tab_len);
	tree = my_list_command(command[0], env_st);
	for (int ct = 0; ct != nbr; ct ++) {
		exec(envp, env_st, command, tree);
	}
}