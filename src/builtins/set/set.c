/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

set_t *set_add_node(char **str, char *long_str)
{
	set_t *tmp = malloc(sizeof(set_t));

	tmp->var = str[1];
	tmp->var_value = my_strdup(long_str);
	tmp->next = NULL;
	return(tmp);
}

void set_add(env_st_t *env_st, char **str, char *long_str)
{
	set_t *new = set_add_node(str, long_str);

	if (env_st->set == NULL)
		env_st->set = new;
	else {
		new->next = env_st->set;
		env_st->set = new;
	}
}

void set_fill(env_st_t *env_st, char **str, char *long_str)
{
	set_t *tmp = env_st->set;

	while (tmp != NULL) {
		if (my_strcmp(tmp->var, str[1]) == 0) {
			tmp->var_value = my_strdup(long_str);
			return;
		}
		tmp = tmp->next;
	}
	set_add(env_st, str, long_str);
}

int set(char **array, UNUSED char **envp, env_st_t *env_st)
{
	char *str = set_parse(array);

	if (array[1] == NULL)
		set_display(env_st);
	else if (array[2] == NULL)
		set_compare(env_st, array[1]);
	else
		set_fill(env_st, array, str);
	return (0);
}
