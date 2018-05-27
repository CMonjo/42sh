/*
** EPITECH PROJECT, 2018
** other.c
** File description:
** other function for the mini shell
*/

#include "tools.h"

char	*malloc_str(int ct, int b, int ctb, char **str)
{
	char *str_tmp = malloc(sizeof(char)
	* (my_strlen(str[1]) + my_strlen(str[2])) + 2);

	while (ctb != (my_strlen(str[1]) + my_strlen(str[2]) + 1)) {
		if (b == 0 && str[1][ct] != '\0') {
			str_tmp[ctb] = str[1][ct];
			ct ++;
		}
		if (b == 0 && str[1][ct] == '\0') {
			ctb ++;
			str_tmp[ctb] = '=';
			b = 1;
			ct = 0;
		} else if (b == 1) {
			str_tmp[ctb] = str[2][ct];
			ct ++;
		}
		ctb ++;
	}
	return (str_tmp);
}
