/*
** EPITECH PROJECT, 2017
** arrows.c
** File description:
** arrows_handle.c
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
