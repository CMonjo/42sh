/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** src/main_loop.c
*/

#include "graph.h"

void	main_loop_dup(env_st_t *env_st, int fd)
{
	bash_rc(env_st);
	dup2(fd, 1);
	dup2(fd, 2);
}

void	end_main_loop(int fd, info_t *info, FILE *file, sfEvent event)
{
	lseek(fd, 0, SEEK_SET);
	print_result(info, file);
	while (sfKeyboard_isKeyPressed(sfKeySpace) == sfFalse &&
	sfRenderWindow_isOpen(info->window))
	close_window(info->window, event);
	fclose(file);
}

int	main_loop_graph(info_t *info, char **envp, int end,
sprite_t *sprite_list)
{
	FILE *file;
	char *path = my_strcat_h(getcwd(NULL, 0), "/output");
	int fd = open(path, O_CREAT | O_RDONLY | O_WRONLY | O_TRUNC, 0666);
	env_st_t *env_st = init_env_struct(envp);
	sfEvent event;

	main_loop_dup(env_st, fd);
	while (sfRenderWindow_isOpen(info->window)) {
		file = pre_new_command(path, file, info, sprite_list);
		if (isatty(0) == 1 && info->str == NULL)
			print_exit();
		if (my_strlen(info->str) > 0) {
			main_b_tree(info->str, env_st, 0, 1);
		}
		else if (isatty(0) != 1)
			end = !end;
		end_main_loop(fd, info, file, event);
	}
	return (0);
}