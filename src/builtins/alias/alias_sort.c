/*
** EPITECH PROJECT, 2018
** alias.c
** File description:
** set alias in the sheel
*/

#include "main.h"

int	sort_alpha(alias_t *h1, alias_t *h2)
{
	int i = 0;

	while (h1->bind[i] != '\0' || h2->bind[i] != '\0') {
		if (h1->bind[i] > h2->bind[i])
			return (1);
		if (h1->bind[i] < h2->bind[i])
			return (0);
		i = i + 1;
	}
	if (my_strlen(h1->bind) > my_strlen(h2->bind))
		return (1);
	else
		return (0);
}

int	sort_or_not(alias_t *tmp)
{
	alias_t *current = tmp;

	while (current->next != NULL) {
		if (sort_alpha(current, current->next) == 1)
			return (1);
		current = current->next;
	}
	return (0);
}

alias_t	*swap_bubble(alias_t *current)
{
	char *tmp_bind = current->bind;
	char *tmp_command_bind = current->command_bind;
	char *tmp_command_display = current->command_display;
	int tmp_active = current->active;

	current->bind = current->next->bind;
	current->command_bind = current->next->command_bind;
	current->command_display = current->next->command_display;
	current->active = current->next->active;
	current->next->bind = tmp_bind;
	current->next->command_bind = tmp_command_bind;
	current->next->command_display = tmp_command_display;
	current->next->active = tmp_active;
	return (current);
}

void	my_bubble(alias_t *current)
{
	alias_t *tmp = current;

	if (sort_or_not(tmp) == 0)
		return;
	while (tmp->next != NULL) {
		if (sort_alpha(tmp, tmp->next) == 1) {
			tmp = swap_bubble(tmp);
		}
		tmp = tmp->next;
	}
	my_bubble(current);
}