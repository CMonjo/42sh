/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** pipe.c
*/

#include "main.h"

void	my_pipe_start_only_else(env_st_t *env_st,
char **command_out, int *num, tree_t* temp)
{
	char **arr1;
	char **arr2;

	if (my_strcmp_c(command_out[0], tab_name[5]) == 0) {
		arr1 = word_array(temp->right->left->commande_parseur);
		arr2 = word_array(temp->right->right->commande_parseur);
		temp->right->fd_in = num[0];
		temp->right->fd_out = temp->fd_out;
		close(num[1]);
		my_pipe_start_only(env_st, arr1, arr2, temp->right);
	} else {
		close(num[1]);
		temp->right->fd_in = num[0];
		temp->right->fd_out = temp->fd_out;
		pipe_check_exec(command_out, env_st->envp_cpy,
		env_st, temp->right);
		wait(NULL);
	}
}

void	my_pipe_start_only(env_st_t *env_st,
char **command_in, char **command_out, tree_t* temp)
{
	int num[2];
	pid_t child;

	if (pipe(num) == -1)
		exit(1);
	if ((child = fork()) == 0) {
		temp->left->fd_in = temp->fd_in;
		temp->left->fd_out = num[1];
		pipe_check_exec(command_in, env_st->envp_cpy,
		env_st, temp->left);
		exit(0);
	} else
		my_pipe_start_only_else(env_st, command_out, num, temp);
}

int	my_pipe_start(env_st_t *env_st,
char **command_in, char **command_out, tree_t* temp)
{
	int fd_save_one = dup(0);
	int fd_save = dup(1);

	if (fd_save_one == -1 || fd_save == -1)
		exit(1);
	if (my_strcmp_c(command_out[0], tab_name[5]) != 0)
		check_path_pip(env_st->envp_cpy, command_out[0],
		env_st, command_out);
	my_pipe_start_only(env_st, command_in, command_out, temp);
	dup2(fd_save, 1);
	dup2(fd_save_one, 0);
	return (0);
}
