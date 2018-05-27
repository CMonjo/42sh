/*
** EPITECH PROJECT, 2018
** alias.c
** File description:
** set alias in the sheel
*/

#include "main.h"

char	*take_at_char(char *str, char c, int *ct)
{
	char *dest = malloc(sizeof(char) * my_strlen(str) + 1);
	int i = 0;

	while (str[*ct] != c && str[*ct] != '\0') {
		dest[i] = str[*ct];
		i = i + 1;
		*ct = *ct + 1;
	}
	if (str[*ct] != c || i == 0) {
		free(dest);
		return (NULL);
	}
	dest[i] = '\0';
	return (dest);
}

char	*rm_char_simple(char *str, char c)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			str[i] = ' ';
		i = i + 1;
	}
	return (str);
}

char	**alias_in_arr(char *str)
{
	char **dest = NULL;

	str = rm_char_simple(str, '=');
	str = rm_char_simple(str, '"');
	dest = word_array(str);
	return (dest);
}

int	verif_bash_rc(char *str)
{
	char **dest = malloc(sizeof(char*) * 4);
	int ct = 0;

	dest[0] = take_at_char(str, ' ', &ct);
	if (my_strcmp(dest[0], "alias") != 0)
		return (1);
	dest[1] = take_at_char(str, '=', &ct);
	if (dest[1] == NULL)
		return (1);
	dest[2] = take_at_char(str, '\0', &ct);
	if (dest[2] == NULL)
		return (1);
	dest[3] = NULL;
	free_tab(dest);
	return (0);
}

void	bash_rc(env_st_t *env_st)
{
	FILE *fd = 0;
	char *str = NULL;
	char **dest = NULL;

	fd = fopen("./data/alias_rc", "r");
	while (1) {
		str = my_getline_cle(fd);
		if (str == NULL)
			break;
		if (verif_bash_rc(str) == 0) {
			dest = alias_in_arr(str);
			alias(dest, NULL, env_st);
		}
	}
}