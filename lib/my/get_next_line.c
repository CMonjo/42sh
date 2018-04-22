/*
** EPITECH PROJECT, 2018
** GNL.c
** File description:
** getnextline function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include <fcntl.h>

int	line_n_len(char *file, int boul, int ct)
{
	while (boul == 0 && file[ct] != '\0') {
		if (file[ct] == '\n')
			return (1);
		ct ++;
	}
	if (boul == 0)
		return (0);
	while (boul == 1 && file[ct] != '\0')
		ct ++;
	if (boul == 1)
		return (ct);
	if (boul == 3) {
		while (file[ct] != '\n' && file[ct] != '\0')
			ct ++;
		return (ct + 1);
	}
	return (0);
}

char	*my_strcat(char *dest, char *src, int b)
{
	char *temp;
	int ctp = 0;
	int ctb = 0;

	CHECK_MALLOC(temp, line_n_len(dest, 1, 0) + line_n_len(src, 1, 0) + 1);
	while (ctp < (line_n_len(dest, 1, 0) + line_n_len(src, 1, 0) + 1)) {
		if (ctp == line_n_len(dest, 1, 0)) {
			b ++;
			ctb = 0;
		}
		if (b == 0)
			temp[ctp] = dest[ctb];
		if (b == 1)
			temp[ctp] = src[ctb];
		ctp ++;
		ctb ++;
	}
	temp[line_n_len(dest, 1, 0) + line_n_len(src, 1, 0)] = '\0';
	free(dest);
	return (temp);
}

char	*line(char *str, int ctp, int ctb, int b)
{
	char *str_rst;
	char *str_tp;

	CHECK_MALLOC(str_rst, line_n_len(str, 1, 0) + 1);
	CHECK_MALLOC(str_tp, line_n_len(str, 1, 0) - line_n_len(str, 3, 0) + 1);
	if (b == 1) {
		for (; str[ctp] != '\n' && str[ctp] != '\0'; ctp ++)
			str_rst[ctp] = str[ctp];
		str_rst[ctp] = '\0';
		free(str_tp);
		return (str_rst);
	}
	for (int ct = line_n_len(str, 3, 0); str[ct] != '\0'; ct ++, ctb ++)
		str_tp[ctb] = str[ct];
	str_tp[ctb] = '\0';
	free(str);
	CHECK_MALLOC(str, line_n_len(str_tp, 1, 0) + 1);
	CHECK_STR_FREE;
	return (str);
}

char	*get_line(int fd, char **str)
{
	int end_file = 0;
	char *file;

	CHECK_MALLOC(file, READ_SIZE + 1);
	while ((end_file = read(fd, file, READ_SIZE)) > 0) {
		file[end_file] = '\0';
		*str = my_strcat(*str, file, 0);
		free(file);
		CHECK_MALLOC(file, READ_SIZE + 1);
		CHECK_LINE;

	}
	CHECK_LINE_END;
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char *str;

	if ((str) == NULL) {
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (fd >= 0 && READ_SIZE > 0)
		return (get_line(fd, &str));
	free(str);
	return (NULL);
}
