/*
** EPITECH PROJECT, 2018
** history
** File description:
** dislplay
*/

#include "main.h"

void display_history(history_t *temp)
{
	if (temp->next)
		display_history(temp->next);
	my_printf("     %ld\t%s:%s\t%s\n", temp->number, temp->hrs, temp->min,
	temp->command);
}

int history(char **array, UNUSED char **envp, env_st_t *env_st)
{
	(void)array;
	display_history(env_st->history);
	return (0);
}
