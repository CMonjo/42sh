/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** concat string each other
*/

#include "my.h"
#include <stdlib.h>

char	*my_strcat(char *dest, char *src, int b)
{
	char *temp;
	int ct = 0;
	int ctb = 0;

	temp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
	while (ct < (my_strlen(dest) + my_strlen(src) + 1)) {
		if (ct == my_strlen(dest)) {
			b ++;
			ctb = 0;
		}
		if (b == 0)
			temp[ct] = dest[ctb];
		if (b == 1)
			temp[ct] = src[ctb];
		ct ++;
		ctb ++;
	}
	temp[my_strlen(dest) + my_strlen(src)] = '\0';
	return (temp);
}