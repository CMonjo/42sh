/*
** EPITECH PROJECT, 2017
** PSU_tetris_2017
** File description:
** src/my_arraydup.c
*/

#include "main.h"

int	array_len(char **array)
{
	int i = 0;

	if (array == NULL)
		return (0);
	for (; array[i] != NULL; i++);
	return (i);
}

char	**my_arraydup(char **array)
{
	int i = 0;
	char **new = malloc(sizeof(char *) * (array_len(array) + 1));

	if (array == NULL) {
		free(new);
		return (NULL);
	}
	for (; array[i] != NULL; i++)
		new[i] = array[i];
	new[i] = NULL;
	return (new);
}