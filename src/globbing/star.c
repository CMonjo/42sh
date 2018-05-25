/*
** EPITECH PROJECT, 2017
** star.c
** File description:
** star_handle.c
*/

#include "main.h"

int	arg_nbr(char **array, int test)
{
	int c = 0;
	int i = 1;

	if (my_arraylen(array) == 1)
		return (0);
	for (; array[i] != NULL; i++, c++) {
		if (is_there_star(array[i]) == 1)
			break;
	}
	if (test == 0)
		return (c);
	return (i);
}

char	**is_the_same(char **array, char *str, int *modif)
{
	for (int i = 0; array != NULL && array[i] != NULL; i++) {
		if (my_strcmp(array[i], str) == 0) {
			array = delete_line(array, i);
			*modif = 1;
			return (array);
		}
	}
	*modif = 0;
	return (array);
}

int	is_there_changement(char **array, char **new)
{
	char **tmp = array;
	int modif = 0;

	for (int i = 0; new != NULL && new[i] != NULL; i++) {
		is_the_same(array, new[i], &modif);
		if (modif == 0) {
			array = tmp;
			return (1);
		}
	}
	array = tmp;
	return (0);
}

void	globuffer_arg(glob_t *globuffer, char **array, int index)
{
	if (index != 0)
		globuffer->gl_offs = arg_nbr(array, 0) + 1;
	else
		globuffer->gl_offs = 0;
}

char	**star_handle(char **array, char *str)
{
	int index;
	glob_t globuffer;

	if (check_stars(str) != 1)
		return (my_arraydup(array));
	array = array_star_sort(array);
	index = arg_nbr(array, 1);
	globuffer_arg(&globuffer, array, index);
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
	return(my_arraydup(globuffer.gl_pathv));
}