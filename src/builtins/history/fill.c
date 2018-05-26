/*
** EPITECH PROJECT, 2018
** history
** File description:
** fill
*/

#include "main.h"

void	fill_history(env_st_t *info, char *command)
{
	history_t* new_ele = malloc(sizeof(history_t));
	time_t t = time(NULL);
	struct tm *timeinfo;
	char str[64];

	time(&t);
	timeinfo = localtime(&t);
	strftime(str, sizeof(str), "%R", timeinfo);
	new_ele->command = my_strdup(command);
	new_ele->number = (info->history) ? info->history->number + 1 : 1;
	new_ele->hrs[0] = str[0];
	new_ele->hrs[1] = str[1];
	new_ele->min[0] = str[3];
	new_ele->min[1] = str[4];
	new_ele->next = info->history;
	new_ele->prev = NULL;
	(info->history != NULL) ? info->history->prev = new_ele : 0;
	info->history = new_ele;
}
