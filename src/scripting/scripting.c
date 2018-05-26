/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/scripting/scripting.c
*/

#include "main.h"

int	check_sheebang(char *str, char *file, env_st_t* env_st)
{
	int len_sheebang = 0;
	char *sheebang;
	int ctb = 0;
	int start = 1;

	if (my_strlen(str) > 2 && str[1] == '!')
		start ++;
	len_sheebang = check_sheebang_next(len_sheebang, str, start);
	sheebang = malloc(sizeof(char) * (len_sheebang + 1));
	for (int ct = start; str[ct] != '\0' && str[ct] != ' '; ct ++, ctb ++)
		sheebang[ctb] = str[ct];
	sheebang[len_sheebang] = '\0';
	if (access(sheebang, F_OK) == -1) {
		my_printf("%s: Command not found.\n", file);
		return (1);
	}
	if (check_sheebang_file(word_array(str), str,
	len_sheebang + start, env_st) == 1)
		return (1);
	return (0);
}

void	start_exec_script(char **arr, FILE *fd, env_st_t* env_st)
{
	int line = 1;
	size_t size = 0;
	char *str = NULL;
	int readed = 0;

	while ((readed = getline(&str, &size, fd)) > 0) {
		str[readed] = '\0';
		if (my_strlen(str) > 1) {
			str = replace_variable(str, arr);
			main_b_tree(str, env_st, 0, 1);
		}
		line ++;
	}
}

int	check_elf(char *str, char **arr, FILE *fd, env_st_t* env_st)
{
	if (my_strlen(str) >= 4 && str[1] == 'E'
	&& str[2] == 'L' && str[3] == 'F')
		return (0);
	else if (str[0] == '#' && check_sheebang(str, arr[0], env_st) == 1)
		return (1);
	if (my_strlen(str) >= 1 && str[0] != '#') {
		str = replace_variable(str, arr);
		main_b_tree(str, env_st, 0, 1);
	}
	start_exec_script(arr, fd, env_st);
	return (1);
}

int	scripting(char **arr, char **arr_val,
UNUSED char **envp, UNUSED env_st_t* env_st)
{
	int fd = 0;
	size_t size = 0;
	char *str = NULL;
	int readed = 0;
	FILE *fd_script = 0;

	fd = open(arr[0], O_RDONLY);
	if (fd == -1)
		return (1);
	fd_script = fdopen(fd, "rw");
	readed = getline(&str, &size, fd_script);
	if (readed <= 0)
		return (0);
	str[readed - 1] = '\0';
	if (readed > 1 && check_elf(str, arr_val, fd_script, env_st) == 1)
		return (1);
	return (0);
}