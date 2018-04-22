/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** pipe.c
*/

#include "my.h"

void	my_pipe(char **command, int fd_in,
int fd_out, env_st_t *env_st)
{
	dup2(fd_in, fd_out);
	pipe_check_exec(command, env_st->envp_cpy, env_st);
}

int	my_pipe_start_more(env_st_t *env_st,
tree_t* temp, int *num, int *num_pip)
{
	int pip[2];
	char **command_in = word_array(temp->left->commande_parseur);
	char **command_out = word_array(temp->right->commande_parseur);
	pid_t child;

	pipe(pip);
	if ((child = fork()) == 0) {
		if (my_strcmp_c(command_out[0], tab_name[3]) == 0) {
			my_pipe(command_in, pip[1], num_pip[0], env_st);
			my_pipe_start_more(env_st, temp->right, num, pip);
		}
		else {
			close(num_pip[1]);
			my_pipe(command_in, num[1], num_pip[0], env_st);
			close(num_pip[0]);
			close(num[1]);
		}
	} else
		wait(NULL);
	return (0);
}

void	my_pipe_start_only(env_st_t *env_st,
char **command_in, char **command_out, tree_t* temp)
{
	int num[2];
	int num_pip[2];
	pid_t child;

	pipe(num);
	pipe(num_pip);
	if ((child = fork()) == 0) {
		if (my_strcmp_c(command_out[0], tab_name[3]) == 0) {
			exit(0);
			my_pipe(command_in, num_pip[1], 1, env_st);
			my_pipe_start_more(env_st, temp->right, num, num_pip);
		} else {
			my_first_command_pipe(env_st, command_in, temp, num);
		}
		exit(0);
	} else
		my_last_command_pipe(env_st, command_out, temp, num);
}


int	my_pipe_start(env_st_t *env_st,
char **command_in, char **command_out, tree_t* temp)
{
	int fd_save_1 = dup(0);
	int fd_save = dup(1);

	check_path_pip(env_st->envp_cpy, command_out[0], env_st, command_out);
	if (env_st->status == 1)
		return (0);
	my_pipe_start_only(env_st, command_in, command_out, temp);
	dup2(fd_save, 1);
	dup2(fd_save_1, 0);
	return (0);
}
