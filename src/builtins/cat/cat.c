/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for the cd func
*/

#include "main.h"

char	*cat_file(FILE *fd)
{
	size_t size = 0;
	char *file = NULL;
	char *grep_file = malloc(sizeof(char) * 1);
	int readed = 0;

	grep_file[0] = '\0';
	while ((readed = getline(&file, &size, fd)) > 0)
		grep_file = my_strcat(grep_file, file, 0);
	return (grep_file);
}

int	cat_bis(char **arr, UNUSED char **envp, UNUSED env_st_t *env_st)
{
	char *grep_file_dis = '\0';
	char *grep_file_more = "\0";
	FILE *fd;

	for (int ct = 1; arr[ct] != NULL; ct ++) {
		if ((fd = fopen(arr[ct], "rw")) != NULL)
			grep_file_dis = cat_file(fd);
		else {
			grep_file_dis = my_strcat(grep_file_dis, "cat: ", 0);
			grep_file_dis = my_strcat(grep_file_dis, arr[ct], 0);
			grep_file_dis = my_strcat(grep_file_dis
			, ": No such file or directory.\n", 0);
		}
		grep_file_more = my_strcat(grep_file_more, grep_file_dis, 0);
	}
	if (grep_file_more[0] != '\0')
		my_printf("%s", grep_file_more);
	return (0);
}

int	cat(char **arr, UNUSED char **envp, UNUSED env_st_t *env_st)
{
	cat_bis(arr, envp, env_st);
	return (0);
}
