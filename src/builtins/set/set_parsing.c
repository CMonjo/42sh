/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

int	set_isalpha(env_st_t *env_st, char const *str)
{
	int i = 0;

	if ((str[i] <= 'z' && str[i] >= 'a') ||
	(str[i] <= 'Z' && str[i] >= 'A'))
		return (1);
	else {
		my_printf("set: Variable name must begin with a letter.\n");
		env_st->err = 1;
		return (0);
	}
}

void set_parse(env_st_t *env_st, char *str)
{
	int set = 0;
	int i = 0;
	char *set_name = my_calloc(sizeof(char) * (my_strlen(str) + 1));
	char *set_value = my_calloc(sizeof(char) * (my_strlen(str) + 1));

	for (i = 0; str[i] != 0; i++) {
		if (str[i] == '=') {
			set = 1;
			break;
		}
		set_name[i] = str[i];
	}
	if (set_isalpha(env_st, set_name) == 0)
		return;
	if (set == 1) {
		for (int j = 0, k = i + 1; str[k] != '\0'; k++, j++)
			set_value[j] = str[k];
	}
	set_fill(env_st, set_name, set_value);
}