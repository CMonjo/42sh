/*
** EPITECH PROJECT, 2018
** exit.c
** File description:
** the function of exit
*/

#include "main.h"

int	checking_alpha(char **str, int ct, int *b)
{
	if (str[1][ct] > 47 && str[1][ct] < 58) {
		*b = 1;
	}
	if (*b == 1 && ((str[1][ct] > 64 && str[1][ct] < 91)
		|| (str[1][ct] > 96 && str[1][ct] < 123))) {
		my_printf("exit: Badly formed number.\n");
		return (-1);
	}
	if ((str[1][ct] > 64 && str[1][ct] < 91)
	|| (str[1][ct] > 96 && str[1][ct] < 123)) {
		my_printf("exit: Expression Syntax.\n");
		return (-1);
	}
	return (0);
}

int	check_alpha(char **str)
{
	int ct = 0;
	int b = 0;

	if (str[1][ct] == '-')
		ct ++;
	if (str[1][0] == '-' && str[1][1] == '\0') {
		my_printf("exit: Expression Syntax.\n");
		return (-1);
	}
	while (str[1][ct] != '\0') {
		if (checking_alpha(str, ct, &b) == -1) {
			return (-1);
		}
		ct ++;
	}
	return (0);
}

int	get_exit(char **str)
{
	int ct = 0;
	int tmp = 0;
	int b = 0;

	if (str[1][ct] == '-') {
		b = 1;
		ct ++;
	}
	while (str[1][ct] != '\0') {
		tmp = str[1][ct] - 48 + tmp;
		ct ++;
	}
	if (b == 1)
		tmp = tmp * -1;
	return (tmp);
}

int	exit_env(char **str, char **envp, env_st_t *env_st)
{
	(void)envp;
	(void)env_st;
	(void)str;

	if (str[1] == NULL) {
		if (isatty(0) == 1)
			my_printf("exit\n");
		exit(0);
	}
	if (check_alpha(str) == -1)
		return (0);
	if (isatty(0) == 1)
		my_printf("exit\n");
	exit((unsigned char)get_exit(str));
	return (0);
}
