/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** pipe.c
*/

#include "my.h"

/*void	my_pipe(char **command, int fd_in,
int fd_out, env_st_t *env_st)
{
	if (fd_out == -1)
		dup2(fd_in, 1);
	if (fd_in == -1)
		dup2(fd_in, 0);
	pipe_check_exec(command, env_st->envp_cpy, env_st, temp);
}*/

/*int	my_pipe_start_more(env_st_t *env_st,
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
}*/

void	my_pipe_start_only(env_st_t *env_st,
char **command_in, char **command_out, tree_t* temp)
{
	int num[2];
	pid_t child;
	char **arr1;
	char **arr2;

	pipe(num);
	if ((child = fork()) == 0) {
	//close(num[0]);
	//dup2(temp->fd_in, 0);
	//dup2(num[1], 1);
	fprintf(stderr, "%d\n", temp->fd_out);
	fprintf(stderr, "FD_IN   :   %d_to    PIPE   :    %d\n", temp->fd_in, num[1]);
	temp->left->fd_in = temp->fd_in;
	temp->left->fd_out = num[1];
	pipe_check_exec(command_in, env_st->envp_cpy, env_st, temp->left);
	//printf("\nCOMMANDE IN EXEC FILS  :    %s\n", command_in[0]);
	} else if (my_strcmp_c(command_out[0], tab_name[5]) == 0) {
		arr1 = word_array(temp->right->left->commande_parseur);
		arr2 = word_array(temp->right->right->commande_parseur);
		temp->right->fd_in = num[1];
		temp->right->fd_out = temp->fd_out;
		close(num[1]);
		//my_printf(" WALLAH CA RENTRE DANS LE PIPE    COMMAND IN   :   %s     COMMAND OUT  :   %s\n", arr1[0], arr2[0]);
		my_pipe_start_only(env_st, arr1, arr2, temp->right);
	}
	else {
		//printf("\nCOMMANDE IN EXEC PERE  :    %s\n", command_out[0]);
		close(num[1]);
		//dup2(num[0], 0);
		fprintf(stderr, " CAT : PIPE  :  %d FD_OUT   :   %d\n", num[0], temp->fd_out);
		temp->right->fd_in = num[0];
		temp->right->fd_out = temp->fd_out;
		pipe_check_exec(command_out, env_st->envp_cpy, env_st, temp->right);
		wait(NULL);
		//my_last_command_pipe(env_st, command_out, temp, num);
	}
}


int	my_pipe_start(env_st_t *env_st,
char **command_in, char **command_out, tree_t* temp)
{
	int fd_save_1 = dup(0);
	int fd_save = dup(1);


	temp->fd_in = 0;
	temp->fd_out = 1;
	if (my_strcmp_c(command_out[0], tab_name[5]) != 0)
		check_path_pip(env_st->envp_cpy, command_out[0], env_st, command_out);
	//my_printf("AVANT VERIF   COMMAND IN   :   %s     COMMAND OUT  :   %s    STATUS    :   %d\n", command_in[0], command_out[0], env_st->status);
	if (env_st->status == 1)
		return (0);
	//my_printf("APRES   VERIF   COMMAND IN   :   %s     COMMAND OUT  :   %s      STATUS    :    %d\n", command_in[0], command_out[0], env_st->status);
	my_pipe_start_only(env_st, command_in, command_out, temp);
	dup2(fd_save, 1);
	dup2(fd_save_1, 0);
	return (0);
}
