/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** main.c
*/

#include "main.h"

char	*rm_first_arr(char **arr)
{
	char *str = malloc(sizeof(char) * 1);

	str[0] = '\0';
	for (int ct = 1; arr[ct] != NULL; ct ++) {
		str = my_strcat(str, arr[ct], 0);
		if (arr[ct + 1] != NULL)
			str = my_strcat(str, " ", 0);
	}
	free_tab(arr);
	return (str);
}