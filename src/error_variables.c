/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/error_variables.c
*/

#include "main.h"

int	find_local_var_error(char *str, env_st_t *env_st, int *b)
{
	set_t* set = env_st->set;

	if (set == NULL) {
		env_st->status = 1;
		my_putstr_err(str, ": Undefined variable.\n");
		(*b) = 1;
		return (1);
	}
	while (set != NULL) {
		if (my_strcmp(set->name, str) == 0)
			return (0);
		set = set->next;
	}
	(*b) = 1;
	env_st->status = 1;
	my_putstr_err(str, ": Undefined variable.\n");
	return (1);
}

char	*change_variable_error(char *str, int *ct, env_st_t *env_st, int *b)
{
	int ctp = (*ct);
	char *str_one = first_string(str, ct);
	char *name_var = variable_name_string(str, ct);
	char *str_two = second_string(str, ct);
	char *command;
	char *command_dest;

	if (find_local_var_error(name_var, env_st, b) == 1)
		return (str);
	(*ct) = ctp + my_strlen(find_local_var(name_var, env_st)) - 1;
	command = find_local_var(name_var, env_st);
	command_dest = my_strcat(str_one, command, 0);
	free(str_one);
	command_dest = my_strcat(command_dest, str_two, 0);
	free(str_two);
	return (command_dest);
}

int	variable_error(char *str, env_st_t *env_st)
{
	int b = 0;

	if (str == NULL)
		return (0);
	for (int ct = 0; str[ct] != '\0'; ct ++) {
		if (str[ct] == '$' && str[ct + 1] != '\0'
		&& str[ct + 1] != '\t' && str[ct + 1] != ' ')
			str = change_variable_error(str, &ct, env_st, &b);
		if (b == 1)
			return (1);
	}
	return (0);
}