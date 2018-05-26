/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/if/then.c
*/

#include "main.h"

void	prompt_if(void)
{
	if (isatty(0) == 1)
		my_printf("if? ");
}

void	prompt_else(void)
{
	if (isatty(0) == 1)
		my_printf("else? ");
}

char	**then_loop(UNUSED char **arr, UNUSED char **envp, env_st_t *env_st)
{
	char *str = malloc(sizeof(char) * 1);

	str[0] = '\0';
	while (end_if_while(word_array(str), env_st) != 1) {
		str = my_getline();
		if (isatty(0) == 1 && str == NULL) {
			my_putstr_err(NULL, "then: then/endif not found.\n");
			exit(1);
		}
		if (my_strlen(str) > 0
		&& end_if_while(word_array(str), env_st) == 1) {
			break;
		}
		else if (my_strlen(str) <= 0 && isatty(0) != 1) {
			my_putstr_err(NULL, "then: then/endif not found.\n");
			exit(1);
		}
		prompt_if();
	}
	return (NULL);
}

char	**else_loop(UNUSED char **arr, UNUSED char **envp, env_st_t *env_st)
{
	char *str = malloc(sizeof(char) * 1);

	str[0] = '\0';
	while (end_else_while(word_array(str), env_st) != 1) {
		str = my_getline();
		if (isatty(0) == 1 && str == NULL) {
			my_putstr_err(NULL, "else: endif not found.\n");
			exit(1);
		}
		if (my_strlen(str) > 0
		&& end_else_while(word_array(str), env_st) == 1) {
			break;
		}
		else if (my_strlen(str) <= 0 && isatty(0) != 1) {
			my_putstr_err(NULL, "else: endif not found.\n");
			exit(1);
		}
		prompt_else();
	}
	return (NULL);
}