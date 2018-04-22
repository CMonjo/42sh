/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** pipe_plus.c
*/

#include "my.h"

char	**load_command_out(tree_t* temp)
{
	char **command_out = word_array(temp->right->commande_parseur);

	while (my_strcmp_c(command_out[0], tab_name[3]) == 0) {
		temp = temp->right;
		command_out = word_array(temp->commande_parseur);
	}
	return (command_out);
}

int	my_last_command_pipe(env_st_t *env_st,
char **command_out, tree_t* temp, int *num)
{
	if (temp->fd_out != 1) {
		dup2(temp->fd_out, 1);
		close(temp->fd_out);
	}
	close(num[1]);
	if (env_st->status == 0) {
		my_pipe(command_out, num[0], 0, env_st);
	}
	close(num[0]);
	wait(NULL);
	return (0);
}

int	my_first_command_pipe(env_st_t *env_st,
char **command_in, tree_t* temp, int *num)
{
	if (temp->fd_in != 0) {
		dup2(temp->fd_in, 0);
		close(temp->fd_in);
	}
	close(num[0]);
	my_pipe(command_in, num[1], 1, env_st);
	close(num[1]);
	exit(0);
}
