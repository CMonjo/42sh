/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/history/history_struct.c
*/

#include "main.h"

void	my_printf_history(history_t* temp)
{
	while (temp != NULL) {
		printf("HISTORY : '%s'\n", temp->command);
		temp = temp->next;
	}
}

void	fill_history(env_st_t *info, char *str)
{
	history_t* new_ele = malloc(sizeof(history_t));

	new_ele->command = my_strdup(str);
	new_ele->next = info->history;
	info->history = new_ele;
}