/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/start_double_sep_and_or.c
*/

#include "main.h"

void	first_simple_or_sep_or(tree_t* temp, env_st_t *env_st)
{
	check_gnl(temp->left->commande_parseur,
	env_st->envp_cpy, env_st, temp);
	if (env_st->status != 0
	&& check_sep_char(temp->right->commande_parseur) == -1)
		check_gnl(temp->right->commande_parseur,
		env_st->envp_cpy, env_st, temp);
	else if (env_st->status != 0
	&& check_sep_char(temp->right->commande_parseur) == 2) {
		check_gnl(temp->right->left->commande_parseur,
		env_st->envp_cpy, env_st, temp);
		if (env_st->status == 0)
			check_gnl(temp->right->right->commande_parseur,
			env_st->envp_cpy, env_st, temp);
	}
}

void	first_simple_or_sep_and(tree_t* temp, env_st_t *env_st)
{
	if (temp->left != NULL)
		check_gnl(temp->left->commande_parseur,
		env_st->envp_cpy, env_st, temp);
	if (env_st->status == 0
	&& check_sep_char(temp->right->commande_parseur) == -1)
		check_gnl(temp->right->commande_parseur,
		env_st->envp_cpy, env_st, temp);
	else if (env_st->status == 0
	&& check_sep_char(temp->right->commande_parseur) == 1) {
		check_gnl(temp->right->left->commande_parseur,
		env_st->envp_cpy, env_st, temp);
		if (env_st->status != 0)
			check_gnl(temp->right->right->commande_parseur,
			env_st->envp_cpy, env_st, temp);
	}
	else if (env_st->status != 0 &&
	check_sep_char(temp->right->commande_parseur) == 1)
		check_gnl(temp->right->right->commande_parseur,
		env_st->envp_cpy, env_st, temp);
}