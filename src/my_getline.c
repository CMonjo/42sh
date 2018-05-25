/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/my_getline.c
*/

#include "main.h"

char	*my_getline(void)
{
	size_t size = 0;
	char *str = NULL;
	int readed = 0;

	readed = getline(&str, &size, stdin);
	if (readed <= 0) {
		return (NULL);
	}
	str[readed - 1] = '\0';
	return (str);
}