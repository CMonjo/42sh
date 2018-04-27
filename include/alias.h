/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** struct declaration file
*/

#ifndef ALIAS_H_
	#define ALIAS_H_

	#include "main.h"

	typedef struct alias_s {
		char *bind;
		char *command_bind;
		char *command_display;
		struct alias_s *next;
	} alias_t;

	typedef struct core_s {
		int status;
		alias_t *alias;
	} core_t;

	void alias(char **array, char **envp, env_st_t *env_st);
	char *alias_parse(char **tab);
	char *alias_check_string(char **str, char *long_str);
	void alias_fill(env_st_t *env_st, char **str, char *long_str);
	void alias_compare(env_st_t *env_st, char *str);
	void alias_add(env_st_t *env_st,, char **str, char *long_str);
	alias_t *alias_add_node(char **str, char *long_str);
	void alias_display(env_st_t *env_st);

	//TOOLS
	// int my_strlen(char *str);
	// char **my_str_to_word_array(char *str, char c);
	// int my_count_char(char *str, char c);
	// char *my_calloc(int nbchars);
	// int my_strcmp(char *s1, char *s2);
	// int my_printf(char *str, ...);
	// int my_putstr(char const *str);
	// void my_putchar(char c);
	// int my_put_nbr(int nb);
	// char *my_strcat(char *str1, char *str2);
#endif
