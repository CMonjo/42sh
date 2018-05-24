/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/variables/variables_spe.c
*/

#include "main.h"

char	*value_return(char *str, env_st_t *env_st)
{
	return (int_to_char(env_st->status));
}

char	*get_pid(char *str, env_st_t *env_st)
{
	return (int_to_char(getpid()));
}