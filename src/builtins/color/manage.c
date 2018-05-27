/*
** EPITECH PROJECT, 2018
** prompt
** File description:
** dislplay
*/

#include "main.h"

color_t promptcolor[] = {
	{"black", "\x1b[30m"},
	{"red", "\x1b[31m"},
	{"green", "\x1b[32m"},
	{"yellow", "\x1b[33m"},
	{"blue", "\x1b[34m"},
	{"magenta", "\x1b[35m"},
	{"cyan", "\x1b[36m"},
	{"white", "\x1b[37m"},
};

void init_prompt(env_st_t *env_st)
{
	env_st->prompt = malloc(sizeof(prompt_t));
	for (int i = 0; promptcolor[2].cmd[i] != '\0'; i++) {
		env_st->prompt->clock[i] = promptcolor[2].cmd[i];
		env_st->prompt->path[i] = promptcolor[4].cmd[i];
	}
	env_st->prompt->clock[strlen(promptcolor[2].cmd)] = '\0';
	env_st->prompt->path[strlen(promptcolor[4].cmd)] = '\0';
}

void display_usage(env_st_t *env_st)
{
	env_st->status = 1;
	my_printf("Usage :   color clock/path color\n");
}

void set_color(env_st_t *env_st, char **array, int i)
{
	for (int j = 0; promptcolor[i].cmd[j] != '\0'; j++) {
		(my_strcmp(array[1], "path") == 0) ?
		env_st->prompt->path[j] = promptcolor[i].cmd[j] : 0;
		(my_strcmp(array[1], "clock") == 0) ?
		env_st->prompt->clock[j] = promptcolor[i].cmd[j] : 0;
	}
	(my_strcmp(array[1], "path") == 0) ?
	env_st->prompt->path[strlen(promptcolor[i].cmd)] = '\0' : 0;
	(my_strcmp(array[1], "clock") == 0) ?
	env_st->prompt->clock[strlen(promptcolor[i].cmd)] = '\0' : 0;
}

int color(char **array, UNUSED char **envp, env_st_t *env_st)
{
	if (!array || !array[0] || !array[1] || !array[2] || array[3] ||
	(my_strcmp(array[1], "clock") != 0 &&
	my_strcmp(array[1], "path") != 0)) {
		display_usage(env_st);
		return (0);
	}
	for (int i = 0; i < 8; i++) {
		if (my_strcmp(promptcolor[i].name, array[2]) != 0)
			continue;
			set_color(env_st, array, i);
		env_st->status = 0;
		return (0);
	}
	display_usage(env_st);
	return (0);
}
