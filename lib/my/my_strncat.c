/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** strcat the func same as cat
*/

char	*my_strncat(char *dest, char const *src,int nb)
{
	int c = 0;
	int b = 0;

	while (dest[c] != '\0') {
		c = c + 1;
	}
	while (b < nb) {
		dest[c] = src[b];
		b = b + 1;
		c = 1 + c;
	}
	dest[c] = '\0';
	return (dest);
}
