/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/scripting/scripting.c
*/

#include "main.h"

void removed_set(env_st_t *env_st, char *str)
{
	set_t *tmp = env_st->set;

	while (tmp != NULL) {
		if (my_strcmp(tmp->name, str) == 0) {
			tmp->active = 0;
			return;
		}
		tmp = tmp->next;
	}
}

int unset(char **array, UNUSED char **envp, env_st_t *env_st)
{
	if (array[1] == NULL)
		my_printf("unset: Too few arguments.\n");
	else {
		for (int i = 1; array[i] != NULL; i++)
			removed_set(env_st, array[i]);
	}
	return (0);
}