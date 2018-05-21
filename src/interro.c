/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/interro.c
*/

#include "main.h"

int	is_there_inter(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		if (str[i] == '?')
			return (1);
	return (0);
}

int	arg_nbr_inter(char **array, int test)
{
	int c = 0;
	int i = 1;

	if (my_arraylen(array) == 1)
		return (0);
	for (; array[i] != NULL; i++, c++) {
		if (is_there_inter(array[i]) == 1)
			break;
	}
	if (test == 0)
		return (c);
	return (i);
}

char	**array_inter_sort_inter(char **array)
{
	int checkpoint = 0;
	char *tmp;

	for (int i = 0; array[i] != NULL; i++) {
		if (is_there_inter(array[i]) == 1)
			checkpoint = 1;
		if (checkpoint == 1 && is_there_inter(array[i]) == 0) {
			tmp = my_strdup(array[i]);
			array = delete_line(array, i);
			array = add_line(array, tmp, 1);
			free(tmp);
			i = -1;
			checkpoint = 0;
		}
	}
	return (array);
}

void	inter_handle(char **array, char **env, env_st_t *env_st)
{
	int index;
	glob_t globuffer;

	array = array_inter_sort(array);
	index = arg_nbr(array, 1);
	globuffer = globuffer_arg(globuffer, array, index);
	for (int i = 0; array[index] != NULL; index++, i++) {
		if (i == 0)
			glob(array[index], GLOB_DOOFFS, NULL, &globuffer);
		else
			glob(array[index], GLOB_DOOFFS | GLOB_APPEND, NULL,
			&globuffer);
	}
	index = arg_nbr(array, 1);
	for (int i = 0; i != index; i++)
		globuffer.gl_pathv[i] = array[i];
	star_execution(array, globuffer, env, env_st);
}