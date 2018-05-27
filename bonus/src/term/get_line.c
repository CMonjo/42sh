/*
** EPITECH PROJECT, 2017
** arrows
** File description:
** get_line
*/

#include "main.h"

char *my_realloc(char *str, term_t *term, int nbr)
{
	if (nbr >= term->mal - 1) {
		term->mal *= 2;
		str = realloc(str, sizeof(char) * term->mal);
	}
	return (str);
}

int check_tab(char *str)
{
	if (strlen(str) == 1 && str[0] == '\t') {
		str[0] = 'l';
		str[1] = 's';
		str[2] = ' ';
		str[3] = '-';
		str[4] = 'C';
		str[5] = 'F';
		str[6] = '\0';
		putchar('\n');
		return (1);
	}
	return (0);
}

char *my_get_line(term_t *term, char *str, history_t *history)
{
	char c = getchar();
	history_t *tmp = history;

	fprintf(stdout, "\e[s");
	str = (!str) ? malloc(sizeof(char) * term->mal) : str;
	term->histo = 0;
	str[0] = '\0';
	for (int i = 0; c != '\n' && c != '\0'; c = getchar()) {
		putchar(c);
		str[i] = c;
		i++;
		str = my_realloc(str, term, i);
		str[i] = '\0';
		if (check_tab(str) == 1)
			return (str);
		del_arrows(term, str, &i);
		manage_up_arrow(term, &tmp, str, &i);
	}
	putchar('\n');
	return (str);
}
