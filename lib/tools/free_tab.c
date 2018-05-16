/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** src/MD5/free_tab.c
*/

#include "tools.h"
#include <unistd.h>
#include <stdlib.h>

void free_tab(char **tab)
{
	for (int ct = 0; tab[ct] != NULL; ct ++)
		free(tab[ct]);
	free(tab);
}