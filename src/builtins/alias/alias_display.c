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
		if (tmp->bind[0] == ct) {
			my_printf("%s\t%s\n", tmp->bind, tmp->command_display);
		}
		tmp = tmp->next;
	}
}

void alias_display(env_st_t *env_st)
{
	alias_t *tmp = env_st->alias;

	if (tmp != NULL)
		my_bubble(tmp);
	for (int ct = 0; ct != 126; ct ++)
		alias_displaying(tmp, ct);
}

void alias_compare(env_st_t *env_st, char *str)
{
	alias_t *tmp = env_st->alias;

	while (tmp != NULL) {
		if (my_strcmp(tmp->bind, str) == 0) {
			my_printf("%s\n", tmp->command_display);
			break;
		}
		tmp = tmp->next;
	}
}
