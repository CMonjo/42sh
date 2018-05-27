/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** include/graph.h
*/

#include "main.h"

#ifndef GRAPH_H_
	#define GRAPH_H_

	#include <SFML/Window.h>
	#include <SFML/System.h>
	#include <SFML/Audio.h>
	#include <SFML/Graphics.h>

	typedef	enum	type_s {
		BG,
		RETRO,
	} type_t;

	typedef	struct	sprite_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfVector2f position;
		type_t type;
		struct sprite_s *next;
	} sprite_t;

	typedef struct info_s {
		sfRenderWindow *window;
		sfEvent event;
		sfMusic *music;
		sfFont *font;
		sfText *text;
		char *str;
	} info_t;

	int	main_graph(char **envp);
	env_st_t	*init_env_struct(char **envp);
	void	display_sprite_list(info_t *info, sprite_t *sprite_list,
	char *line);
	void	display_clear(info_t *info);
	void	print_exit(void);
	char	*prompt_graph(void);
	void	print_result(info_t *info, FILE *file);
	int	main_graph(char **envp);
	void	close_window(sfRenderWindow *window, sfEvent event);
	sfText	*text_creation(char *str, sfFont *font, int size,
	sfVector2f position);
	char	*my_getline_csfml(FILE *fd);
	char	*my_strcat_h(char *str1, char *str2);
	info_t	*info_init(void);
	sprite_t	*sprite_list_init(void);
	void	put_list_sprite(sprite_t **sprite, char *path,
	sfVector2f position);
	int	main_loop_graph(info_t *info, char **envp, int end,
	sprite_t *sprite_list);
	void	end_main_loop(int fd, info_t *info, FILE *file, sfEvent event);
	void	main_loop_dup(env_st_t *env_st, int fd);
	FILE	*pre_new_command(char *path, FILE *file, info_t *info,
	sprite_t *sprite_list);
	void	new_command(info_t *info, sprite_t *sprite_list);
	int	type(info_t *info);
	void	type_close(info_t *info, sfEvent event);
	char	*remove_char(char *str);
	char	*add_char(char *str, char c);
#endif