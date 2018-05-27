/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/grep/grep_bis.c
*/

#include "main.h"

char	*grep_file_bis_len(char **arr, int ct)
{
	char *grep_file_dis = '\0';
	FILE *fd;

	if ((fd = fopen(arr[ct], "rw")) != NULL)
		grep_file_dis = grep_file(arr[ct], arr[1], 1, fd);
	else {
		grep_file_dis = my_strcat(grep_file_dis, "grep: ", 0);
		grep_file_dis = my_strcat(grep_file_dis, arr[ct], 0);
		grep_file_dis = my_strcat(grep_file_dis
		, ": No such file or directory.\n", 0);
	}
	return (grep_file_dis);
}

char	*grep_file_bis_else(char **arr, int ct)
{
	char *grep_file_dis = '\0';
	FILE *fd;

	if ((fd = fopen(arr[ct], "rw")) != NULL)
		grep_file_dis = grep_file(arr[ct], arr[1], 0, fd);
	else {
		grep_file_dis = my_strcat(grep_file_dis, "grep: ", 0);
		grep_file_dis = my_strcat(grep_file_dis, arr[ct], 0);
		grep_file_dis = my_strcat(grep_file_dis
		, ": No such file or directory.\n", 0);
	}
	return (grep_file_dis);
}

int	grep_bis(char **arr, UNUSED char **envp,
UNUSED env_st_t *env_st, int tab_len)
{
	char *grep_file_dis;
	char *grep_file_more = "\0";

	for (int ct = 2; arr[ct] != NULL; ct ++) {
		if (tab_len > 3)
			grep_file_dis = grep_file_bis_len(arr, ct);
		else
			grep_file_dis = grep_file_bis_else(arr, ct);
		grep_file_more = my_strcat(grep_file_more, grep_file_dis, 0);
		free(grep_file_dis);
	}
	if (grep_file_more[0] != '\0')
		my_printf("%s", grep_file_more);
	return (0);
}