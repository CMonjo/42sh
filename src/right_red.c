/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** right_rep.c
*/

#include "main.h"

void	my_right_red_pipe(char **file, tree_t* temp, char *sep)
{
	int fd;

	if (access(file[0], F_OK) != -1) {
		/*if (my_strcmp_c(sep, tab_name[7]) == 0) {
			fd = open(file[0], O_RDWR | O_APPEND, 0666);
			temp->fd_in = 0;
			temp->fd_out = fd;
			return;
		}*/
		fd = open(file[0], O_WRONLY | O_APPEND | O_TRUNC);
		temp->fd_in = 0;
		temp->fd_out = fd;
	} else {
		/*if (my_strcmp_c(sep, tab_name[7]) == 0) {
			fd = open(file[0], O_RDWR | O_CREAT, 0666);
			temp->fd_in = 0;
			temp->fd_out = fd;
			printf("FD_OUT RED %d\n", fd);
			return;
		}*/
		fd = open(file[0], O_RDWR | O_CREAT, 0666);
		//printf("FD out : %d\n", fd);
		temp->fd_in = 0;
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
		temp->left->fd_in = 0;
		temp->left->fd_out = fd;
		exec(env_st->envp_cpy, env_st, command, temp->left);
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm), temp);
	} else {
		fd = open(file[0], O_RDWR | O_CREAT, 0666);
		//printf("RIGHT DOUBLE REDI  :   FD   :   %d    TEMP  %s    TEMP LEFT    %s    FILE :   %s\n", fd, temp->commande_parseur, temp->left->commande_parseur, file[0]);
		temp->left->fd_in = 0;
		temp->left->fd_out = fd;
		exec(env_st->envp_cpy, env_st, command, temp->left);
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm), temp);
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
		exec(env_st->envp_cpy, env_st, command, temp->left);
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm), temp);
	} else {
		fd = open(file[0], O_RDWR | O_CREAT, 0666);
		temp->left->fd_in = 0;
		temp->left->fd_out = fd;
		exec(env_st->envp_cpy, env_st, command, temp->left);
		close(fd);
		if (env_st->status == 1)
			exec(env_st->envp_cpy, env_st, word_array(rm), temp);
	}
}
