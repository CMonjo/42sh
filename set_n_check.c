/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** the main file of mini1
*/

#include "my.h"

int	check_val(char **envp, char *name, env_st_t* env_st)
{
	int ct = 0;
	int b = 0;

	if (envp == NULL)
		return (0);
	while (envp[ct] != NULL && b == 0) {
		if (check_env(envp[ct], name) == 1) {
			env_st->ind = ct;
			b = 1;
		}
		ct ++;
	}
	return (b);
}

int	check_name(char **str, env_st_t* env_st)
{
	int ct = 0;
	int b = 0;

	while (str[1][ct] != '\0') {
		if ((str[1][ct] > 47 && str[1][ct] < 58) || str[1][ct] == '_')
			b = 1;
		if (b == 0 && (str[1][ct] < 65 ||
		(str[1][ct] > 90 && str[1][ct] < 97)
			|| str[1][ct] > 122)) {
			my_putstr_err(NULL, "setenv: Variable name must cont");
			my_putstr_err(NULL, "ain alphanumeric characters.\n");
			env_st->status = 1;
			return (-1);
		}
		b = 0;
		ct ++;
	}
	return (0);
}

char	**unset_env_name(char **str, char **envp, env_st_t* env_st)
{
	int ct = 0;
	char **new_env = copy_env(envp, env_st, 0);
	char *str_tmp;

	free(new_env[env_st->ind]);
	new_env[env_st->ind] = malloc(sizeof(char)
				* (my_strlen(str[1]) + my_strlen(str[2])) + 2);
	str_tmp = maloc_str(0, 0, 0, str);
	str_tmp[(my_strlen(str[1]) + my_strlen(str[2]) + 1)] = '\0';
	while (str_tmp[ct] != '\0') {
		new_env[env_st->ind][ct] = str_tmp[ct];
		ct ++;
	}
	new_env[env_st->ind][ct] = '\0';
	env_st->envp_cpy = new_env;
	return (new_env);
}

int	set_name(char **str, char **envp, env_st_t* env_st)
{
	int ct = 0;
	char **new_env;

	env_st->len_h ++;
	new_env = copy_env(envp, env_st, 0);
	new_env[env_st->len_h - 1] = malloc(sizeof(char)
					* (my_strlen(str[1]) + 2));
	while (str[1][ct] != '\0') {
		new_env[env_st->len_h - 1][ct] = str[1][ct];
		ct ++;
	}
	new_env[env_st->len_h - 1][ct] = '=';
	new_env[env_st->len_h - 1][ct + 1] = '\0';
	env_st->envp_cpy = new_env;
	return (0);
}

int	set_name_value(char **str, char **envp, env_st_t* env_st)
{
	int ct = 0;
	char **new_env;
	char *str_tmp;

	new_env = copy_env(envp, env_st, 0);
	new_env[env_st->len_h - 1] = malloc(sizeof(char)
				* (my_strlen(str[1]) + my_strlen(str[2])) + 2);
	str_tmp = maloc_str(0, 0, 0, str);
	str_tmp[(my_strlen(str[1]) + my_strlen(str[2]) + 1)] = '\0';
	while (str_tmp[ct] != '\0') {
		new_env[env_st->len_h - 1][ct] = str_tmp[ct];
		ct ++;
	}
	new_env[env_st->len_h - 1][ct] = '\0';
	env_st->envp_cpy = new_env;
	return (0);
}
