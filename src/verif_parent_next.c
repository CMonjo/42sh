/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** main.c
*/

#include "main.h"

char	*verif_parent(char *str, int ct)
{
	int a = 0;
	int b = 0;

	a = verif_parent_next(str, ct);
	b = verif_parent_next_rev(str, ct);
	if (str[a + 2] == '(' && str[b - 2] == ')') {
		str = rm_char(str, a);
		str = rm_char(str, a);
		str = rm_char(str, b - 2);
		str = rm_char(str, b - 3);
	}
	return (str);
}

char	*too_much_parent(char *str)
{
	int ct = nb_char_in_str(str, '(');

	if (ct == 0 || ct == 1)
		return (str);
	while (1 != ct) {
		str = verif_parent(str, 1);
		ct = ct - 1;
	}
	return (str);
}