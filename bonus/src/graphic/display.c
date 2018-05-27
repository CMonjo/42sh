/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** src/display.c
*/

#include "graph.h"

void	print_result(info_t *info, FILE *file)
{
	char *str;
	int i = 25;

	while ((str = my_getline_csfml(file)) != NULL) {
		sfText_setString(info->text, str);
		sfText_setPosition(info->text, (sfVector2f){400, 40 + i});
		sfRenderWindow_drawText(info->window, info->text, NULL);
		i += 25;
	}
	sfRenderWindow_display(info->window);
}

char	*prompt_graph(void)
{
	return (my_strcat_h(getcwd(NULL, 0), "  $> "));
}

void	print_exit(void)
{
	my_printf("exit\n");
	exit(0);
}

void	display_clear(info_t *info)
{
	sfRenderWindow_display(info->window);
	sfRenderWindow_clear(info->window, sfBlack);
}

void	display_sprite_list(info_t *info, sprite_t *sprite_list, char *line)
{
	for (; sprite_list != NULL; sprite_list = sprite_list->next)
		sfRenderWindow_drawSprite(info->window, sprite_list->sprite,
		NULL);
	sfText_setString(info->text, line);
	sfRenderWindow_drawText(info->window, info->text, NULL);
}
