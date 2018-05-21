/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/variables.c
*/

#include "main.h"

int	local_var(char *command, char *str, env_st_t *env_st)
{
	alias_t* set = env_st->set;

	if (str[0] == '$') {
		//local variables
	}
	if (set != NULL && error_alias_loop(command, str, env_st) == 1)
		return (1);
	while (set != NULL) {
		if (my_strcmp(set->name, command) == 0) {
			check_gnl(set->value,
			env_st->envp_cpy, env_st,
			my_list_command(set->name, env_st, 0, 1));
			return (1);
		}
		set = set->next;
	}
	return (0);
}

char	*variable(char *command, char *str, env_st_t *env_st)
{
	char **arr;

	if ((arr = word_array(name)) == NULL)
		return (0);
	for (int ct = 0; arr[ct] != NULL; ct ++)
		if (arr[ct][0] == '$' && arr[ct][1] != '\0')
			local_var(command, str, env_st);
}