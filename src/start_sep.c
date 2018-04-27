/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** start_sep.c
*/

#include "main.h"

void	first_start_sep(char **arr, tree_t* temp, env_st_t *env_st, int *b)
{
	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[6]) == 0 &&
	check_sep_char(temp->right->commande_parseur) == -1) {
		my_left_red_start(env_st,
		word_array(temp->left->commande_parseur),
		word_array(temp->right->commande_parseur), temp);
		(*b) = 1;
	}
	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[7]) == 0 &&
	check_sep_char(temp->left->commande_parseur) == -1) {
		my_right_red_start(env_st,
		word_array(temp->left->commande_parseur),
		word_array(temp->right->commande_parseur), temp);
		(*b) = 1;
	}
	second_start_sep(arr, temp, env_st, b);
}

void	second_start_sep(char **arr, tree_t* temp, env_st_t *env_st, int *b)
{
	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[4]) == 0 &&
	check_sep_char(temp->right->commande_parseur) == -1) {
		my_right_double_red_start(env_st,
		word_array(temp->left->commande_parseur),
		word_array(temp->right->commande_parseur), temp);
		(*b) = 1;
	}
	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[3]) == 0 &&
	check_sep_char(temp->right->commande_parseur) == -1) {
		my_double_left_red_start(env_st,
		word_array(temp->left->commande_parseur),
		word_array(temp->right->commande_parseur), temp);
		(*b) = 1;
	}
	third_start_sep(arr, temp, env_st, b);
}

void	third_start_sep(char **arr, tree_t* temp, env_st_t *env_st, int *b)
{
	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[5]) == 0) {
		my_pipe_start(env_st,
		word_array(temp->left->commande_parseur),
		word_array(temp->right->commande_parseur), temp);
		(*b) = 1;
	}
}
