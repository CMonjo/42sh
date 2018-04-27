/*
** EPITECH PROJECT, 2018
** other.c
** File description:
** other function for the mini shell
*/

#include "tools.h"

char	*copy_str_arr(char *line, int *ct)
{
	int ctp = *ct;
	int len = 0;
	char *str;

	while (line[ctp] != 32 && line[ctp] != 9 && line[ctp] != '\0') {
		len ++;
		ctp ++;
	}
	ctp = 0;
	str = malloc(sizeof(char) * (len + 1));
	while (line[*ct] != 32 && line[*ct] != 9 && line[*ct] != '\0') {
		str[ctp] = line[*ct];
		ctp ++;
		(*ct) ++;
	}
	str[ctp] = '\0';
	len = 0;
	ctp = 0;
	ct --;
	return (str);
}

char	*copy_str_quote(char *line, int *ct, char c)
{
	int ctp = *ct;
	int len = 0;
	char *str;

	while (line[ctp] != c && line[ctp] != '\0') {
		len ++;
		ctp ++;
	}
	ctp = 0;
	str = malloc(sizeof(char) * (len + 1));
	while (line[*ct] != c && line[*ct] != '\0') {
		str[ctp] = line[*ct];
		ctp ++;
		(*ct) ++;
	}
	(*ct) ++;
	str[ctp] = '\0';
	len = 0;
	ctp = 0;
	return (str);
}

int	epur_str(char *str)
{
	int ct = 0;
	int len = 0;
	int b = 0;

	while (str[ct] != '\0') {
		if (b == 0 && (str[ct] == 32 || str[ct] == 9)) {
			b = 1;
		}
		if (str[ct] != 32 && str[ct] != 9) {
			len ++;
			b =0;
		}
		ct ++;
	}
	return (len);
}

char	**word_array(char *line)
{
	int len = 0;
	int ct = 0;
	int ctb = 0;
	char **str;

	if ((len = epur_str(line)) == 0)
		return (NULL);
	str = malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (line[ct] != '\0') {
		if (line[ct] == 39 || line[ct] == 34) {
			ct ++;
			str[ctb] = copy_str_quote(line, &ct, line[ct - 1]);
			ctb ++;
		} else if (line[ct] != 32 && line[ct] != 9) {
			if (line[ct] == '\\')
				ct ++;
			str[ctb] = copy_str_arr(line, &ct);
			ctb ++;
		} else
			ct ++;
	}
	str[ctb] = NULL;
	return (str);
}
