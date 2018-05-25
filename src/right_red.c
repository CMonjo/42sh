/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** right_rep.c
*/

#include "main.h"

void	my_right_red_pipe(char **file, tree_t* temp, UNUSED char *sep)
{
	int fd;

	if (access(file[0], F_OK) != -1) {
		fd = open(file[0], O_WRONLY | O_APPEND | O_TRUNC);
		temp->fd_in = 0;
		temp->fd_out = fd;
	} else {
		fd = open(file[0], O_RDWR | O_CREAT, 0666);
		temp->fd_in = 0;
		temp->fd_out = fd;
	}
}

void	my_right_double_red_start(env_st_t *env_st, char **command,
char **file, tree_t* temp)
{
	int fd;
	char **rm = word_array(my_strcat("rm ", file[0], 0));

	if (access(file[0], F_OK) != -1) {
		fd = open(file[0], O_RDWR | O_APPEND, 0666);
		temp->left->fd_in = 0;
		temp->left->fd_out = fd;
		pipe_check_exec(command, env_st->envp_cpy, env_st, temp->left);
		close(fd);
		if (env_st->status == 1)
			pipe_check_exec(rm, env_st->envp_cpy, env_st, temp);
	} else {
		fd = open(file[0], O_RDWR | O_CREAT, 0666);
		temp->left->fd_in = 0;
		temp->left->fd_out = fd;
		pipe_check_exec(command, env_st->envp_cpy, env_st, temp->left);
		close(fd);
		if (env_st->status == 1)
			pipe_check_exec(rm, env_st->envp_cpy, env_st, temp);
	}
}

void	my_right_red_start(env_st_t *env_st, char **command,
char **file, tree_t* temp)
{
	int fd;
	char *rm = my_strcat("rm ", file[0], 0);

	if (access(file[0], F_OK) != -1) {
		fd = open(file[0], O_WRONLY | O_APPEND | O_TRUNC);
		temp->left->fd_in = 0;
		temp->left->fd_out = fd;
		pipe_check_exec(command, env_st->envp_cpy, env_st, temp->left);
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm), temp);
	} else {
		fd = open(file[0], O_RDWR | O_CREAT, 0666);
		temp->left->fd_in = 0;
		temp->left->fd_out = fd;
		pipe_check_exec(command, env_st->envp_cpy, env_st, temp->left);
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm), temp);
	}
}
