/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/if/if_comp.c
*/

#include "main.h"

int	if_no_equal(char *str_one, char *str_two)
{
	if (my_strcmp(str_one, str_two) != 0)
		return (0);
	return (1);
}