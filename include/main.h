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
	#include <stdio.h>
	#include <sys/types.h>
	#include <fcntl.h>
	#include <dirent.h>
	#include <pwd.h>
	#include <grp.h>
	#include <errno.h>
	#include <sys/wait.h>
	#include "tools.h"
	#include <glob.h>

	#define UNUSED __attribute__((unused))

	extern char const *tab_name[];

	typedef struct alias_s {
		char *bind;
		char *command_bind;
		char *command_display;
		struct alias_s *next;
	} alias_t;

	typedef struct set_s {
		char *var;
		char *var_value;
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
		alias_t *alias;
		set_t *set;
		history_t *history;
	} env_st_t;

	typedef struct name_env_s {
		char *name;
		int (*name_str)(char **str, char **envp, env_st_t *env_st);
	} name_env_t;


	//SET
	int set(char **array, UNUSED char **envp, env_st_t *env_st);
	char *set_parse(char **tab);
	char *concat_set(char *dest, char *src);
	void set_compare(env_st_t *env_st, char *str);
	void set_display(env_st_t *env_st);

	//ALIAS
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
	int alias(char **array, UNUSED char **envp, env_st_t *env_st);
	char *alias_parse(char **tab);
	char *alias_check_string(char *long_str, char *parents);
	void alias_fill(env_st_t *env_st, char **str, char *long_str,
		char *parenthesis);
	void alias_compare(env_st_t *env_st, char *str);
	void alias_add(env_st_t *env_st, char **str, char *long_str,
		char *parenthesis);
	alias_t *alias_add_node(char **str, char *long_str,
		char *parenthesis);
	void alias_display(env_st_t *env_st);
	char *alias_parse_parenthesis(char **tab);
	int	error_alias_loop(char *first, char *str, env_st_t *env_st);
	int	check_gnl_alias(char *name, char **envp,
	env_st_t *env_st, tree_t* temp);
	void error_backstick_quote(char *str, char c, int *ct);
	void error_parent(char *command);
	int check_long_sep(char *command);
	int repeat(char **arr, char **envp, env_st_t *env_st);
	int echo(char **arr, char **envp, env_st_t *env_st);
	int cat(char **arr, char **envp, env_st_t *env_st);
	int grep(char **str, char **envp, env_st_t *env_st);
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
	tree_t*	my_list_command(char *command, env_st_t* info, int fd_in, int fd_out);
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
	void check_path_env(char **envp, char *name, env_st_t* env_st,
	char **str_arr, tree_t* temp);
	int check_path_bsc(char **envp, char *name, char **str_arr,
	env_st_t* env_st, tree_t* temp);
	int strat_exec(char *name, char **envp, char **str, env_st_t* env_st,
		tree_t* temp);
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
	void	star_handle(char **array, char **env, env_st_t *env_st);
#endif
