/*
** EPITECH PROJECT, 2018
** alias.c
** File description:
** set alias in the sheel
*/

#include "main.h"

void removed_alias(env_st_t *env_st, char *str)
{
	alias_t *tmp = env_st->alias;

	while (tmp != NULL) {
		if (my_strcmp(tmp->bind, str) == 0) {
			tmp->active = 0;
			return;
		}
		tmp = tmp->next;
	}
}

int unalias(char **array, UNUSED char **envp, env_st_t *env_st)
{
	if (array[1] == NULL)
		printf("unalias: Too few arguments.\n");
	else {
		for (int i = 1; array[i] != NULL; i++)
			removed_alias(env_st, array[i]);
	}
	return (0);
}