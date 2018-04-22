/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** error_sep.c
*/

#include "my.h"

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