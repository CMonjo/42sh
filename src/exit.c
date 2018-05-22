/*
** EPITECH PROJECT, 2018
** exit.c
** File description:
** exit command
*/

#include "main.h"

void	exit_display(int i, env_st_t *env_st)
{
	if (i == 0 && isatty(0))
		dprintf(2, "exit\n");
	if (i == 1 && isatty(0)) {
		dprintf(2, "exit: Badly formed number.\n");
		env_st->status = 1;
	}
	if (i == 2 && isatty(0)) {
		env_st->status = 1;
		dprintf(2, "exit: Expression Syntax.\n");
	}
}

int	is_there_alpha(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == '-' && str[i + 1] == '-')
			return (2);
		if (str[i] < 45 || (str[i] > 45 && str[i] < 48) ||
			(str[i] > 57 && str[i] < 65) ||
			(str[i] > 64 && str[i] < 91) || str[i] > 90 ||
			(str[0] == '-' && str[1] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

int	exit_command(char **array, UNUSED char **envp, env_st_t *env_st)
{
	if (array[1] != NULL && is_there_alpha(array[1]) == 0) {
		exit_display(0, env_st);
		env_st->status = (unsigned char)my_getnbr(array[1]);
		exit ((unsigned char)my_getnbr(array[1]));
	} else if (array[1] == NULL) {
		exit_display(0, env_st);
		env_st->status = 0;
		exit (0);
	}
	if ((array[1][0] >= '0' && array[1][0] <= '9') ||
		is_there_alpha(array[1]) == 2) {
		exit_display(1, env_st);
		return (0);
	}
	exit_display(2, env_st);
	return (0);
}