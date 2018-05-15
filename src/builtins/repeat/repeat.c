/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for the cd func
*/

#include "main.h"
#include <limits.h>

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

int	error_repeat(char **arr, env_st_t *env_st, int tab_len)
{
	if (tab_len < 3) {
		env_st->status = 1;
		my_printf("repeat: Too few arguments.\n");
		return (1);
	}
	for (int ct = 0; arr[1][ct] != '\0'; ct ++)
		if (arr[1][ct] < '0' || arr[1][ct] > '9') {
			env_st->status = 1;
			my_printf("repeat: Badly formed number.\n");
			return (1);
		}
	return (0);
}

int	repeat(char **arr, char **envp, env_st_t *env_st)
{
	int tab_len = 0;
	int nbr = 0;
	char **command;
	tree_t* tree = env_st->tree;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		tab_len ++;
	if (error_repeat(arr, env_st, tab_len) == 1)
		return (1);
	if ((nbr = my_getnbr(arr[1])) > INT_MAX)
	nbr = my_getnbr(arr[1]);
	command = repeat_command(arr, tab_len);
	tree = my_list_command(command[0], env_st);
	for (int ct = 0; ct != nbr; ct ++) {
		exec(envp, env_st, command, tree);
	}
	env_st->status = 0;
	return (0);
}
