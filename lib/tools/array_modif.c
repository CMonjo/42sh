/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** lib/tools/array_modif.c
*/

#include "main.h"

int	my_arraylen(char **array)
{
	int i = 0;

	for (; array != NULL && array[i] != NULL; i++);
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