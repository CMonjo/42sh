/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** create a maloc for arg
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	my_strcpy(dest, src);
	return (dest);
}
