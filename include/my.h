/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** struct declaration file
*/

#ifndef MY_H_
	#define MY_H_

	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <stdarg.h>
	#include <stdio.h>
	#include <sys/types.h>
	#include <fcntl.h>
	#include <dirent.h>
	#include <pwd.h>
	#include <grp.h>
	#include <errno.h>
	#include <sys/wait.h>

	extern char const *tab_name[];

	typedef struct tree_s {
		int fd_in;
		int fd_out;
		char *commande_parseur;
		struct tree_s *left;
		struct tree_s *right;
	} tree_t;

	typedef struct history_s {
		int nbr;
		char *command;
		struct history_s *next;
	} history_t;

	typedef struct env_st_s {
		int len_w;
		int len_h;
		int unset;
		int ind;
		int cd_abl;
		int status;
		char **envp_cpy;
		char **envp_bsc;
		tree_t *tree;
		history_t *history;
	} env_st_t;

	typedef struct name_env_s {
		char *name;
		int (*name_str)(char **str, char **envp, env_st_t *env_st);
	} name_env_t;

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

	int	grep(char **str, char **envp, env_st_t *env_st);
	void first_simple_or_sep(char **arr, tree_t* temp,
	env_st_t *env_st, int *b);
	void my_pipe(char **command, int fd_in, int fd_out, env_st_t *env_st);
	int my_first_command_pipe(env_st_t *env_st,
	char **command_in, tree_t* temp, int *num);
	int my_last_command_pipe(env_st_t *env_st,
	char **command_out, tree_t* temp, int *num);
	int my_pipe_start_more(env_st_t *env_st, tree_t* temp,
	int *num, int *num_pip);
	char **load_command_out(tree_t* temp);
	void check_path_pip(char **envp, char *name,
	env_st_t* env_st, char **str_arr);
	int check_bult_in(char *str);
	void fourth_double_verif_sep(char **arr,
	tree_t* temp, env_st_t *env_st, int *b);
	void third_double_verif_sep(char **arr,
	tree_t* temp, env_st_t *env_st, int *b);
	void second_double_verif_sep(char **arr,
	tree_t* temp, env_st_t *env_st, int *b);
	void first_double_verif_sep(char **arr,
	tree_t* temp, env_st_t *env_st, int *b);
	void first_start_sep(char **arr,
	tree_t* temp, env_st_t *env_st, int *b);
	void second_start_sep(char **arr,
	tree_t* temp, env_st_t *env_st, int *b);
	void third_start_sep(char **arr,
	tree_t* temp, env_st_t *env_st, int *b);
	int exit_value(char *command_in, char *command_out);
	int my_getnbr(char const *str);
	int main_loop(char **envp, int end, char *str);
	void my_right_red_pipe(char **file, tree_t* temp, char *sep);
	int pipe_check_exec(char **command, char **envp, env_st_t *env_st, tree_t* temp);
	int my_pipe_start(env_st_t *env_st,
	char **command_in, char **command_out, tree_t* temp);
	int my_putstr_err(char *str, char *msg);
	void my_printf_err(char *str, ...);
	void my_right_red_start(env_st_t *env_st,
	char **command, char **file, tree_t* temp);
	void my_right_double_red_start(env_st_t *env_st,
	char **command, char **file, tree_t* temp);
	void my_left_red_start(env_st_t *env_st,
	char **command, char **file, tree_t* temp);
	void my_double_left_red_start(env_st_t *env_st,
	char **command, char **file, tree_t* temp);
	char  *my_getline(void);
	int strat_exec_red(char *name, char **str,
	env_st_t* env_st, tree_t* temp);
	void check_path_env_red(char *name,
	env_st_t* env_st, char **str_arr, tree_t* temp);
	int status(int w, env_st_t* env_st);
	int exec_red(env_st_t* env_st, char **str, tree_t* temp);
	int check_gnl(char *name, char **envp, env_st_t *env_st, tree_t* temp);
	int main_b_tree(char *str, env_st_t *info);
	int my_strcmp_c(char *s1, char const *s2);
	tree_t *my_list_command(char *command, env_st_t *info);
	char **my_separator_command(char *av, char *sep);
	char *my_second_command(char *av, int len);
	tree_t *fill_struct_comand(char *command, int fd_in, int fd_out);
	char *start_sep_command(int ct, int ctb, char *command, int *b);
	int check_sep_char(char *str);
	int check_sep(char **arr);
	char *check_command_bis(int ct, char *command, int *b);
	char *check_command(char *command, int b);
	int error_pipe_redic_second(tree_t* temp, char *str);
	int error_pipe_redic_bis(tree_t* temp, char *str, char **arr);
	int error_pipe_redic_first(tree_t* temp, char *str);
	int error_pipe_redic(tree_t* temp, char *str);
	int start_error_sep(tree_t* temp, char **arr, int ct, int b);
	int start_error_tree(tree_t* temp, int b);
	char *get_next_line(int fd);
	char *maloc_str(int ct, int b, int ctb, char **str);
	void check_path_env(char **envp, char *name, env_st_t* env_st,
	char **str_arr, tree_t* temp);
	int check_path_bsc(char **envp, char *name, char **str_arr,
	env_st_t* env_st, tree_t* temp);
	int strat_exec(char *name, char **envp, char **str, env_st_t* env_st, tree_t* temp);
	char *pathing(char **envp, int *ct, int ctb);
	int error_oldpwd(char **str, int cd_min, env_st_t *env_st);
	char **create_env(void);
	int check_name(char **str, env_st_t* env_st);
	int check_same(char **envp, env_st_t* env_st);
	int set_name_value(char **str, char **envp, env_st_t* env_st);
	int set_name(char **str, char **envp, env_st_t* env_st);
	char **unset_env_name(char **str, char **envp, env_st_t* env_st);
	int check_env(char *envp, char *name);
	int error_set_env(char **str, env_st_t* env_st);
	int strat_set_env(char **str, char **envp, env_st_t* env_st, int b);
	int set_env(char **str, char **envp, env_st_t* env_st);
	int env(char **str, char **envp, env_st_t *env_st);
	char **copy_env(char **envp, env_st_t* env_st, int ct);
	int delet_val(char *str, char **envp, env_st_t* env_st);
	int change_env(char *pwd, char *oldpwd, int b, env_st_t *env_st);
	char *my_getcwd(char *str, int ctb);
	char *get_path(char **envp, env_st_t *env_st, int ct);
	int cd_pwd(char **str, env_st_t *env_st);
	int cd_home(char **str, char **envp, env_st_t *env_st, int cd_min);
	int cd_oldpwd(char **str, char **envp, env_st_t *env_st, int cd_min);
	int exec(char **envp, env_st_t* env_st, char **str, tree_t* temp);
	int set_env(char **str, char **envp, env_st_t* env_st);
	int unset_env(char **str, char **envp, env_st_t* env_st);
	int exit_env(char **str, char **envp, env_st_t *env_st);
	int env(char **str, char **envp, env_st_t *env_st);
	int cd(char **str, char **envp, env_st_t *env_st);
	env_st_t *fill_struct(char **envp);
	char **word_array(char *line);
	int epur_str(char *str);
	char *copy_str_arr(char *line, int *ct);
	int check_val(char **envp, char *name, env_st_t* env_st);
	int check_env(char *envp, char *name);
	int my_putchar(char c);
	int my_put_nbr(int nb);
	int my_putstr(char *str, int len);
	char *my_revstr(char *str);
	char *my_strcat(char *dest, char *src, int b);
	int my_strcmp(char *s1, char *s2);
	char *my_strdup(char *src);
	int my_strlen(char *str);
	char *my_strncat(char *dest, char *src, int n);
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

#endif
