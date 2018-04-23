/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** error_sep.c
*/

#include "my.h"

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
	if (my_strcmp_c(str, tab_name[7]) == 0 && my_strcmp("<", arr[0]) == 0 && my_strcmp("<<", arr_two[0]) == 0 && my_strcmp("|", arr_three[0]) == 0) {
		my_printf("Ambiguous input redirect.\n");
		exit(1);
	}
	return (0);
}

int	error_pipe_redic_second(tree_t* temp, char *str)
{
	char **arr;

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
		exit(1);
		}
	}
	return (0);
}

int	error_pipe_redic_bis(tree_t* temp, char *str, char **arr)
{
	if ((my_strcmp_c(str, tab_name[7]) == 0
	|| my_strcmp_c(str, tab_name[4]) == 0)
	&& check_sep_char(arr[0]) != -1 && temp->right->left == NULL) {
		my_printf("Missing name for redirect.\n");
		exit(1);
	}
	if ((my_strcmp_c(str, tab_name[7]) == 0
	|| my_strcmp_c(str, tab_name[4]) == 0)
	&& my_strcmp("|", arr[0]) == 0) {
		my_printf("Ambiguous output redirect.\n");
		exit(1);
	}

	if ((my_strcmp_c(str, tab_name[5]) == 0) && (my_strcmp("<", arr[0]) == 0
	|| my_strcmp("<<", arr[0]) == 0)) {
		my_printf("Ambiguous input redirect.\n");
		exit(1);
	}
	return (0);
}

int	error_pipe_redic_first(tree_t* temp, char *str)
{
	if (my_strcmp_c(str, tab_name[2]) == 0 && temp->right == NULL) {
		my_printf("Invalid null command.\n");
		exit(1);
	}
	if ((my_strcmp_c(str, tab_name[5]) == 0
	&& (temp->left == NULL || temp->right == NULL))
	|| (my_strcmp_c(str, tab_name[7]) == 0 && temp->left == NULL)) {
		my_printf("Invalid null command.\n");
		exit(1);
		exit(1);
	}
	if ((my_strcmp_c(str, tab_name[7]) == 0
	|| my_strcmp_c(str, tab_name[4]) == 0
	|| my_strcmp_c(str, tab_name[6]) == 0
	|| my_strcmp_c(str, tab_name[3]) == 0) && temp->right == NULL) {
		my_printf("Missing name for redirect.\n");
		exit(1);
		exit(1);
	}
	return (0);
}

int	error_pipe_redic(tree_t* temp, char *str)
{
	char **arr;

	if (error_pipe_redic_first(temp, str) == 1)
		return (1);
	arr = word_array(temp->right->commande_parseur);
	if (my_strcmp_c(str, tab_name[5]) == 0 && check_sep_char(arr[0]) != -1
	&& temp->right->left == NULL) {
		my_printf("Invalid null command.\n");
		exit(1);
		exit(1);

	}
	if (error_pipe_redic_bis(temp, str, arr) == 1)
		return (1);
	return (0);
}

void	error_backstick_quote(char *str, char c, int *ct)
{
	while (str[*ct] != '\0') {
		if (str[*ct] == c)
			return;
		(*ct) ++;
	}
	my_printf("Unmatched %c.\n", c);
	exit(1);
}

void	error_parent(char *command)
{
	int parent_left = 0;
	int parent_right = 0;

	for (int ct = 0; command[ct] != '\0'; ct ++) {
		if (command[ct] == 41)
			parent_right ++;
		if (command[ct] == 40)
			parent_left ++;
		if (command[ct] == 34 || command[ct] == 39) {
			ct ++;
			error_backstick_quote(command, command[ct - 1], &ct);
		}
	}
	if (parent_left == 0 && parent_right == 0)
		return;
	if (parent_left == 0) {
		my_printf("Too many %c's.\n", 41);
		exit(1);
	}
	if (parent_right == 0) {
		my_printf("Too many %c's.\n", 40);
		exit(1);
	}
	if ((parent_right / parent_left) == 0) {
		my_printf("Too many %c's.\n", 40);
		exit(1);
	}
	if ((parent_left / parent_right) == 0) {
		my_printf("Too many %c's.\n", 41);
		exit(1);
	}
}