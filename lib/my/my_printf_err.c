/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** my_printf, display with flags
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

spec_t const tab_specc[] = {{'c', flag_c}, {'x', flag_x},
			{'X', flag_xx}, {'o', flag_o},
			{'u', flag_unsg_l}, {'d', flag_long},
			{'i', flag_long},
			{'S', flag_ss}, {'p', flag_p}, {'s', flag_s_err},
			{'b', flag_b}};

length_t const tab_lenn[] = {{"lld", flag_long_long}, {"lli", flag_long_long},
			{"llu", flag_unsg_ll},
			{"llo", flag_ll_o}, {"llx", flag_ll_x},
			{"llX", flag_ll_xx}, {"ld", flag_long},
			{"li", flag_long}, {"lu", flag_unsg_l},
			{"lo", flag_o}, {"lx", flag_x}, {"lX", flag_xx},
			{"hhd", flag_hh_d}, {"hhi", flag_hh_d},
			{"hhu", flag_hh_u}, {"hho", flag_hh_o},
			{"hhx", flag_hh_x}, {"hhX", flag_hh_xx},
			{"hd", flag_h_nbr}, {"hi", flag_h_nbr},
			{"hu", flag_unsg_short}, {"ho", flag_o},
			{"hx", flag_x}, {"hX", flag_xx}};

void	flag_one_err(char *str, va_list ap, int ct, char *str_temp)
{
	int ctp = 0;
	int ctb = 0;

	while (ctp < 11) {
		if (str[ctb] == tab_specc[ctp].spec_pf)
			(tab_specc[ctp].spec_p)(ap, ct, str, str_temp);
		ctp ++;
	}
}

void	separator_flag_err(char *str, va_list ap, int ct, char *str_temp)
{
	int len = my_strlen(str);
	int ctp = 0;

	if (len == 1) {
		flag_one_err(str, ap, ct, str_temp);
		free(str_temp);
		return;
	}
	while (ctp < 24) {
		if (my_strcmp(str, tab_lenn[ctp].sep_pf) == 0) {
			(tab_lenn[ctp].sep_p)(ap, ct, str, str_temp);
		}
		ctp ++;
	}
	free(str_temp);
}

int	choise_flag_err(char *str, int ct, int b)
{
	int ctp = 0;

	while (ctp < 11) {
		if (str[ct] == tab_specc[ctp].spec_pf) {
			b ++;
			return (b);
		}
		ctp ++;
	}
	return (0);
}

int	len_flag_err(char *str, int ct)
{
	int b = 0;
	int ctp = 0;

	while (b == 0) {
		while (ctp < 10) {
			if (str[ct] == tab_specc[ctp].spec_pf)
				b ++;
			ctp ++;
		}
		ctp = 0;
		ct ++;
	}
	return (ct);
}

void	my_printf_err(char *str, ...)
{
	va_list ap;
	char *temp;
	char *str_temp;

	temp = my_strdup("0");
	va_start(ap, str);
	for (int ct = 0; str[ct] != '\0'; ct ++) {
		if (str[ct] == '%') {
			str_temp = copy_str(str, str_temp, ct);
			ct = flag_flag(str, ct);
			temp = copy_flag(str, temp, ct);
			separator_flag_err(temp, ap, ct, str_temp);
			ct = len_flag_err(str, ct);
			ct --;
		} else {
			my_putchar_err(str[ct]);
		}
	}
	free(temp);
	va_end(ap);
}
