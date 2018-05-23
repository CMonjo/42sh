/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/variables.c
*/

#include "main.h"

char	*find_local_var(char *str, env_st_t *env_st)
{
	set_t* set = env_st->set;

	while (set != NULL) {
		if (my_strcmp(set->name, str) == 0)
			return (set->value);
		set = set->next;
	}
	if (check_val(env_st->envp_cpy, str, env_st) == 0)
		exit(5);
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

	//printf("STR_ONE  :  '%s'   NAMEVAR : '%s'   STR_TWO   :   '%s'\n", str_one, name_var, str_two);
	(*ct) = ctp + my_strlen(find_local_var(name_var, env_st)) - 1;
	command = find_local_var(name_var, env_st);
	command_dest = my_strcat(str_one, command, 0);
	command_dest = my_strcat(command_dest, str_two, 0);
	//printf("COMMANDE  :  %s    CT  :   %d    LEN   :   %d\n", command_dest, (*ct), my_strlen(command_dest));
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