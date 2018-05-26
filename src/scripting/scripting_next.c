/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/scripting/scripting.c
*/

#include "main.h"

int	arr_len(char **arr)
{
	int i = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		i = i + 1;
	return (i);
}

int	sheebang_next_two(int file_len, char *str, int sheebang_len)
{
	for (int ct = sheebang_len; str[ct] != '\0'; ct ++)
		file_len ++;
	return (file_len);
}

int	sheebang_next(int sheebang_len, char *str)
{
	for (int ct = sheebang_len; str[ct] == '\t' || str[ct] == ' '; ct ++)
		sheebang_len ++;
	return (sheebang_len);
}

int	check_sheebang_next(int len_sheebang, char *str, int start)
{
	for (int ct = start; str[ct] != '\0' && str[ct] != ' '; ct ++)
		len_sheebang ++;
	return (len_sheebang);
}