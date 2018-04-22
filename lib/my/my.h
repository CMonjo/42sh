/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#include<stdarg.h>

#ifndef  CHECK_MALLOC

#define  CHECK_MALLOC(file, size) if (!(file = malloc(sizeof(char) * size))) \
	return (NULL);

#endif

#ifndef  CHECK_LINE

#define  CHECK_LINE free(file);	\
		if (line_n_len(*str, 0, 0) == 1) { \
		file = line(*str, 0, 0, 1);	       \
		*str = line(*str, 0, 0, 0);	       \
		return (file); \
	}

#endif

#ifndef  CHECK_LINE_END

#define  CHECK_LINE_END CHECK_LINE; \
		if (line_n_len(*str, 0, 0) != 1 && my_strlen(*str) != 0) { \
		file = my_strdup(*str);	\
		free(*str);	\
		*str = NULL;	\
		return (file);                                              \
	}

#endif

#ifndef  CHECK_STR_FREE

#define  CHECK_STR_FREE for (; str_tp[ctp] != '\0'; ctp ++) \
			str[ctp] = str_tp[ctp]; \
			str[ctp] = '\0'; \
			free(str_rst); \
			free(str_tp); \

#endif

#ifndef  READ_SIZE

#define  READ_SIZE 3000

#endif

#ifndef MY_H

#define MY_H

int my_getnbr(char const *str);
int	choise_flag_err(char *str, int ct, int b);
int	flag_flag_err(char *str, int ct);
char	*copy_str_err(char *str, char *str_temp, int ct);
char	*copy_flag_err(char *str, char *temp, int ct);
int	flag_s_err(va_list ap, int ct, char *str, char *str_temp);
int	my_putstr_err(char *str, char *msg);
void	my_printf_err(char *str, ...);
void	my_putchar_err(char c);
char	*get_next_line(int fd);
int	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str, int len);
char	*my_revstr(char *str);
char	*my_strcat(char *dest, char *src, int b);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *src);
int	my_strlen(char *str);
char	*my_strncat(char *dest, char *src, int n);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcpy(char *dest, char const *src);
char	*my_strncpy(char *dest, char *src, int n);
void	my_swap(int *a, int *b);
char	*swap_output(char *base, int nb);
long long	my_put_long_long(long long nb);
void	my_put_unsg_ll(unsigned long long nb);
int	my_long_long_len(long long nb);
int	flag_x(va_list ap, int ct, char *str, char *str_temp);
int	flag_xx(va_list ap, int ct, char *str, char *str_temp);
int	flag_o(va_list ap, int ct, char *str, char *str_temp);
int	flag_long(va_list ap, int ct, char *str, char *str_temp);
int	flag_h_nbr(va_list ap, int ct, char *str, char *str_temp);
int	flag_long_long(va_list ap, int ct, char *str, char *str_temp);
int	flag_unsg_short(va_list ap, int ct, char *str, char *str_temp);
int	flag_unsg_l(va_list ap, int ct, char *str, char *str_temp);
int	flag_unsg_ll(va_list ap, int ct, char *str, char *str_temp);
int	flag_p(va_list ap, int ct, char *str, char *str_temp);
int	flag_s(va_list ap, int ct, char *str, char *str_temp);
int	flag_c(va_list ap, int ct, char *str, char *str_temp);
int	flag_b(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_x(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_xx(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_o(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_b(va_list ap, int ct, char *str, char *str_temp);
int	flag_plus(char *str_temp, long long rst, int b, int nbr);
int	flag_plus_bis(char *str_temp, long long rst, int b);
int	nbr_disp(int temp_len, char *str_temp, int nbr, int b);
int	nbr_disp_bis(int temp_len, char *str_temp, int nbr_f, int b);
int	nbr_disp_bis(int temp_len, char *str_temp, int nbr_f, int b);
int	nbr_disp_thd(long long rst);
void	base(unsigned long long nbr, char *str);
void	separator_flag(char *str, va_list ap, int ct, char *str_temp);
void	flag_one(char *str, va_list ap, int ct, char *str_temp);
int	choise_flag(char *str, int ct, int b);
char	*copy_flag(char *str, char *temp, int ct);
char	*copy_str(char *str, char *str_temp, int ct);
void	my_printf(char *str, ...);
int	len_flag(char *str, int ct);
void	flag_sign(long long rst);
int	flag_flag(char *str, int ct);
int	choise_flag_flag(char *str, int ctp, long long temp, char *str_temp);
int	choise_flg_flg_c(char *str, int ctp, char* temp, char *str_temp);
void	flag_nbr_disp(int nbr, int len_f);
int	flag_nbr(char *str, char *str_temp, int ctp, int temp);
void	flag_zero_disp(int nbr, int len_f);
int	flag_long_long_d(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_x(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_xx(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_o(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_b(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_u(va_list ap, int ct, char *str, char *str_temp);
int	flag_ss(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_d(va_list ap, int ct, char *str, char *str_temp);
void	flag_has_o(char *str_temp);
void	flag_has_x(char *str_temp);
void	flag_has_xx(char *str_temp);

#endif

typedef struct spec
{
	char spec_pf;
	int (*spec_p)(va_list ap, int ct, char *str, char *str_temp);
}spec_t;

typedef struct length
{
	char *sep_pf;
	int (*sep_p)(va_list ap, int ct, char *str, char *str_temp);
}length_t;

typedef struct flag
{
	char flag_pf;
	int (*flag_p)(char *str, int ctp, long long temp, char *str_temp);
}flag_t;

typedef struct flag_char
{
	char flag_c_pf;
	int (*flag_c_p)(char *str, int ctp, char *temp, char *str_temp);
}flag_char_t;
