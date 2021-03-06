/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** struct declaration file
*/

#ifndef MAIN_H_
	#define MAIN_H_

	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdio.h>
	#include <sys/types.h>
	#include <fcntl.h>
	#include <dirent.h>
	#include <pwd.h>
	#include <grp.h>
	#include <time.h>
	#include <errno.h>
	#include <sys/wait.h>
	#include <glob.h>
	#include <ncurses.h>
	#include <termios.h>
	#include <termcap.h>
	#include "tools.h"

	#define UNUSED __attribute__((unused))

	extern char const *tab_name[];

	typedef struct alias_s {
		char *bind;
		char *command_bind;
		char *command_display;
		int active;
		struct alias_s *next;
	} alias_t;

	typedef struct set_s {
		char *name;
		char *value;
		int active;
		struct set_s *next;
	} set_t;

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
		long number;
		char hrs[3];
		char min[3];
		struct history_s *next;
		struct history_s *prev;
	} history_t;

	typedef struct color_s {
		char name[10];
		char cmd[10];
	} color_t;

	typedef struct prompt_s {
		char clock[10];
		char path[10];
	} prompt_t;

	typedef struct job_s {
		int nbr;
		int pid;
		char *command;
		struct job_s *next;
	} job_t;

	typedef struct term_s {
		int mal;
		int histo;
		int a;
		int b;
		struct termios origin;
		struct termios tios;
	} term_t;

	typedef struct env_st_s {
		int len_w;
		int len_h;
		int unset;
		int ind;
		int cd_abl;
		int status;
		int err;
		int set_array;
		char **envp_cpy;
		char **envp_bsc;
		prompt_t *prompt;
		tree_t *tree;
		term_t *term;
		alias_t *alias;
		set_t *set;
		history_t *history;
		job_t *job;
	} env_st_t;

	typedef struct name_env_s {
		char *name;
		int (*name_str)(char **str, char **envp, env_st_t *env_st);
	} name_env_t;

	typedef struct if_s {
		char *name;
		int (*name_str)(char *str_one, char *str_two);
	} if_t;

	typedef struct variables_s {
		char *name;
		char *(*name_str)(char *str, env_st_t *env_st);
	} variables_t;

	typedef struct exec_tree_s {
		char *name;
		int (*name_str)(env_st_t *env_st, char **command,
	char **file, tree_t* temp);
	} exec_tree_t;

	//SET
	int set(char **array, UNUSED char **envp, env_st_t *env_st);
	void set_parse(env_st_t *env_st, char *, char *);
	void set_fill(env_st_t *env_st, char *name, char *value);
	void set_display(env_st_t *env_st);
	int unset(char **array, UNUSED char **envp, env_st_t *env_st);
	void set_check_array(env_st_t *, char **, int);
	void set_add(env_st_t *env_st, char *name, char *value);
	int set_isalpha(env_st_t *env_st, char const *str);
	int set_deep(char *str);
	char *set_parsing_spaced(char *set_value, char *str);
	void set_parse_spaces(env_st_t *env_st, char *str, char *spaced);
	void my_bubble_set(set_t *current);

	//ALIAS
	char	**else_loop(UNUSED char **arr,
	UNUSED char **envp, env_st_t *env_st);
	int	else_build(char **arr, UNUSED char **envp, env_st_t *env_st);
	void	prompt_else(void);
	int	end_else_while(char **arr, UNUSED env_st_t *env_st);
	int	endif_build(UNUSED char **arr,
	UNUSED char **envp, env_st_t *env_st);
	int	error_main_b_tree_variable(char *str,
	char *command, env_st_t *info);
	int	check_special_case(char *str);
	int	error_main_b_tree(char *command, env_st_t *info, tree_t* temp);
	void	skip_parent_command(char *command, int *ctb);
	void	remove_parent_command(char *command, char *av,
	char sep, int len);
	char	*my_second_command(char *av, int len, char sep);
	int	check_sep_bis_second(char **arr);
	void	skip_parent(char **arr, int *ctb);
	int	check_alias_local_var(char *command,
	char *str, env_st_t *env_st);
	void	pass_alias_unalias(char **arr, int *ct);
	void	first_simple_or_sep_and(tree_t* temp, env_st_t *env_st);
	void	first_simple_or_sep_or(tree_t* temp, env_st_t *env_st);
	char	*my_getline_file(FILE *fd);
	void	my_pipe_start_only(env_st_t *env_st,
	char **command_in, char **command_out, tree_t* temp);
	char	**then_loop(char **arr, UNUSED char **envp, env_st_t *env_st);
	void	prompt_if(void);
	int	end_if_while(char **arr, env_st_t *env_st);
	char	*rm_first_arr(char **arr);
	int	cat_bis(char **arr,
	UNUSED char **envp, UNUSED env_st_t *env_st);
	void	print_ascii(FILE *fd);
	char	**recup_face(FILE *fd);
	int	clock_func(void);
	char *concat_alias(char *dest, char *src);
	char	*get_pid(char *str, env_st_t *env_st);
	char	*value_return(char *str, env_st_t *env_st);
	void	fill_history(env_st_t *info, char *str);
	char	*find_local_var(char *str, env_st_t *env_st);
	char	*variable(char *str, env_st_t *env_st);
	int	variable_error(char *str, env_st_t *env_st);
	char	*second_string(char *str, int *ct);
	char	*first_string(char *str, int *ct);
	char	*variable_name_string(char *str, int *ct);
	int	error_if_syntax_next(char **arr, env_st_t *env_st);
	int	if_inf(char *str_one, char *str_two);
	int	if_sup(char *str_one, char *str_two);
	int	if_equal_inf(char *str_one, char *str_two);
	int	if_equal_sup(char *str_one, char *str_two);
	int	if_equal(char *str_one, char *str_two);
	int	if_build(char **arr, char **envp, env_st_t *env_st);
	int	jobs(char **arr, char **envp, env_st_t *env_st);
	char	*chang_inib(char *str);
	char	*replace_variable_arr(char *str_one, char *str_two,
	char **arr, int index_arg);
	char	*replace_variable(char *str, char **arr);
	int	scripting(char **arr, char **arr_val, char **envp,
	env_st_t* env_st);
	int alias(char **array, UNUSED char **envp, env_st_t *env_st);
	char *alias_parse(char **tab);
	char *alias_check_string(char *long_str, char *parents);
	void alias_fill(env_st_t *env_st, char **str, char *long_str,
		char *parenthesis);
	void alias_compare(env_st_t *env_st, char *str);
	int unalias(char **array, UNUSED char **envp, env_st_t *env_st);
	void alias_add(env_st_t *env_st, char **str, char *long_str,
	char *parenthesis);
	alias_t *alias_add_node(char **str, char *long_str,
	char *parenthesis);
	void alias_display(env_st_t *env_st);
	char *alias_parse_parenthesis(char **tab);
	int	error_alias_loop(char *first, char *str, env_st_t *env_st);
	int	check_gnl_alias(char *name, char **envp,
	env_st_t *env_st, tree_t* temp);

	//
	int	ascii(char **array, UNUSED char **envp, env_st_t *env_st);
	void	prompt_foreach(void);
	int	count_ele(char **arr);
	int	error_foreach(char **arr, env_st_t *env_st);
	int	error_foreach_args(char **arr, env_st_t *env_st, int tab_len);
	int	error_foreach_alphanumeric(char **arr, env_st_t *env_st);
	int	where_path(char *str, env_st_t *env_st);
	int	where_builtin(char *str);
	int	where_alias(char *str, env_st_t *env_st);
	int	which_path(char *str, env_st_t *env_st);
	int	which_builtin(char *str);
	int	which_alias(char *str, env_st_t *env_st);
	int	error_alias_dangerous(char **arr, env_st_t *env_st);
	int	end(char **arr, char **envp, env_st_t *env_st);
	int	end_foreach_while(char **arr, env_st_t *env_st, int);
	char	*create_file(void);
	int	foreach(char **arr, char **envp, env_st_t *env_st);
	int	where(char **arr, char **envp, env_st_t *env_st);
	int	which(char **arr, char **envp, env_st_t *env_st);
	int error_backstick_quote(char *str, char c, int *ct);
	int error_parent(char *command);
	int check_long_sep(char *command);
	int repeat(char **arr, char **envp, env_st_t *env_st);
	int echo_build(char **arr, char **envp, env_st_t *env_st);
	int cat(char **arr, char **envp, env_st_t *env_st);
	int grep(char **str, char **envp, env_st_t *env_st);
	void first_simple_or_sep(char **arr, tree_t* temp,
	env_st_t *env_st, int *b);
	void my_pipe(char **command, int fd_in, int fd_out, env_st_t *env_st);
	int my_first_command_pipe(env_st_t *env_st,
	char **command_in, tree_t* temp, int *num);
	int	error_if_syntax_next_next(char **arr, env_st_t *env_st);
	char	*if_command(char **arr);
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
	int pipe_check_exec(char **command, char **envp, env_st_t *env_st,
		tree_t* temp);
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
	int	main_b_tree(char *str, env_st_t *info, int fd_in, int fd_out);
	int my_strcmp_c(char *s1, char const *s2);
	tree_t*	my_list_command(char *command, env_st_t* info,
	int fd_in, int fd_out);
	char **my_separator_command(char *av, char *sep);
	char *my_second_command(char *av, int len, char sep);
	tree_t *fill_struct_comand(char *command, int fd_in, int fd_out);
	char *start_sep_command(int ct, char *command, int *b);
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
	void check_path_env(char *name, env_st_t* env_st,
	char **str_arr, tree_t* temp);
	int check_path_bsc(char *name, char **str_arr,
	env_st_t* env_st, tree_t* temp);
	int strat_exec(char *name, char **str, env_st_t* env_st, tree_t* temp);
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
	char **word_array(char *line);
	int epur_str(char *str);
	char *copy_str_arr(char *line, int *ct);
	int check_val(char **envp, char *name, env_st_t* env_st);
	int check_env(char *envp, char *name);
	int	error_redi_right_input(tree_t* temp, char *str);
	char	**star_handle(char **array, char *str);
	void	my_bubble(alias_t *current);
	char	**bracket_handle(char **array, char *str);
	int	check_bracket_close(char *str, int ct);
	int	is_there_changement(char **array, char **new);
	char	**is_the_same(char **array, char *str, int *modif);
	char	**delete_line(char **array, int i);
	char	**add_line(char **array, char *str, int i);
	int	my_arraylen(char **array);
	int	glob_execution(char **str, char **envp, env_st_t *env_st,
	char *name);
	char	**inter_handle(char **array, char *str);
	int	check_inter(char *str);
	int	check_bracket(char *str);
	int	check_stars(char *str);
	char	**my_arraydup(char **array);
	int	if_no_equal(char *str_one, char *str_two);
	int	error_if_syntax(char **arr, env_st_t *env_st);
	int	exit_command(char **array, char **envp, env_st_t *env_st);
	char	*too_much_parent(char *str);
	char	*rm_char(char *str, int ct);
	int	verif_parent_next(char *str, int ct);
	int	verif_parent_next_rev(char *str, int ct);
	int	nb_char_in_str(char *str, char c);
	int	error_null_parent(char **command);
	char	*select_env(char **env, char *str);
	void	pass_quotes(char *str, int *ct, char quote);
	int	yes(char **str, UNUSED char **envp, UNUSED env_st_t *env_st);
	int	grep_bis(char **arr, UNUSED char **envp,
	UNUSED env_st_t *env_st, int tab_len);
	char	*grep_file(char *path, char *find, int boul, FILE *fd);
	int	error_and_or(tree_t* temp, char *str);
	char	**array_star_sort(char **array);
	int	is_there_star(char *str);
	int	builtins(UNUSED char **arr, UNUSED char **envp,
	UNUSED env_st_t *env_st);
	int	check_alias_local_var(char *command,
	char *str, env_st_t *env_st);
	int	check_gnl_next(char **str, char **envp, env_st_t *env_st);
	char	*my_getline_cle(FILE *fd);
	void	bash_rc(env_st_t *env_st);
	int history(char **array, UNUSED char **envp, env_st_t *env_st);
	void	fill_history(env_st_t *info, char *command);
	int	check_sheebang_next(int len_sheebang, char *str, int start);
	int	check_sheebang_file(char **arr, char *str, int sheebang_len,
	env_st_t* env_st);
	int	arr_len(char **arr);
	int	sheebang_next(int sheebang_len, char *str);
	int	sheebang_next_two(int file_len, char *str, int sheebang_len);
	int color(char **array, UNUSED char **envp, env_st_t *env_st);
	void init_prompt(env_st_t *env_st);
	int unset_canonic(env_st_t *sh);
	char *my_get_line(term_t *term, char *str, history_t *history);
	char *my_realloc(char *str, term_t *term, int nbr);
	void del_arrows(term_t *term, char *str, int *i);
	void manage_up_arrow(term_t *term, history_t **tmp, char *str, int *i);

#endif
