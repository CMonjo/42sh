/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/ascii.c
*/


#include <string.h>
#include "main.h"

int	clock_func(void)
{
	static int nbr = 0;

	nbr += 1;
	if (nbr > 20000) {
		nbr = 0;
		return (1);
	}
	return (0);
}

char	*my_getline_file(FILE *fd)
{
	size_t size = 0;
	char *str = NULL;
	int readed = 0;

	readed = getline(&str, &size, fd);
	if (readed <= 0) {
		return (NULL);
	}
	str[readed - 1] = '\0';
	return (str);
}

char	**recup_face(FILE *fd)
{
	char **face = NULL;
	char *str;

	while ((str = my_getline_file(fd)) != NULL) {
		face = add_line(face, str, my_arraylen(face));
		if (face == NULL)
			return (NULL);
	}
	return (face);
}

int	ascii(char **array, UNUSED char **envp, env_st_t *env_st)
{
	char *faces[4] = {"marlon", "thibault", "karim", "edouart"};
	char *path;
	int i = 0;
	FILE *fd = NULL;

	for (; i != 4; i++) {
		if (array[1] != NULL && my_strcmp(array[1], faces[i]) == 0) {
			path = concat_alias("./data/ascii/", faces[i]);
			fd = fopen(path, "r");
			break;
		}
	}
	if (fd == NULL) {
		env_st->status = 1;
		printf("File not found !\n");
		return (1);
	}
	print_ascii(fd);
	fclose(fd);
	return (0);
}