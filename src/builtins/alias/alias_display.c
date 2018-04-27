/*
** EPITECH PROJECT, 2018
** alias.c
** File description:
** set alias in the sheel
*/

#include "main.h"

void	alias_displaying(alias_t *tmp, int ct)
{

	while (tmp != NULL) {
		if (tmp->bind[0] == ct)
			my_printf("%s\t%s\n", tmp->bind, tmp->command_display);
		tmp = tmp->next;
	}
}

void alias_display(env_st_t *env_st)
{
	alias_t *tmp = env_st->alias;

	for (int ct = 0; ct != 126; ct ++)
		alias_displaying(tmp, ct);
}