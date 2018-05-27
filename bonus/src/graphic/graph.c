/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** src/main.c
*/

#include "graph.h"

char	*my_strcat_h(char *str1, char *str2)
{
	char *new = malloc(sizeof(char) * (my_strlen(str1) +
	my_strlen(str2) + 1));
	int i = 0;

	for (; str1 != NULL && str1[i] != '\0'; i++)
		new[i] = str1[i];
	for (int u = 0; str2 != NULL && str2[u] != '\0'; i++, u++)
		new[i] = str2[u];
	new[i] = '\0';
	return (new);
}

char	*my_getline_csfml(FILE *fd)
{
	size_t size = 0;
	char *str = NULL;
	int readed = 0;

	if (fd == NULL)
		return (NULL);
	readed = getline(&str, &size, fd);
	if (readed <= 0) {
		return (NULL);
	}
	str[readed - 1] = '\0';
	return (str);
}

sfText	*text_creation(char *str, sfFont *font, int size, sfVector2f position)
{
	sfText *text = sfText_create();

	sfText_setString(text, str);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, size);
	sfText_setPosition(text, position);
	return (text);
}

void	close_window(sfRenderWindow *window, sfEvent event)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
	}
}

int	main_graph(char **envp)
{
	info_t *info = info_init();
	sprite_t *sprite_list = sprite_list_init();
	int return_value;

	return_value = main_loop_graph(info, envp, 0, sprite_list);
	sfMusic_destroy(info->music);
	return (return_value);
}