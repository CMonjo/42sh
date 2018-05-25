/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** main.c
*/

#include "main.h"

int	len_tab_not_one(char **arr)
{
	int i = 1;
	int len = 0;

	while (arr[i] != NULL) {
		len = my_strlen(arr[i]) + len;
		i = i + 1;
		len = len + 1;
	}
	return (len);
}

char	*rm_first_arr(char **arr)
{
	int len = len_tab_not_one(arr);
	char *str = malloc(sizeof(char) * len);
	int i = 0;
	int w = 1;
	int y = 0;

	while (arr[y] != NULL) {
		str[i] = arr[y][w];
		i = i + 1;
		w = w + 1;
		if (arr[y][w] == '\0' && arr[y + 1] != NULL) {
			w = 0;
			y = y + 1;
			str[i] = ' ';
			i = i + 1;
		}
	}
	str[i] = '\0';
	free_tab(arr);
	return (str);
}