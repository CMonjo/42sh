/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set in the sheel
*/

#include "main.h"

void set_displaying(set_t *tmp, int ct)
{
	while (tmp != NULL) {
		if (tmp->name[0] == ct && tmp->active == 1)
			my_printf("%s\t%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

void set_display(env_st_t *env_st)
{
	set_t *tmp = env_st->set;

	if (isatty(0) == 1 && env_st->history->next != NULL)
		my_printf("_\t%s\n\n", env_st->history->next->command);
	else
		my_printf("_ \n");
	for (int ct = 0; ct != 126; ct++)
		set_displaying(tmp, ct);
}