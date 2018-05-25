/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/exec_status.c
*/

#include "main.h"

int	status_bis(int w, env_st_t* env_st)
{
	if (SIGFPE == WTERMSIG(w)) {
		my_printf("Floating exception");
		if (WCOREDUMP(w))
			my_printf(" (core dumped)");
		my_printf("\n");
		env_st->status = 136;
		return (136);
	}
	if (WIFSIGNALED(w)) {
		my_printf("Segmentation fault");
		if (WCOREDUMP(w))
			my_printf(" (core dumped)");
		my_printf("\n");
		env_st->status = 139;
		return (139);
	}
	return (1);
}

int	status(int w, env_st_t* env_st)
{
	if ((w % 255) == 1) {
		env_st->status = 1;
		return (0);
	}
	if ((w % 255) == 2) {
		env_st->status = 2;
		return (0);
	}
	return (status_bis(w, env_st));
}