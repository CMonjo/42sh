/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** src/init.c
*/

#include "graph.h"

void	put_list_sprite(sprite_t **sprite, char *path, sfVector2f position)
{
	sprite_t *element = malloc(sizeof(sprite_t));

	element->sprite = sfSprite_create();
	element->texture = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(element->sprite, element->texture, sfTrue);
	element->position = position;
	sfSprite_setPosition(element->sprite, element->position);
	element->next = *sprite;
	*sprite = element;
}

sprite_t	*sprite_list_init(void)
{
	sprite_t *sprite_list = NULL;
	char *sprite[2] = {"texture/bg.png", "texture/retro.png"};
	sfVector2f pos[2] = {(sfVector2f){0, 0}, (sfVector2f){0, 0}};

	for (int i = 0; i != 2; i++)
		put_list_sprite(&sprite_list, sprite[i], pos[i]);
	return (sprite_list);
}

info_t	*info_init(void)
{
	info_t *info = malloc(sizeof(info_t));

	info->str = NULL;
	info->music = sfMusic_createFromFile("music/ost.ogg");
	info->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
	"shell", sfDefaultStyle, NULL);
	info->font = sfFont_createFromFile("font/retro.otf");
	info->text = text_creation(info->str, info->font,
	20, (sfVector2f){400, 40});
	sfMusic_setLoop(info->music, sfTrue);
	sfMusic_play(info->music);
	return (info);
}