/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for the cd func
*/

#include "main.h"

void	ckeck_grep(char *file, char *find, int ct, int *b)
{
	int ct_find = 0;

	for (int ctb =ct; find[ct_find] != '\0'; ctb ++) {
		if (file[ctb] == '\0')
			return;
		if (file[ctb] != find[ct_find])
			return;
		ct_find ++;
	}
	(*b) = 1;
}

void	ckeck_file_grep(char *file, char *find, int *b)
{
	for (int ct = 0; file[ct] != '\0'; ct ++)
		if (file[ct] == find[0])
			ckeck_grep(file, find, ct, b);
}

char	*grep_file(char *path, char *find, int boul, FILE *fd)
{
	size_t size = 0;
	char *file = NULL;
	char *grep_file = malloc(sizeof(char) * 1);
	int readed = 0;
	int b = 0;

	grep_file[0] = '\0';
	while ((readed = getline(&file, &size, fd)) > 0) {
		ckeck_file_grep(file, find, &b);
		if (b == 1 && boul == 0) {
			grep_file = my_strcat(grep_file, file, 0);
		} else if (b == 1 && boul == 1) {
			grep_file = my_strcat(grep_file, path, 0);
			grep_file = my_strcat(grep_file, ":", 0);
			grep_file = my_strcat(grep_file, file, 0);
		}
		b = 0;
	}
	return (grep_file);
}

int	grep(char **arr, UNUSED char **envp, UNUSED env_st_t *env_st)
{
	int tab_len = 0;

	while (arr[tab_len] != NULL)
		tab_len ++;
	if (tab_len == 1) {
		my_printf("Please put a file and something to find\n");
		return (1);
	}
	if (tab_len == 2)
		while (1);
	grep_bis(arr, envp, env_st, tab_len);
	return (0);
}
