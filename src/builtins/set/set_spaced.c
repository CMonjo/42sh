/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

char *set_parsing_spaced(char *set_value, char *str)
{
	for (int i = 0, j = 0; str[i] != '\0'; i++) {
		if (str[i] != 39 && str[i] != 34) {
			set_value[j] = str[i];
			j++;
		}
	}
	return (set_value);
}

void set_parse_spaces(env_st_t *env_st, char *str, char *spaced)
{
	int i = 0;
	char *set_name = my_calloc(sizeof(char) * (my_strlen(str) + 1));
	char *set_value = my_calloc(sizeof(char) *
	(my_strlen(str) + my_strlen(spaced) + 1));

	for (i = 0; str[i] != 0; i++)
		set_name[i] = str[i];
	if (set_isalpha(env_st, set_name) == 0)
		return;
	set_value = my_strdup(set_parsing_spaced(set_value, spaced));
	set_fill(env_st, set_name, set_value);
}