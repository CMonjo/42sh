/*
** EPITECH PROJECT, 2017
** my_swap.c
** File description:
** my_swap int char others
*/

int	my_swap(int *a, int*b)
{
	int c = *a;

	*a = *b;
	*b = c;
	return (0);
}
