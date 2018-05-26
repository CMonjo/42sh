/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** pipe_plus.c
*/

#include "main.h"

char	**load_command_out(tree_t* temp)
{
	char **command_out = word_array(temp->right->commande_parseur);

	while (my_strcmp_c(command_out[0], tab_name[3]) == 0) {
		temp = temp->right;
		command_out = word_array(temp->commande_parseur);
	}
	return (command_out);
}