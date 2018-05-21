/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

set_t *set_add_node(char *name, char *value)
{
	set_t *tmp = malloc(sizeof(set_t));

	tmp->name = my_strdup(name);
	tmp->value = my_strdup(value);
	tmp->next = NULL;
	return (tmp);
}

void set_add(env_st_t *env_st, char *name, char *value)
{
	set_t *new = set_add_node(name, value);

	if (env_st->set == NULL)
		env_st->set = new;
	else {
		new->next = env_st->set;
		env_st->set = new;
	}
}

void set_fill(env_st_t *env_st, char *name, char *value)
{
	set_t *tmp = env_st->set;

	while (tmp != NULL) {
		if (my_strcmp(tmp->name, name) == 0) {
			tmp->value = my_strdup(value);
			return;
		}
		tmp = tmp->next;
	}
	set_add(env_st, name, value);
}

int set(char **array, UNUSED char **envp, env_st_t *env_st)
{
	if (array[1] == NULL)
		set_display(env_st);
	else {
		for (int i = 1; array[i] != NULL; i++)
			set_parse(env_st, array[i]);
	}
	return (0);
}
