/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/print_ascii.c
*/

#include "main.h"

void	print_ascii_array(int y, FILE *fd)
{
	int i = 0;
	char *str;
	rewind(fd);

	str = my_getline_file(fd);
	for (; str != NULL; i++, str = my_getline_file(fd))
		if (y + i > 0)
			mvprintw(y + i, 0, str);
}

void	print_ascii(FILE *fd)
{
	int pos[2];

	initscr();
	noecho();
	getmaxyx(stdscr, pos[0], pos[1]);
	while (pos[0] > -20) {
		refresh();
		if (clock_func() == 1) {
			clear();
			pos[0] -= 1;
			print_ascii_array(pos[0], fd);
		}
	}
	endwin();
}