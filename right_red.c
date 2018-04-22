/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** right_rep.c
*/

#include "my.h"

void	my_right_red_pipe(char **file, tree_t* temp, char *sep)
{
	int fd;

	if (access(file[0], F_OK) != -1) {
		if (my_strcmp_c(sep, tab_name[2]) == 0) {
			fd = open(file[0], O_RDWR | O_APPEND, 0666);
			temp->fd_out = fd;
			return;
		}
		fd = open(file[0], O_WRONLY | O_APPEND | O_TRUNC);
		temp->fd_out = fd;
	} else {
		if (my_strcmp_c(sep, tab_name[2]) == 0) {
			fd = open(file[0], O_RDWR | O_CREAT, 0666);
			temp->fd_out = fd;
			return;
		}
		fd = open(file[0], O_RDWR | O_CREAT, 0666);
		temp->fd_out = fd;
	}
}

void	my_right_double_red_start(env_st_t *env_st, char **command,
char **file, tree_t* temp)
{
	int fd;
	char *rm = my_strcat("rm ", file[0], 0);

	if (access(file[0], F_OK) != -1) {
		fd = open(file[0], O_RDWR | O_APPEND, 0666);
		temp->fd_in = fd;
		temp->fd_out = 1;
		exec_red(env_st, command, temp);
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm));
	} else {
		fd = open(file[0], O_RDWR | O_CREAT, 0666);
		exec_red(env_st, command, temp);
		temp->fd_in = fd;
		temp->fd_out = 1;
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm));
	}
}

void	my_right_red_start(env_st_t *env_st, char **command,
char **file, tree_t* temp)
{
	int fd;
	char *rm = my_strcat("rm ", file[0], 0);

	if (access(file[0], F_OK) != -1) {
		fd = open(file[0], O_WRONLY | O_APPEND | O_TRUNC);
		temp->fd_in = fd;
		temp->fd_out = 1;
		exec_red(env_st, command, temp);
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm));
	} else {
		fd = open(file[0], O_RDWR | O_CREAT, 0666);
		temp->fd_in = fd;
		temp->fd_out = 1;
		exec_red(env_st, command, temp);
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm));
	}
}
