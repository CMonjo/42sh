/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/variables.c
*/

#include "main.h"

char	*find_local_var(char *str, env_st_t *env_st)
{
	alias_t* set = env_st->set;

	while (set != NULL) {
		if (my_strcmp(set->name, str) == 0)
			return (set->value);
		set = set->next;
	}
	return (NULL);
}

int	find_local_var_error(char *str, env_st_t *env_st)
{
	alias_t* set = env_st->set;

	if (set == NULL) {
		env_st->status = 1;
		my_putstr_err(str, ": Undefined variable.\n");
		return (1);
	}
	while (set != NULL) {
		if (my_strcmp(set->name, str) == 0)
			return (0);
		set = set->next;
	}
	env_st->status = 1;
	my_putstr_err(str, ": Undefined variable.\n");
	return (1);
}

char	*first_string(char *str, int ct)
{
	char *command = malloc(sizeof(char) * (ct + 1));

	for (int ctb = 0; ctb != ct; ctb ++)
		command[ctb] = str[ctb];
	command[ct] = '\0';
	return (command);
}

char	*variable_name_string(char *str, int *ct)
{
	char *command = malloc(sizeof(char) * ((*ct) + 1));
	int ctb = 0;

	while (str[*ct] != '\0' && str[*ct] != ' ' && str[*ct] != '\t') {
		command[ctb] = str[*ct];
		ctb ++;
		(*ct) ++;
	}
	command[ctb] = '\0';
	return (command);
}

char	*second_string(char *str, int ct)
{
	char *command = malloc(sizeof(char) * (my_strlen(str) - ct));
	int ctb = 0;

	for (; str[ct] != '\0'; ctb ++, ct ++)
		command[ctb] = str[ct];
	command[ctb] = '\0';
	return (command);
}

int	change_variable(char *command, int ct, env_st_t *env_st)
{
	char *str_one = first_string(str, ct);
	char *name_var = variable_name_string(str, &ct);
	char *str_two = second_string(str, ct);
	char *command;
	char *command_dest;

	if (find_local_var_error(name_var, env_st) == 1)
		return (1);
	command = find_local_var(name_var, str, env_st);
	command_dest = my_strcat(str_one, command);
	command_dest =
	//APPELER LA FUNC QUI FREMPLACE LA VAR PAR LA COMMANDE PUIS TOUT STRCAT
	return (command _dest);
}

char	*variable(char *str, env_st_t *env_st)
{
	char **str;

	if (str == NULL)
		return (0);
	for (int ct = 0; str[ct] != '\0'; ct ++)
		if (str[ct] == '$' && str[ct + 1] != '\0'
		&& str[ct + 1] != '\t' && str[ct + 1] != ' ')
			local_var(str, ct, env_st);
	return (str);
}