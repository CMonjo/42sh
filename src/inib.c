/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/inib.c
*/

#include "main.h"

char *replace_inib(char *str, int *ct)
{
	int nb_back = 0;
	char *command;
	int ct_str = 0;

	for (int ctb = (*ct); str[ctb] == '\\'; ctb ++)
		nb_back ++;
	\//printf("\nNB BACK : %d      CALCUL   :  %d   CT   :   %d\n", nb_back, (nb_back / 2), (*ct));
	command = malloc(sizeof(char) * (my_strlen(str) + (nb_back / 2) + 1));
	for (int ctb = 0; ct_str != (*ct); ctb ++, ct_str ++)
		command[ct_str] = str[*ct];
	for (int ctb = 0; ctb != (nb_back / 2); ctb ++, ct_str ++)
		command[ct_str] = '\\';
	(*ct) = (*ct) + nb_back;
	for (;str[*ct] != '\0'; (*ct) ++, ct_str ++)
		command[ct_str] = str[*ct];
	command[my_strlen(str) + (nb_back / 2) - 1] = '\0';
	free(str);
	//printf("COMMANDE   :   %s    CT   :   %d\n", command, (*ct));
	return (command);
}

char	*chang_inib(char *str)
{
	for (int ct = 0; str[ct] != '\0'; ct ++)
		if (str[ct] == '\\')
			str = replace_inib(str, &ct);
	//printf("STR : %s\n", str);
	return (str);
}