/*
** EPITECH PROJECT, 2018
** unsetenv.c
** File description:
** unsetenv an value and name of the env
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

int	delet_val(char *str, char **envp, env_st_t* env_st)
{
	int ct = 0;
	int b = 0;

	while (envp[ct] != NULL && b == 0) {
		if (check_env(envp[ct], str) == 1) {
			env_st->ind = ct;
			env_st->len_h --;
			env_st->unset = 1;
			b = 1;
		}
		ct ++;
	}
	env_st->envp_cpy = copy_env(envp, env_st, 0);
	env_st->unset = 0;
	return (0);
}

int	unset_env(char **str, char **envp, env_st_t* env_st)
{
	int ct = 1;
	(void)envp;
	if (str[1] == NULL) {
		my_putstr_err(str[0], ": Too few arguments.\n");
		env_st->status = 1;
		return (0);
	}
	env_st->status = 0;
	while (str[ct] != NULL) {
		delet_val(str[ct], env_st->envp_cpy, env_st);
		ct ++;
	}
	return (0);
}
