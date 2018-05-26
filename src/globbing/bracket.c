/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/bracket.c
*/

#include "main.h"

int	is_there_bracket(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		if (str[i] == '[' && check_bracket_close(str, i) == 1)
			return (1);
	return (0);
}

int	arg_nbr_bracket(char **array, int test)
{
	int c = 0;
	int i = 1;

	if (my_arraylen(array) == 1)
		return (0);
	for (; array[i] != NULL; i++, c++) {
		if (is_there_bracket(array[i]) == 1)
			break;
	}
	if (test == 0)
		return (c);
	return (i);
}

char	**array_bracket_sort(char **array)
{
	int checkpoint = 0;
	char *tmp;

	for (int i = 0; array[i] != NULL; i++) {
		if (is_there_bracket(array[i]) == 1)
			checkpoint = 1;
		if (checkpoint == 1 && is_there_bracket(array[i]) == 0) {
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

void	globuffer_arg_bracket(glob_t *globuffer, char **array, int index)
{
	if (index != 0)
		globuffer->gl_offs = arg_nbr_bracket(array, 0) + 1;
	else
		globuffer->gl_offs = 0;
}

char	**bracket_handle(char **array, char *str)
{
	int index;
	glob_t globuffer;

	if (check_bracket(str) != 1)
		return (array);
	array = array_bracket_sort(array);
	index = arg_nbr_bracket(array, 1);
	globuffer_arg_bracket(&globuffer, array, index);
	for (int i = 0; array[index] != NULL; index++, i++) {
		if (i == 0)
			glob(array[index], GLOB_DOOFFS, NULL, &globuffer);
		else
			glob(array[index], GLOB_DOOFFS | GLOB_APPEND, NULL,
			&globuffer);
	}
	index = arg_nbr_bracket(array, 1);
	for (int i = 0; i != index; i++)
		globuffer.gl_pathv[i] = array[i];
	return (globuffer.gl_pathv);
}