/*
** EPITECH PROJECT, 2018
** copy_env.c
** File description:
** copy the env for the minishell1
*/

#include "main.h"

char **create_env(void)
{
	char **str;
	char *path = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin";
	char *path_two = ":/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	char *pwd_env = "PWD=";
	char *pwd;

	if ((pwd = my_getcwd(NULL, 0)) == NULL) {
		str = malloc(sizeof(char *) * 2);
		str[0] = my_strcat(path, path_two, 0);
		str[1] = NULL;
	} else {
		str = malloc(sizeof(char *) * 3);
		str[0] = my_strcat(path, path_two, 0);
		str[1] = my_strcat(pwd_env, pwd, 0);
		str[2] = NULL;
	}
	return (str);
}

int	get_len(char **envp, env_st_t* env_st, int ct)
{
	int ctp = 0;

	while (envp[ct][ctp] != '\0') {
		ctp ++;
	}
	env_st->len_w = ctp;
	return (ctp + 1);
}

char	*copy_str_env(char **envp, env_st_t* env_st, int ct)
{
	char *str = malloc(sizeof(char) * get_len(envp, env_st, ct));
	int ctp = 0;

	while (envp[ct][ctp] != '\0') {
		str[ctp] = envp[ct][ctp];
		ctp ++;
	}
	str[ctp] = '\0';
	return (str);

}

char	**copy_env(char **envp, env_st_t* env_st, int ct)
{
	char **env_env = malloc(sizeof(char *) * (env_st->len_h + 1));
	int b = 0;
	int ctb = 0;

	while (envp[ct] != NULL) {
		if (env_st->unset == 1 && ct == env_st->ind) {
			b = 1;
		}
		if (b == 0) {
			env_env[ctb] = copy_str_env(envp, env_st, ct);
			ctb ++;
		}
		b = 0;
		ct ++;
	}
	env_env[env_st->len_h] = NULL;
	return (env_env);
}
