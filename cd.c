/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for the cd func
*/

#include "my.h"

char	*my_getcwd(char *str, int ctb)
{
	int b = 0;

	while (b == 0 && ctb < 350) {
		str = getcwd(str, ctb);
		if (str != NULL)
			b = 1;
		ctb ++;
	}
	return (str);
}

char	*get_path(char **envp, env_st_t *env_st, int ct)
{
	char *str;
	int ctp = ct;
	int len = 0;

	while (envp[env_st->ind][ctp] != '\0') {
		len ++;
		ctp ++;
	}
	ctp = 0;
	str = malloc(sizeof(char) * (len + 2));
	while (envp[env_st->ind][ct] != '\0') {
		str[ctp] = envp[env_st->ind][ct];
		ct ++;
		ctp ++;
	}
	str[ctp] = '/';
	str[ctp + 1] = '\0';
	return (str);
}

int	change_env(char *pwd, char *oldpwd, int b, env_st_t *env_st)
{
	char *str_pwd[4] = {"cd", "PWD", pwd, NULL};
	char *str_oldpwd[4] = {"cd", "OLDPWD", oldpwd, NULL};

	if (b == 0) {
		set_env(str_oldpwd, env_st->envp_cpy, env_st);
	}
	if (b == 1) {
		set_env(str_pwd, env_st->envp_cpy, env_st);
	}
	return (0);
}

int	error_oldpwd(char **str, int cd_min, env_st_t *env_st)
{
	if (env_st->cd_abl != 1) {
		my_putstr_err(NULL, ": No such file or directory.\n");
		env_st->status = 1;
		return (1);
	}
	if (str[1][1] != '-' && str[1][1] != '\0') {
		my_putstr_err(NULL, "Usage: cd [-plvn][-|<dir>].\n");
		env_st->status = 1;
		return (1);
	}
	if (cd_min == 0) {
		my_putstr_err(NULL, ": No such file or directory.\n");
		env_st->status = 1;
		return (1);
	}
	return (0);
}

int	cd(char **str, char **envp, env_st_t *env_st)
{
	char *env_oldwd = "OLDPWD";
	int cd_min = 0;

	if (cd_home(str, envp, env_st, 0) == 1)
		return (0);
	cd_min = check_val(envp, env_oldwd, env_st);
	if (str[1][0] == '-') {
		cd_oldpwd(str, envp, env_st, cd_min);
		return (0);
	}
	cd_pwd(str, env_st);
	return (0);
}
