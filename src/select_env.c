/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** main.c
*/

#include "main.h"

char	*before_egal(char *str)
{
	int i = 0;
	char *dest = malloc(sizeof(char) * my_strlen(str));

	while (str[i] != '=') {
		dest[i] = str[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

int	comp_str_env(char *env, char *str)
{
	char *dest = before_egal(env);

	if (my_strcmp(dest, str) == 0) {
		free (dest);
		return (0);
	}
	free (dest);
	return (1);
}

char	*after_egal(char *str)
{
	int i = 0;
	int w = 0;
	char *dest = malloc(sizeof(char) * my_strlen(str));

	while (str[i] != '=')
		i = i + 1;
	i = i + 1;
	while (str[i] != '\0') {
		dest[w] = str[i];
		i+= 1;
		w += 1;
	}
	dest[w] = '\0';
	return (dest);
}

char	*select_env(char **env, char *str)
{
	int i = 0;

	while (env[i] != NULL) {
		if (comp_str_env(env[i], str) == 0)
			return (after_egal(env[i]));
		i += 1;
	}
	return (NULL);
}