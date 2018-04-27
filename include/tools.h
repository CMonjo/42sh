/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** struct declaration file
*/

#ifndef TOOLS_H_
	#define TOOLS_H_

	#include "main.h"

	typedef struct spec_s {
		char spec_pf;
		int (*spec_p)(va_list ap, int ct, char *str, char *str_temp);
	} spec_t;

	typedef struct length_s {
		char *sep_pf;
		int (*sep_p)(va_list ap, int ct, char *str, char *str_temp);
	} length_t;

	typedef struct flag_s {
		char flag_pf;
		int (*flag_p)(char *str, int ctp, long long temp, char *str_temp);
	} flag_t;

	typedef struct flag_char_s {
		char flag_c_pf;
		int (*flag_c_p)(char *str, int ctp, char *temp, char *str_temp);
	} flag_char_t;

	void my_putchar(char c);
	int my_put_nbr(int nb);
	int my_putstr(char *str, int len);
	char *my_revstr(char *str);
	char *my_strcat(char *dest, char *src, int b);
	int my_strcmp(char *s1, char *s2);
	char *my_strdup(char *src);
	int my_strlen(char *str);
	char *my_strncat(char *dest, char *src, int n);
	int my_putstr_err(char *str, char *msg);
	void my_putchar_err(char c);
	int my_strncmp(char *s1, char *s2, int n);
	char *my_strcpy(char *dest, char const *src);
	char *my_strncpy(char *dest, char *src, int n);
	void my_swap(int *a, int *b);
	char *swap_output(char *base, int nb);
	long long my_put_long_long(long long nb);
	void my_put_unsg_ll(unsigned long long nb);
	int my_long_long_len(long long nb);
	int flag_x(va_list ap, int ct, char *str, char *str_temp);
	int flag_xx(va_list ap, int ct, char *str, char *str_temp);
	int flag_o(va_list ap, int ct, char *str, char *str_temp);
	int flag_long(va_list ap, int ct, char *str, char *str_temp);
	int flag_h_nbr(va_list ap, int ct, char *str, char *str_temp);
	int flag_long_long(va_list ap, int ct, char *str, char *str_temp);
	int flag_unsg_short(va_list ap, int ct, char *str, char *str_temp);
	int flag_unsg_l(va_list ap, int ct, char *str, char *str_temp);
	int flag_unsg_ll(va_list ap, int ct, char *str, char *str_temp);
	int flag_p(va_list ap, int ct, char *str, char *str_temp);
	int flag_s(va_list ap, int ct, char *str, char *str_temp);
	int flag_c(va_list ap, int ct, char *str, char *str_temp);
	int flag_b(va_list ap, int ct, char *str, char *str_temp);
	int flag_ll_x(va_list ap, int ct, char *str, char *str_temp);
	int flag_ll_xx(va_list ap, int ct, char *str, char *str_temp);
	int flag_ll_o(va_list ap, int ct, char *str, char *str_temp);
	int flag_ll_b(va_list ap, int ct, char *str, char *str_temp);
	int flag_plus(char *str_temp, long long rst, int b, int nbr);
	int flag_plus_bis(char *str_temp, long long rst, int b);
	int nbr_disp(int temp_len, char *str_temp, int nbr, int b);
	int nbr_disp_bis(int temp_len, char *str_temp, int nbr_f, int b);
	int nbr_disp_bis(int temp_len, char *str_temp, int nbr_f, int b);
	int nbr_disp_thd(long long rst);
	void base(unsigned long long nbr, char *str);
	void separator_flag(char *str, va_list ap, int ct, char *str_temp);
	void flag_one(char *str, va_list ap, int ct, char *str_temp);
	int choise_flag(char *str, int ct, int b);
	char *copy_flag(char *str, char *temp, int ct);
	char *copy_str(char *str, char *str_temp, int ct);
	void my_printf(char *str, ...);
	int len_flag(char *str, int ct);
	void flag_sign(long long rst);
	int flag_flag(char *str, int ct);
	int choise_flag_flag(char *str, int ctp,
	long long temp, char *str_temp);
	int choise_flg_flg_c(char *str, int ctp, char* temp, char *str_temp);
	void flag_nbr_disp(int nbr, int len_f);
	int flag_nbr(char *str, char *str_temp, int ctp, int temp);
	void flag_zero_disp(int nbr, int len_f);
	int flag_long_long_d(va_list ap, int ct, char *str, char *str_temp);
	int flag_hh_x(va_list ap, int ct, char *str, char *str_temp);
	int flag_hh_xx(va_list ap, int ct, char *str, char *str_temp);
	int flag_hh_o(va_list ap, int ct, char *str, char *str_temp);
	int flag_hh_b(va_list ap, int ct, char *str, char *str_temp);
	int flag_hh_u(va_list ap, int ct, char *str, char *str_temp);
	int flag_ss(va_list ap, int ct, char *str, char *str_temp);
	int flag_hh_d(va_list ap, int ct, char *str, char *str_temp);
	void flag_has_o(char *str_temp);
	void flag_has_x(char *str_temp);
	void flag_has_xx(char *str_temp);
	char	**word_array(char *line);
	char	*malloc_str(int ct, int b, int ctb, char **str);

#endif
