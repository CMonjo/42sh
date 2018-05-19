/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/jobs/jobs.c
*/

#include "main.h"

int	jobs(char **arr, UNUSED char **envp, UNUSED env_st_t *env_st)
{
	my_putstr_err(arr[0], ": No current job.\n");
	return (0);
}