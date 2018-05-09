/*
** EPITECH PROJECT, 2017
** star.c
** File description:
** star_handle.c
*/

#include "main.h"

int	is_there_star(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		if (str[i] == '*')
			return (1);
	return (0);
}

int	my_arraylen(char **array)
{
	int i = 0;

	for (; array != NULL && array[i] != NULL; i++);
	return (i);
}

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

char	**add_line(char **array, char *str, int i)
{
	char **new = malloc(sizeof(char *) * my_arraylen(array) + 2);
	int u = 0;
	int c = 0;

	for (; c != i; c++, u++)
		new[u] = array[c];
	new[u] = my_strdup(str);
	u++;
	for (; array != NULL && array[c] != NULL; c++, u++)
		new[u] = array[c];
	new[u] = NULL;
	return (new);
}

char	**delete_line(char **array, int i)
{
	char **new = malloc(sizeof(char *) * (my_arraylen(array)));
	int u = 0;
	int c = 0;

	for (; c != i; c++, u++)
		new[u] = array[c];
	c++;
	for (; array[c] != NULL; c++, u++)
		new[u] = array[c];
	new[u] = NULL;
	return (new);
}

char	**array_star_sort(char **array)
{
	int checkpoint = 0;
	char *tmp;

	for (int i = 0; array[i] != NULL; i++) {
		if (is_there_star(array[i]) == 1)
			checkpoint = 1;
		if (checkpoint == 1 && is_there_star(array[i]) == 0) {
			tmp = my_strdup(array[i]);
			array = delete_line(array, i);
			array = add_line(array, tmp, 1);
			free (tmp);
			i = -1;
			checkpoint = 0;
		}
	}
	return (array);
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

void	star_execution(char **array, glob_t globuffer, char **env,
env_st_t *env_st)
{
	tree_t *tree = env_st->tree;

	tree = my_list_command(array[0], env_st);
	if (is_there_changement(array, globuffer.gl_pathv) == 1)
		pipe_check_exec(globuffer.gl_pathv, env, env_st, tree);
	else
		my_printf("%s: No match.\n", globuffer.gl_pathv[0]);
}

glob_t	globuffer_arg(glob_t globuffer, char **array, int index)
{
	if (index != 0)
		globuffer.gl_offs = arg_nbr(array, 0) + 1;
	else
		globuffer.gl_offs = 0;
	return (globuffer);
}

void	star_handle(char **array, char **env, env_st_t *env_st)
{
	int index;
	glob_t globuffer;

	array = array_star_sort(array);
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
