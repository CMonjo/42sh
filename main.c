/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** main.c
*/

#include "my.h"

void	prompt(void)
{
	if (isatty(0) == 1)
		my_printf("%s $> ", getcwd(NULL, 0));
}

int	main_loop(char **envp, int end, char *str)
{
	env_st_t *env_st = fill_struct(envp);

	prompt();
	while (!end) {
		str = my_getline();
		if (isatty(0) == 1 && str == NULL) {
			my_printf("exit\n");
			exit(0);
		}
		if (my_strlen(str) > 0) {
			main_b_tree(str, env_st);
		}
		else if (isatty(0) != 1)
			end = !end;
		prompt();
	}
	return (env_st->status);
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	return (main_loop(envp, 0, NULL));
}
