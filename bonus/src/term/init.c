/*
** EPITECH PROJECT, 2017
** arrows
** File description:
** init
*/

#include "main.h"

int unset_canonic(env_st_t *sh)
{
	sh->term = malloc(sizeof(term_t));
	if (isatty(0) == 0 || tcgetattr(0, &(sh->term->origin)) == -1)
		return (0);
	sh->term->mal = 10;
	if (tcgetattr(0, &(sh->term->tios)) == -1)
		exit(84);
	sh->term->tios.c_lflag &= ~(ICANON | ECHO);
	sh->term->tios.c_cc[VMIN] = 1;
	sh->term->tios.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &(sh->term->tios)))
		exit(84);
	fflush(stdout);
	return (0);
}
