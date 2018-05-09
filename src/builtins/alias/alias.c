/*
** EPITECH PROJECT, 2018
** alias.c
** File description:
** set alias in the sheel
*/

#include "main.h"

alias_t *alias_add_node(char **str, char *long_str, char *parents)
{
	alias_t *tmp = malloc(sizeof(alias_t));

	tmp->bind = str[1];
	tmp->command_bind = my_strdup(long_str);
	tmp->command_display =
	my_strdup(alias_check_string(long_str, parents));
	tmp->next = NULL;
	return(tmp);
}

void alias_add(env_st_t *env_st, char **str, char *long_str, char *parents)
{
	alias_t *new = alias_add_node(str, long_str, parents);

	if (env_st->alias == NULL)
		env_st->alias = new;
	else {
		new->next = env_st->alias;
		env_st->alias = new;
	}
}

void alias_fill(env_st_t *env_st, char **str, char *long_str, char *parents)
{
	alias_t *tmp = env_st->alias;

	while (tmp != NULL) {
		if (my_strcmp(tmp->bind, str[1]) == 0) {
			tmp->command_bind = my_strdup(long_str);
			tmp->command_display =
			my_strdup(alias_check_string(long_str, parents));
			return;
		}
		tmp = tmp->next;
	}
	alias_add(env_st, str, long_str, parents);

}

int alias(char **array, UNUSED char **envp, env_st_t *env_st)
{
	char *long_str = alias_parse(array);
	char *parents = alias_parse_parenthesis(array);

	if (array[1] == NULL)
		alias_display(env_st);
	else if (array[2] == NULL)
		alias_compare(env_st, array[1]);
	else
		alias_fill(env_st, array, long_str, parents);
	return (0);
}
