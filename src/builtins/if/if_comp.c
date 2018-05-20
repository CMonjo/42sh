/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/if/if_comp.c
*/

#include "main.h"

int	if_equal(char *str_one, char *str_two)
{
	//printf("%d\n", my_strcmp(str_one, str_two));
	if (my_strcmp(str_one, str_two) != 0)
		return (1);
	return (0);
}

int	if_equal_sup(char *str_one, char *str_two)
{
	//printf("EQU SUP	 %d\n", my_strcmp(str_one, str_two));
	if (my_strcmp(str_one, str_two) < 0)
		return (1);
	return (0);
}

int	if_equal_inf(char *str_one, char *str_two)
{
	//printf("EQUAL INF %d\n", my_strcmp(str_one, str_two));
	if (my_strcmp(str_one, str_two) > 0)
		return (1);
	return (0);
}

int	if_sup(char *str_one, char *str_two)
{
	printf(" SUP  %d  STR_ONE  %s   STR_TWO   %S\n", my_strcmp(str_one, str_two), str_one, str_two);
	if (my_strcmp(str_one, str_two) <= 0)
		return (1);
	return (0);
}

int	if_inf(char *str_one, char *str_two)
{
	printf(" INF  %d  STR_ONE  %s   STR_TWO   %S\n", my_strcmp(str_one, str_two), str_one, str_two);
	if (my_strcmp(str_one, str_two) >= 0)
		return (1);
	return (0);
}