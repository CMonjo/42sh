/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

char *set_w_full(char *set_value, char *str, int i)
{
	for (int j = 0, k = i + 1; str[i] != '\0'
	&& str[k] != '\0'; k++, j++) {
		if (str[k] != 39 && str[k] != 34)
			set_value[j] = str[k];
	}
	return (set_value);
}

char *set_w_quotes(env_st_t *env_st, char *set_value, char *quote)
{
	for (int i = 0, j = 0; quote[i] != '\0'; i++) {
		if (quote[i] != 39 && quote[i] != 34) {
			set_value[j] = quote[i];
			j++;
		}
	}
	env_st->set_array = 1;
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
	if (set == 1 && quote != NULL && (quote[0] == 39 || quote[0] == 34))
		set_value = my_strdup(set_w_quotes(env_st, set_value, quote));
	else
		set_value = my_strdup(set_w_full(set_value, str, i));
	set_fill(env_st, set_name, set_value);
}

void set_check_array(env_st_t *env_st, char **array, int i)
{
	if (array[i + 1] != NULL && array[i + 1][0] == '=') {
		set_parse_spaces(env_st, array[i], array[i + 2]);
		env_st->set_array = 2;
	}
	else
		set_parse(env_st, array[i], array[i + 1]);
}