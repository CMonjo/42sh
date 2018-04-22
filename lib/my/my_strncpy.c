/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** copy the string with the number you want
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int nb)
{
	int i = 0;

	while (i != nb) {
		dest[i] = src[i];
		i = i + 1;
	}
	return (dest);
}
