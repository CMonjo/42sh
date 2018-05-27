/*
** EPITECH PROJECT, 2017
** arrows
** File description:
** arrows
*/

#include "main.h"

void disp_history(history_t *tmp, char *str, int *i, term_t *term)
{
	if (!tmp)
		return;
	for (int j = 0; tmp->command[j] != '\0'; j++) {
		str = my_realloc(str, term, j);
		str[j] = tmp->command[j];
	}
	str = my_realloc(str, term, strlen(tmp->command));
	str[strlen(tmp->command)] = '\0';
	*i = strlen(tmp->command);
	printf("%s", tmp->command);
}

void del_arrows(term_t *term, char *str, int *i)
{
	term->a = 0;
	term->b = 0;
	if (*i <= 2 || str[*i - 2] != '[')
		return;
	(str[*i - 1] == 67) ? fprintf(stdout, "\e[1D") : 0;
	(str[*i - 1] == 68) ? fprintf(stdout, "\e[1C") : 0;
	term->a = (str[*i - 1] == 65) ? 1 : 0;
	term->b = (str[*i - 1] == 66) ? 1 : 0;
	if (str[*i - 1] == 65 || str[*i - 1] == 66 || str[*i - 1] == 67 ||
	str[*i - 1] == 68) {
		str[*i - 1] = '\0';
		str[*i - 2] = '\0';
		str[*i - 3] = '\0';
		*i = *i - 3;
	}
}

void manage_down_arrow(term_t *term, history_t **tmp, char *str, int *i)
{
	if (term->b == 1) {
		fprintf(stdout, "\e[1A");
		fprintf(stdout, "\e[u");
		fprintf(stdout, "\e[K");
		if (*tmp && (*tmp)->prev) {
			*tmp = (*tmp)->prev;
			disp_history(*tmp, str, i, term);
		} else if (*tmp) {
			str[0] = '\0';
			*i = 0;
			term->histo = 0;
		}
	}
}

void manage_up_arrow(term_t *term, history_t **tmp, char *str, int *i)
{
	if (term->a == 1) {
		fprintf(stdout, "\e[1B");
		fprintf(stdout, "\e[u");
		fprintf(stdout, "\e[K");
		if (tmp && term->histo == 0) {
			disp_history(*tmp, str, i, term);
			term->histo = 1;
		} else if (*tmp && (*tmp)->next) {
			*tmp = (*tmp)->next;
			disp_history(*tmp, str, i, term);
			term->histo = 1;
		} else {
			disp_history(*tmp, str, i, term);
		}
	}
	manage_down_arrow(term, tmp, str, i);
}
