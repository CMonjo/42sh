/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** left_redi.c
*/

#include "main.h"

void	my_left_red_start(env_st_t *env_st, char **command,
char **file, tree_t* temp)
{
	int fd;

	if (access(file[0], F_OK) != -1) {
		fd = open(file[0], O_RDONLY);
		temp->left->fd_in = fd;
		exec(env_st->envp_cpy, env_st, command, temp->left);
		close(fd);
	} else
		my_putstr_err(file[0], ": No such file or directory.\n");
}

void	prompt_red_left(void)
{
	if (isatty(0) == 1)
		my_printf("? ");
}

char	*my_strcat_char(char *dest, char src)
{
	char *temp;

	temp = malloc(sizeof(char) * (my_strlen(dest) + 2));
	for (int ct = 0; dest[ct] != '\0'; ct ++)
		temp[ct] = dest[ct];
	temp[my_strlen(dest)] = src;
	temp[my_strlen(dest) + 1] = '\0';
	return (temp);
}

char	*create_file(void)
{
	char *file = "C24bYs1-2NiColaS2_0alBigEs9_A3u1z0WtF";
	int add = 65;

	for (int ct = 0; ct != 210; ct ++) {
		if (access(file, F_OK) != -1)
			return (file);
		my_strcat_char(file, (char)add);
		add ++;
		if (add == 90)
			add = 65;
	}
	if (access(file, F_OK) != -1)
		exit(0);
	return (file);
}

void	my_double_left_red_start(env_st_t *env_st, char **command,
char **file, tree_t* temp)
{
	char *str = "\0";
	int fd = 0;
	char *file_tmp = NULL;

	fd = open((file_tmp = create_file()), O_RDWR | O_CREAT, 0666);
	while (my_strcmp(str, file[0]) != 0) {
		str = my_getline();
		if (isatty(0) == 1 && str == NULL) {
			exit(0);
		}
		if (my_strlen(str) > 0 && my_strcmp(str, file[0]) != 0) {
			write(fd, str, my_strlen(str));
			write(fd, "\n", 1);
		}
		else if (isatty(0) != 1)
			break;
		prompt_red_left();
	}
	my_left_red_start(env_st, command, word_array(file_tmp), temp);
	exec(env_st->envp_cpy, env_st,
	word_array(my_strcat("rm ", file_tmp, 0)), temp);
}
