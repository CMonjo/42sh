/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for the cd func
*/

#include "my.h"

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

char	*strcat_grep(char *grep_file, int boul, int b, char* path, char *file)
{
	if (b == 1 && boul == 0) {
			grep_file = my_strcat(grep_file, file, 0);
	} else if (b == 1 && boul == 1 ) {
		grep_file = my_strcat(grep_file, path, 0);
		grep_file = my_strcat(grep_file, ":", 0);
		grep_file = my_strcat(grep_file, file, 0);
	}
	return (grep_file);
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
		grep_file = strcat_grep(grep_file, boul, b, path, file);
		b = 0;
	}
	return (grep_file);
}
int	grep(char **arr, char **envp, env_st_t *env_st)
{
	int tab_len = 0;
	char *grep_file_dis;
	char *grep_file_more = "\0";
	FILE *fd;

	while (arr[tab_len] != NULL)
		tab_len ++;
	if (tab_len == 1) {
		my_printf("PLease put a file and something to find\n");
		return (1);
	}
	if (tab_len == 2)
		while (1)
			printf("PAS DE CHANCE");
	for (int ct = 2; arr[ct] != NULL; ct ++) {
		if (tab_len > 3)
			if ((fd = fopen(arr[ct], "rw")) != NULL)
				grep_file_dis = grep_file(arr[ct], arr[1], 1, fd);
			else {
				grep_file_dis = my_strcat(grep_file_dis, "grep: ", 0);
				grep_file_dis = my_strcat(grep_file_dis, arr[ct], 0);
				grep_file_dis = my_strcat(grep_file_dis, ": No such file or directory.\n", 0);
			}
		else
			if ((fd = fopen(arr[ct], "rw")) != NULL)
				grep_file_dis = grep_file(arr[ct], arr[1], 0, fd);
			else {
				grep_file_dis = my_strcat(grep_file_dis, "grep: ", 0);
				grep_file_dis = my_strcat(grep_file_dis, arr[ct], 0);
				grep_file_dis = my_strcat(grep_file_dis, ": No such file or directory.\n", 0);
			}
		grep_file_more = my_strcat(grep_file_more, grep_file_dis, 0);
	}
	if (grep_file_more[0] != '\0')
		my_printf("%s", grep_file_more);
	return (0);
}