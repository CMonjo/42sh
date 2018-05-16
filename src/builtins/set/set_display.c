/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

void set_display(env_st_t *env_st)
{
	set_t *tmp = env_st->set;

	while (tmp != NULL) {
		my_printf("%s\t%s\n", tmp->var, tmp->var_value);
		tmp = tmp->next;
	}
}

void set_compare(env_st_t *env_st, char *str)
{
	set_t *tmp = env_st->set;

	while (tmp != NULL) {
		if (my_strcmp(tmp->var, str) == 0) {
			my_printf("%s\n", tmp->var_value);
			break;
		}
		tmp = tmp->next;
	}
}
