/*
** EPITECH PROJECT, 2018
** other.c
** File description:
** other function for the mini shell
*/

#include "tools.h"

char	*copy_str_arr(char *line, int *ct)
{
	int len = 0;
	char *str;
	int ctp = 0;

	for (int ctp = *ct; line[ctp] != 32 && line[ctp] != 9
	&& line[ctp] != '\0' && line[ctp] != 39 && line[ctp] != 34; ctp ++)
		len ++;
	str = malloc(sizeof(char) * (len + 1));
	for (; line[*ct] != 32 && line[*ct] != 9 && line[*ct] != '\0'
	&& line[*ct] != 39 && line[*ct] != 34; (*ct) ++, ctp ++)
		str[ctp] = line[*ct];
	str[ctp] = '\0';
	return (str);
}

char	*copy_str_quote(char *line, int *ct, char c)
{
	int len = 2;
	char *str;

	for (int ctb = ((*ct) + 1); line[ctb] != c
	&& line[ctb] != '\0'; ctb ++)
		len ++;
	str = malloc(sizeof(char) * (len + 1));
	str[0] = line[*ct];
	(*ct) ++;
	for (int ctb = 1; line[*ct] != c
	&& line[*ct] != '\0'; ctb ++, (*ct) ++)
		str[ctb] = line[*ct];
	str[len - 1] = line[*ct];
	str[len] = '\0';
	(*ct) ++;
	return (str);
}

int	len_str(char *str)
{
	int ct = 0;
	int len = 1;
	int b = 0;

	while (str[ct] != '\0') {
		if (str[ct] == 39 || str[ct] == 34) {
			len ++;
			pass_quotes(str, &ct, str[ct]);
		}

		if (b == 0 && (str[ct] == 32 || str[ct] == 9)) {
			len ++;
			b = 1;
		}
		if (str[ct] != 32 && str[ct] != 9)
			b = 0;
		ct ++;
	}
	return (len);
}

int	empty_str(char *str)
{
	int ct = 0;
	int len = 1;
	int b = 0;

	while (str[ct] != '\0') {
		if (b == 0 && (str[ct] == 32 || str[ct] == 9)) {
			b = 1;
		}
		if (str[ct] != 32 && str[ct] != 9) {
			len ++;
			b = 0;
		}
		ct ++;
	}
	return (len);
}

char	**word_array(char *line)
{
	int ct = 0;
	int ctb = 0;
	char **str;

	if (empty_str(line) == 0)
		return (NULL);
	str = malloc(sizeof(char *) * (len_str(line) + 1));
	while (line[ct] != '\0') {
		if (line[ct] != 32 && line[ct] != 9) {
			str[ctb] = copy_str_arr(line, &ct);
			ctb ++;
		}
		if (line[ct] == 39 || line[ct] == 34) {
			str[ctb] = copy_str_quote(line, &ct, line[ct]);
			ctb ++;
		} else if (line[ct] != '\0')
			ct ++;
	}
	str[ctb] = NULL;
	return (str);
}
