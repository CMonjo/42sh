/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

void set_fill(env_st_t *env_st, char *name, char *value)
{
	set_t *tmp = env_st->set;

	if (set_deep(value) == 0) {
		my_printf("Directory stack not that deep.\n");
		env_st->status = 1;
		return;
	}
	while (tmp != NULL) {
		if (my_strcmp(tmp->name, name) == 0) {
			tmp->value = my_strdup(value);
			tmp->active = 1;
			return;
		}
		tmp = tmp->next;
	}
	set_add(env_st, name, value);
}

void set_check_array(env_st_t *env_st, char **array, int i)
{
	if (array[i + 1] != NULL && array[i + 1][0] == '=') {
		set_parse_spaces(env_st, array[i], array[i + 2]);
		env_st->set_array = 2;
	} else
		set_parse(env_st, array[i], array[i + 1]);
}

void set_initialize(env_st_t *env_st, char **array)
{
	for (int i = 1; array[i] != NULL && env_st->err == 0; i++) {
		if (env_st->set_array != 0)
			env_st->set_array--;
		else
			set_check_array(env_st, array, i);
	}
	env_st->status = 0;
}

int set(char **array, UNUSED char **envp, env_st_t *env_st)
{
	if (array[1] == NULL) {
		env_st->status = 0;
		set_display(env_st);
	} else
		set_initialize(env_st, array);
	env_st->err = 0;
	return (0);
}