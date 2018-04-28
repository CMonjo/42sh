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
		//printf("WALLA LA STR  :   %s\n", arr[0]);
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
		if (error_redi_right_input(temp, arr[0]) == 1
		|| (val = start_error_sep(temp, arr, ct, b)) == 1)
			return (1);
		if (val == -1)
			break;
	}
	if (temp->left != NULL)
		if (start_error_tree(temp->left, b) == 1)
			return (1);
	if (temp->right != NULL)
		if (start_error_tree(temp->right, b) == 1)
			return (1);
	return (0);
}
