/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** check_command.c
*/

#include "main.h"

int	yes(char **str, UNUSED char **envp, UNUSED env_st_t *env_st)
{
	int len = my_strlen(str[1]);

	while (1) {
		write(1, str[1], len);
		my_putchar('\n');
	}
	return (0);
}