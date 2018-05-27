/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** src/type.c
*/

#include "graph.h"

char	*add_char(char *str, char c)
{
	unsigned int i;
	char *new = malloc(sizeof(char) * (my_strlen(str) + 2));

	for (i = 0; str != NULL && str[i] != '\0'; i++)
		new[i] = str[i];
	new[i] = c;
	new[i + 1] = '\0';
	free(str);
	return (new);
}

char	*remove_char(char *str)
{
	unsigned int i;
	char *new = malloc(sizeof(char) * my_strlen(str));

	for (i = 0; str[i + 1] != '\0'; i++)
		new[i] = str[i];
	new[i] = '\0';
	free(str);
	return (new);
}

void	type_close(info_t *info, sfEvent event)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(info->window);
}

int	type(info_t *info)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(info->window, &event)) {
		if (sfEvtTextEntered == event.type && (event.key.code !=
		sfKeyReturn || event.key.code == ':') && (event.key.code !=
		sfKeyBack || event.key.code == ';'))
			info->str = add_char(info->str, event.key.code);
		else if (event.key.code == sfKeyBack && info->str != NULL &&
		my_strlen(info->str) != 0)
			info->str = remove_char(info->str);
		else if (event.key.code == sfKeyReturn)
			return (1);
		type_close(info, event);
	}
	return (0);
}