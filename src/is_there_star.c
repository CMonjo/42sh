/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** lib/tools/is_there_star.c
*/

#include "main.h"

int	is_there_star(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		if (str[i] == '*')
			return (1);
	return (0);
}