/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/jobs/jobs.c
*/

#include "main.h"

int	jobs(char **arr, UNUSED char **envp, UNUSED env_st_t *env_st)
{
	if (isatty(0) != 1) {
		env_st->status = 1;
		my_putstr_err(arr[0], "No job control in this shell.\n");
	} else {
		env_st->status = 1;
		my_putstr_err(arr[0], ": No current job.\n");
	}
	return (0);
}