/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/error_main_b_tree.c
*/

#include "main.h"

int	error_main_b_tree_variable(char *str, char *command, env_st_t *info)
{
	if (variable_error(command, info) == 1) {
		command = check_command(str, 0);
		fill_history(info, command);
		return (1);
	}
	return (0);
}

int	check_special_case(char *str)
{
	char **arr = word_array(str);
	int str_arr = 0;

	while (arr[str_arr] != NULL)
		str_arr ++;
	if (str_arr != 1)
		return (0);
	for (int ct = 0; arr[0][ct] != '\0'; ct ++)
		if (arr[0][ct] != ';' && arr[0][ct] != '&')
			return (0);
	return (1);
}

int	error_main_b_tree(char *command, env_st_t *info, tree_t* temp)
{
	char **arr;

	if ((arr = word_array(command)) == NULL)
		return (1);
	for (int ct = 0; arr[ct] != NULL; ct ++) {
		if (my_strcmp(arr[ct], "alias") == 0
		|| my_strcmp(arr[ct], "unalias") == 0)
			pass_alias_unalias(arr, &ct);
		if (arr[ct] == NULL)
			break;
		if (info->alias != NULL
		&& error_alias_loop(arr[ct], arr[ct], info) == 1)
			return (1);
	}
	if (start_error_tree(temp, 0) == 1 || start_error_tree(temp, 1) == 1) {
		info->status = 1;
		return (1);
	}
	return (0);
}