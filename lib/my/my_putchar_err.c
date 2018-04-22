/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** its my print char
*/

#include<unistd.h>

void	my_putchar_err(char c)
{
	write(2, &c, 1);
}
