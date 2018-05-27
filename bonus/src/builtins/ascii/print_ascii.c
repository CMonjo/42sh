/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/print_ascii.c
*/

#include "main.h"

void	print_ascii_array(char **face, int y)
{
	int i = 0;

	for (; face != NULL && face[i] != NULL; i++)
		if (y + i > 0)
			mvprintw(y + i, 0, face[i]);
}

void	print_ascii(FILE *fd)
{
	char **face = recup_face(fd);
	int pos[2];

	if (face == NULL)
		return;
	initscr();
	noecho();
	getmaxyx(stdscr, pos[0], pos[1]);
	while (pos[0] > -20) {
		refresh();
		if (clock_func() == 1) {
			clear();
			pos[0] -= 1;
			print_ascii_array(face, pos[0]);
		}
	}
	endwin();
}