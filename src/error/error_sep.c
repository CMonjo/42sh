/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** error_sep.c
*/

#include "main.h"

int	error_redi_right_input(tree_t* temp, char *str)
{
	char **arr;
	char **arr_two;
	char **arr_three;

	if (temp->left == NULL || temp->right == NULL || temp->left->right == NULL)
		return (0);
	arr = word_array(temp->right->commande_parseur);
	arr_two = word_array(temp->left->commande_parseur);
	arr_three = word_array(temp->left->right->commande_parseur);
	if (my_strcmp_c(str, tab_name[7]) == 0 && my_strcmp("<", arr[0]) == 0
	&& my_strcmp("<<", arr_two[0]) == 0
	&& my_strcmp("|", arr_three[0]) == 0) {
		my_printf("Ambiguous input redirect.\n");
		return (1);
	}
	return (0);
}

int	error_and_or(tree_t* temp, char *str)
{
	char **arr = word_array(temp->right->commande_parseur);;

	if (my_strcmp_c(str, "&&") == 0 && my_strcmp_c(arr[0], "||") == 0
	&& temp->right->left == NULL) {
		my_printf("Invalid null command.\n");
		return (1);
	}
	return (0);
}

int	error_pipe_redic_bis(tree_t* temp, char *str, char **arr)
{
	if ((my_strcmp_c(str, tab_name[7]) == 0
	|| my_strcmp_c(str, tab_name[4]) == 0)
	&& check_sep_char(arr[0]) != -1 && temp->right->left == NULL) {
		my_printf("Missing name for redirect.\n");
		return (1);
	}
	if ((my_strcmp_c(str, tab_name[7]) == 0
	|| my_strcmp_c(str, tab_name[4]) == 0)
	&& my_strcmp("|", arr[0]) == 0) {
		my_printf("Ambiguous output redirect.\n");
		return (1);
	}

	if ((my_strcmp_c(str, tab_name[5]) == 0)
	&& (my_strcmp("<", arr[0]) == 0
	|| my_strcmp("<<", arr[0]) == 0)) {
		my_printf("Ambiguous input redirect.\n");
		return (1);
	}
	return (0);
}

int	error_pipe_redic_first(tree_t* temp, char *str)
{
	if ((my_strcmp_c(str, tab_name[7]) == 0
	|| my_strcmp_c(str, tab_name[4]) == 0
	|| my_strcmp_c(str, tab_name[6]) == 0
	|| my_strcmp_c(str, tab_name[3]) == 0) && temp->right == NULL) {
		my_printf("Missing name for redirect.\n");
		return (1);
	}
	if ((my_strcmp_c(str, tab_name[2]) == 0
	|| my_strcmp_c(str, "||") == 0 || my_strcmp_c(str, "&&") == 0)
	&& temp->right == NULL) {
		my_printf("Invalid null command.\n");
		return (1);
	}
	if ((my_strcmp_c(str, tab_name[5]) == 0
	&& (temp->left == NULL || temp->right == NULL))
	|| (my_strcmp_c(str, tab_name[7]) == 0 && temp->left == NULL)) {
		my_printf("Invalid null command.\n");
		return (1);
	}
	return (0);
}

int	error_pipe_redic(tree_t* temp, char *str)
{
	char **arr;

	if (error_pipe_redic_first(temp, str) == 1)
		return (1);
	if ((arr = word_array(temp->right->commande_parseur)) == NULL)
		exit(3);
	if (my_strcmp_c(str, tab_name[5]) == 0 && check_sep_char(arr[0]) != -1
	&& temp->right->left == NULL) {
		my_printf("Invalid null command.\n");
		return (1);

	}
	if (error_pipe_redic_bis(temp, str, arr) == 1)
		return (1);
	return (0);
}
