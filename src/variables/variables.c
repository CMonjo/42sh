/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/variables.c
*/

#include "main.h"

variables_t const tab_name_var[] = {
	{"?", value_return},
	{"$", get_pid},
};

char	*find_local_var(char *str, env_st_t *env_st)
{
	set_t* set = env_st->set;

	for (int ct = 0; ct < 2; ct ++)
		if (str != NULL
		&& my_strcmp(str, tab_name_var[ct].name) == 0)
			return ((tab_name_var[ct].name_str)(str, env_st));
	while (set != NULL) {
		if (set->active == 1 && my_strcmp(set->name, str) == 0)
			return (set->value);
		set = set->next;
	}
	if (select_env(env_st->envp_cpy, str) != NULL) {
		return (select_env(env_st->envp_cpy, str));
	}
	return (NULL);
}

char	*change_variable(char *str, int *ct, env_st_t *env_st)
{
	int ctp = (*ct);
	char *str_one = first_string(str, ct);
	char *name_var = variable_name_string(str, ct);
	char *str_two = second_string(str, ct);
	char *command;
	char *command_dest;

	(*ct) = ctp + my_strlen(find_local_var(name_var, env_st)) - 1;
	command = find_local_var(name_var, env_st);
	command_dest = my_strcat(str_one, command, 0);
	command_dest = my_strcat(command_dest, str_two, 0);
	return (command_dest);
}

char	*variable(char *str, env_st_t *env_st)
{
	if (str == NULL)
		return (0);
	for (int ct = 0; str[ct] != '\0'; ct ++)
		if (str[ct] == '$' && str[ct + 1] != '\0'
		&& str[ct + 1] != '\t' && str[ct + 1] != ' ')
			str = change_variable(str, &ct, env_st);
	return (str);
}