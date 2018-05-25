/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/error/error_sep_bis.c
*/

#include "main.h"

int	error_pipe_redic_second_bis(tree_t* temp, char *str)
{
	char **arr;

	arr = word_array(temp->right->commande_parseur);
	if (temp->right->right != NULL) {
		if ((my_strcmp_c(str, ">") == 0 || my_strcmp(str, ">>") == 0)
		&& (my_strcmp_c(arr[0], ">") == 0
		|| my_strcmp(arr[0], ">>") == 0)) {
			my_printf("Ambiguous output redirect.\n");
			return (1);
		}
	}
	if (my_strcmp_c(str, "||") == 0 && my_strcmp_c(arr[0], "&&") == 0
	&& temp->right->left == NULL) {
		my_printf("Invalid null command.\n");
		return (1);
	}
	return (0);
}

int	error_pipe_redic_second(tree_t* temp, char *str)
{
	char **arr;

	if (temp->right != NULL && error_and_or(temp, str) == 1)
		return (1);
	if (temp == NULL || temp->right == NULL || temp->left == NULL)
		return (0);
	arr = word_array(temp->right->commande_parseur);
	if (temp->right->right != NULL) {
		if (my_strcmp_c(str, tab_name[5]) == 0
		&& (my_strcmp(">", arr[0]) == 0
		|| my_strcmp(">>", arr[0]) == 0)
		&& (my_strcmp("<", arr[0]) == 0
		|| my_strcmp("<<", arr[0]) == 0) == 0) {
			my_printf("Ambiguous input redirect.\n");
			return (1);
		}
	}
	if (error_pipe_redic_second_bis(temp, str) == 1)
		return (1);
	return (0);
}
