/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** start_double_sep.c
*/

#include "my.h"

void	first_simple_or_sep(char **arr,
tree_t* temp, env_st_t *env_st, int *b)
{
	int fd = 0;

	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[1]) == 0) {
		check_gnl(temp->left->commande_parseur, env_st->envp_cpy, env_st);
		if (env_st->status == 1 && check_sep_char(temp->right->commande_parseur) == -1)
			check_gnl(temp->right->commande_parseur, env_st->envp_cpy, env_st);
		else if (check_sep_char(temp->right->commande_parseur) == 2) {
			check_gnl(temp->right->left->commande_parseur, env_st->envp_cpy, env_st);
			if (env_st->status == 0)
				check_gnl(temp->right->right->commande_parseur, env_st->envp_cpy, env_st);
		}
		(*b) = 1;
	}
	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[2]) == 0) {
		if (temp->left != NULL)
			check_gnl(temp->left->commande_parseur, env_st->envp_cpy, env_st);
		if (env_st->status == 0)
			check_gnl(temp->right->commande_parseur, env_st->envp_cpy, env_st);
		(*b) = 1;
	}
	first_double_verif_sep(arr, temp, env_st, b);
}

void	first_double_verif_sep(char **arr,
tree_t* temp, env_st_t *env_st, int *b)
{
	int fd = 0;

	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[7]) == 0 &&
	check_sep_char(temp->left->commande_parseur) != -1) {
		my_right_red_pipe(word_array(temp->right->commande_parseur),
		temp, arr[0]);
		fd = temp->fd_out;
		temp = temp->left;
		temp->fd_out = fd;
		arr = word_array(temp->commande_parseur);
		if (my_strcmp_c(arr[0], tab_name[5]) == 0) {
			my_pipe_start(env_st,
			word_array(temp->left->commande_parseur),
			word_array(temp->right->commande_parseur), temp);
			(*b) = 1;
		}
	}
	second_double_verif_sep(arr, temp, env_st, b);
}

void	second_double_verif_sep(char **arr,
tree_t* temp, env_st_t *env_st, int *b)
{
	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[6]) == 0 &&
	check_sep_char(temp->right->commande_parseur) != -1) {
		arr = word_array(temp->right->commande_parseur);
		if (my_strcmp_c(arr[0], tab_name[5]) == 0) {
			temp->fd_out = -1;
			my_left_red_start(env_st, arr,
			word_array(temp->right->left->commande_parseur), temp);
			(*b) = 1;
		}
	}
	third_double_verif_sep(arr, temp, env_st, b);
}

void	third_double_verif_sep(char **arr,
tree_t* temp, env_st_t *env_st, int *b)
{
	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[3]) == 0 &&
	check_sep_char(temp->right->commande_parseur) != -1) {
		arr = word_array(temp->right->commande_parseur);
		if (my_strcmp_c(arr[0], tab_name[5]) == 0) {
			temp->fd_out = -1;
			my_double_left_red_start(env_st,
			word_array(temp->left->commande_parseur),
			word_array(temp->right->left->commande_parseur), temp);
			(*b) = 1;
		}
	}
	fourth_double_verif_sep(arr, temp, env_st, b);
}

void	fourth_double_verif_sep(char **arr,
tree_t* temp, env_st_t *env_st, int *b)
{
	int fd = 0;

	if ((*b) == 0 && my_strcmp_c(arr[0], tab_name[4]) == 0 &&
	check_sep_char(temp->left->commande_parseur) != -1) {
		my_right_red_pipe(word_array(temp->right->commande_parseur),
		temp, arr[0]);
		fd = temp->fd_out;
		temp = temp->left;
		temp->fd_out = fd;
		arr = word_array(temp->commande_parseur);
		if (my_strcmp_c(arr[0], tab_name[5]) == 0) {
			my_pipe_start(env_st,
			word_array(temp->left->commande_parseur),
			word_array(temp->right->commande_parseur), temp);
			(*b) = 1;
		}
	}
	first_start_sep(arr, temp, env_st, b);
}