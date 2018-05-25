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
	tmp->active = 1;
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

int set_deep(char *str)
{
	int i = 1;

	if (str[0] != '=')
		return (1);
	while (str[i] != '\0') {
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
		i += 1;
	}
	return (0);
}

int	set_isalpha(env_st_t *env_st, char const *str)
{
	if ((str[0] <= 'z' && str[0] >= 'a') || (str[0] <= 'Z'
	&& str[0] >= 'A') || str[0] == 39 || str[0] == 34 ||
	str[0] == ' ' || str[0] == '\0')
		return (1);
	else {
		my_printf("set: Variable name must begin with a letter.\n");
		env_st->err = 1;
		env_st->status = 1;
		return (0);
	}
}