/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/remove_parent.c
*/

#include "main.h"

void	skip_parent_command(char *command, int *ctb)
{
	int nb_parent = 0;
	int nb_parent_out = 0;

	for (int ct = 0; command[ct] != '\0'; ct ++) {
		if (command[ct] == ')')
			break;
		if (command[ct] == '(')
			nb_parent ++;
	}
	(*ctb) ++;
	while (nb_parent_out != nb_parent) {
		if (command[*ctb] == ')')
			nb_parent_out ++;
		(*ctb) ++;
	}
}

int	count_parent(char *av, int nb_parent_out_old, int ctb, int b)
{
	int nb_parent = 0;
	int nb_parent_out = 0;

	for (int ct = 0; b == 0 && av[ct] != '\0'; ct ++) {
		if (av[ct] == ')')
			break;
		if (av[ct] == '(')
			nb_parent ++;
	}
	if (b == 0)
		return (nb_parent);
	if (av[ctb] == ')')
		nb_parent_out ++;
	return (nb_parent_out_old + nb_parent_out);
}

void	remove_parent_command(char *command, char *av, char sep, int len)
{
	int nb_parent = count_parent(av, 0, 0, 0);
	int nb_parent_out = 0;
	int b = 0;
	int ctb = 0;

	for (int ct = 0; av[ct] != sep; ct ++) {
		nb_parent_out = count_parent(av, nb_parent_out, ct, 1);
		if (nb_parent_out > 0 && nb_parent_out == nb_parent)
			break;
		if (av[ct] == '(' && b == 0)
			b ++;
		else {
			command[ctb] = av[ct];
			ctb ++;
		}
	}
	command[len] = '\0';
}