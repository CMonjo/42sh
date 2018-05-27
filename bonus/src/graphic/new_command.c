/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** src/new_command.c
*/

#include "graph.h"

void	new_command(info_t *info, sprite_t *sprite_list)
{
	info->str = NULL;
	char *line;

	sfText_setPosition(info->text, (sfVector2f){400, 40});
	while (type(info) != 1 &&
	sfRenderWindow_isOpen(info->window) == sfTrue) {
		line = my_strcat_h(prompt_graph(), info->str);
		display_clear(info);
		display_sprite_list(info, sprite_list, line);
	}
	if (info->str == NULL) {
		info->str = malloc(sizeof(char));
		info->str[0] = '\0';
	}
}

FILE	*pre_new_command(char *path, FILE *file, info_t *info,
sprite_t *sprite_list)
{
	file = fopen(path, "w+");
	display_clear(info);
	new_command(info, sprite_list);
	return (file);
}