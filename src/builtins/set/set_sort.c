/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set set in the sheel
*/

#include "main.h"

int	sort_alpha_set(set_t *h1, set_t *h2)
{
	int i = 0;

	while (h1->name[i] != '\0' || h2->name[i] != '\0') {
		if (h1->name[i] > h2->name[i])
			return (1);
		if (h1->name[i] < h2->name[i])
			return (0);
		i = i + 1;
	}
	if (my_strlen(h1->name) > my_strlen(h2->name))
		return (1);
	else
		return (0);
}

int	sort_or_not_set(set_t *tmp)
{
	set_t *current = tmp;

	while (current->next != NULL) {
		if (sort_alpha_set(current, current->next) == 1)
			return (1);
		current = current->next;
	}
	return (0);
}

set_t	*swap_bubble_set(set_t *current)
{
	char *tmp_name = current->name;
	char *tmp_value = current->value;
	int tmp_active = current->active;

	current->name = current->next->name;
	current->value = current->next->value;
	current->active = current->next->active;
	current->next->name = tmp_name;
	current->next->value = tmp_value;
	current->next->active = tmp_active;
	return (current);
}

void	my_bubble_set(set_t *current)
{
	printf("rentre\n");
	if (sort_or_not_set(current) == 0)
		return;
	while (current->next != NULL) {
		if (sort_alpha_set(current, current->next) == 1) {
			current = swap_bubble_set(current);
		}
		current = current->next;
	}

}