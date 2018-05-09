/*
** EPITECH PROJECT, 2017
** flag_disp.c
** File description:
** display the flag
*/

#include "tools.h"

int	flag_ss(va_list ap, int ct, char *str, char *str_temp)
{
	int ctp = 0;
	char *rst = va_arg(ap, char*);
	char base_oct[] = "01234567";
	(void)str_temp;
	(void)str;

	while (rst[ctp] != '\0') {
		if (rst[ctp] < 32 || rst[ctp] >= 127) {
			my_putchar('\\');
			base(rst[ctp], base_oct);
		}
		my_putchar(rst[ctp]);
		ctp ++;
	}
	return (ct);
}

int	flag_c(va_list ap, int ct, char *str, char *str_temp)
{
	(void)str_temp;
	(void)str;

	my_putchar(va_arg(ap, int));
	return (ct);
}

void	flag_nbr_disp(int nbr, int len_f)
{
	nbr = nbr - len_f;
	while (nbr != 0 && nbr > 0) {
		nbr --;
		my_putchar(' ');
	}
}

int	flag_nbr(char *str, char *str_temp, int ctp, int temp)
{
	int nbr = 1;
	int ct = 0;

	if ((str_temp[ctp - 1] >= 48 && str_temp[ctp - 1] <= 57)
	&& (my_strlen(str) != temp)) {
		while (str_temp[ctp + ct] >= 48 && str_temp[ctp + ct] <= 57) {
			ct ++;
			nbr = nbr * 10;
		}
		nbr = nbr * (str_temp[ctp - 1] - 48);
		return (nbr);
	}
	return (0);
}

int	flag_s(va_list ap, int ct, char *str, char *str_temp)
{
	int len;
	int ctp = 0;
	int nbr = 0;

	str = my_strdup(va_arg(ap, char*));
	len = my_strlen(str);
	while (str_temp[ctp] != '\0') {
		ctp ++;
		if (str_temp[ctp] >= 48 && str_temp[ctp] <= 57)
			nbr = nbr * 10 + (str_temp[ctp] - 48);
	}
	flag_nbr_disp(nbr, len);
	my_putstr(str, len);
	free(str);
	return (ct);
}
