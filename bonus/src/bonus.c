/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** main.c
*/

#include "main.h"

env_st_t	*init_env_struct_bis(env_st_t* new_node)
{
	new_node->len_w = 0;
	new_node->ind = 0;
	new_node->unset = 0;
	new_node->cd_abl = 0;
	new_node->status = 0;
	new_node->err = 0;
	new_node->set_array = 0;
	new_node->tree = NULL;
	new_node->history = NULL;
	new_node->job = NULL;
	new_node->alias = NULL;
	new_node->set = NULL;
	return (new_node);
}

env_st_t	*init_env_struct(char **envp)
{
	env_st_t* new_node = malloc(sizeof(env_st_t));
	int ctp = 0;

	new_node = init_env_struct_bis(new_node);
	new_node->envp_bsc = create_env();
	(isatty(0) == 1) ? unset_canonic(new_node) : 0;
	if (envp[0] == NULL) {
		new_node->envp_cpy = create_env();
		new_node->len_h = 2;
	} else {
		while (envp[ctp] != NULL) {
			ctp ++;
		}
		new_node->len_h = ctp;
		new_node->envp_cpy = copy_env(envp, new_node, 0);
	}
	return (new_node);
}

void	prompt(void)
{
	time_t t = time(NULL);
	struct tm *timeinfo;
	char str[64];

	if (isatty(0) == 1) {
		str[0] = '\0';
		time(&t);
		timeinfo = localtime(&t);
		strftime(str, sizeof(str), "%T", timeinfo);
		my_printf("\x1b[1m\x1b[32m%s", str);
		my_printf(" \x1B[34m%s", getcwd(NULL, 0));
		my_printf(" \x1B[0m$> ");
	}
}

int	main_loop(char **envp, int end, char *str)
{
	env_st_t *env_st = init_env_struct(envp);

	bash_rc(env_st);
	prompt();
	while (!end) {
		str = (isatty(0) == 1) ? my_get_line(env_st->term, str,
		env_st->history) : my_getline();
		if (isatty(0) == 1 && str == NULL) {
			my_printf("exit\n");
			exit(0);
		}
		if (my_strlen(str) > 0) {
			main_b_tree(str, env_st, 0, 1);
		}
		else if (isatty(0) != 1)
			end = !end;
		prompt();
	}
	tcsetattr(0, TCSANOW, &(env_st->term->origin));
	return (env_st->status);
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	return (main_loop(envp, 0, NULL));
}
