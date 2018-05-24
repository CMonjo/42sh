/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

int set_deep(char *str)
{
	int i = 1;

	if (str[0] != '=')
		return (1);
	while (str[i] != '\0') {
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
		i += 1;
	}
	return (0);
}

int	set_isalpha(env_st_t *env_st, char const *str)
{
	int i = 0;

	if ((str[i] <= 'z' && str[i] >= 'a') ||
	(str[i] <= 'Z' && str[i] >= 'A') || str[i] == 39 || str[i] == 34)
		return (1);
	else {
		my_printf("set: Variable name must begin with a letter.\n");
		env_st->err = 1;
		env_st->status = 1;
		return (0);
	}
}

char *set_parsing_value(env_st_t *env_st, char *set_value, char *str, char *quote, int i)
{
	if (quote != NULL && (quote[0] == 39 || quote[0] == 34)) {
		for (int i = 0, j = 0; quote[i] != '\0'; i++) {
			if (quote[i] != 39 && quote[i] != 34) {
				set_value[j] = quote[i];
				j++;
			}
		}
		env_st->set_array = 1;
	} else {
		for (int j = 0, k = i + 1; str[k] != '\0'; k++, j++) {
			if (str[k] != 39 && str[k] != 34)
				set_value[j] = str[k];
		}
	}
	return (set_value);
}

void set_parse(env_st_t *env_st, char *str, char *quote)
{
	int set = 0;
	int i = 0;
	char *set_name = my_calloc(sizeof(char) * (my_strlen(str) + 1));
	char *set_value = my_calloc(sizeof(char) *
	(my_strlen(str) + my_strlen(quote) + 1));

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
		set_value = my_strdup(set_parsing_value(env_st, set_value, str, quote, i));
	}
	set_fill(env_st, set_name, set_value);
}