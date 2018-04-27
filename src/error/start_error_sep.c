/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** start_error_sep.c
*/

#include "main.h"

int	start_error_sep(tree_t* temp, char **arr, int ct, int b)
{
	if (my_strcmp_c(arr[0], tab_name[ct]) == 0) {
		if (b == 0 && error_pipe_redic(temp, arr[0]) == 1)
			return (1);
		if (b == 1 && error_pipe_redic_second(temp, arr[0]) == 1)
			return (1);
		return (-1);
	}
	return (0);
}

int	start_error_tree(tree_t* temp, int b)
{
	char **arr;
	int val = 0;

	arr = word_array(temp->commande_parseur);
	for (int ct = 0; ct != 7; ct ++) {
		error_redi_right_input(temp, arr[0]);
		if ((val = start_error_sep(temp, arr, ct, b)) == 1)
			return (1);
		if (val == -1)
			break;
	}
	if (temp->left != NULL)
		start_error_tree(temp->left, b);
	if (temp->right != NULL)
		start_error_tree(temp->right, b);
	return (0);
}
