/*
** EPITECH PROJECT, 2017
** my_printf_bis.c
** File description:
** printf with other functions
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char	*copy_flag(char *str, char *temp, int ct)
{
	int len = 0;
	int b = 0;
	char *temp_dup;

	while (b == 0) {
		temp_dup = my_strdup(temp);
		free(temp);
		temp = malloc(sizeof(char) * (len + 2));
		for (int ctb = 0; temp_dup[ctb] != '\0'; ctb ++)
			temp[ctb] = temp_dup[ctb];
		temp[len] = str[ct];
		b = choise_flag(str, ct, b);
		ct ++;
		len ++;
		temp[len] = '\0';
	}
	free(temp_dup);
	return (temp);
}

char	*copy_str(char *str, char *str_temp, int ct)
{
	int b = 0;
	int len = 0;
	int ctp = 0;
	int ctb = ct;

	while (b == 0 || str[ct] != '\0') {
		b = choise_flag(str, ct, b);
		ct ++;
		len ++;
	}
	str_temp = malloc(sizeof(char) * (len + 1));
	while (ctp != len) {
		str_temp[ctp] = str[ctb];
		ctp ++;
		ctb ++;
	}
	str_temp[len] = '\0';
	return (str_temp);
}

int	flag_flag(char *str, int ct)
{
	int b = 0;

	while (b == 0 && str[ct] != 'l' && str[ct] != 'h') {
		ct ++;
		b = choise_flag(str, ct, b);
	}
	return (ct);
}
