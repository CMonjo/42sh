/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/scripting/scripting.c
*/

#include "main.h"

int	script_check_path_bsc(char **envp, char *name, UNUSED char **str_arr,
UNUSED env_st_t* env_st)
{
	int ct = 0;
	char *str;

	while (envp[0][ct] != '=')
		ct ++;
	ct ++;
	for (int ctb = ct; envp[0][ctb] != '\0'; ctb ++) {
		str = my_strcat(pathing(envp, &ctb, 0), name, 0);
		if (envp[0][ctb] == '\0')
			ct --;
		if (access(str, F_OK) != -1)
			return (1);
	}
	return (0);
}

int	script_path_command(char **envp, char *name,
	env_st_t* env_st, char **str_arr)
{
	int ct = 0;
	char *str;

	if (check_val(envp, "PATH", env_st) == 0) {
		if (script_check_path_bsc(env_st->envp_bsc,
		name, str_arr, env_st) == 1)
			return (1);
	}
	ct = check_same(envp, env_st);
	for (int ctb = ct; envp[env_st->ind][ctb] != '\0'; ctb ++) {
		str = my_strcat(pathing(envp, &ctb, env_st->ind), name, 0);
		if (envp[env_st->ind][ctb] == '\0')
			ctb --;
		if (access(str, F_OK) != -1)
			return (1);
	}
	return (0);
}

int	script_path(char *str, UNUSED env_st_t *env_st)
{
	if (access(str, F_OK) != -1) {
		return (1);
	}
	return (0);
}

int	script_command(char **envp, env_st_t* env_st, char *str)
{
	int b = 0;

	for (int ct = 0; str[ct] != '\0'; ct ++)
		if (str[ct] == '/')
			b = 1;
	if (b == 1) {
		if (script_path(str, env_st) == 1)
			return (1);
	} else if (script_path_command(envp, str, env_st, NULL) == 1)
		return (1);
	return (0);
}

int	check_sheebang_file(char **arr, char *str, int sheebang_len,
env_st_t* env_st)
{
	int arr_sheebang = arr_len(arr);
	int file_len = 0;
	char *check_sheebang_file;
	int ctb = 0;

	if (arr_sheebang > 1) {
		sheebang_len = sheebang_next(sheebang_len, str);
		file_len = sheebang_next_two(file_len, str, sheebang_len);
		check_sheebang_file = malloc(sizeof(char) * (file_len + 1));
		for (int ct = sheebang_len; str[ct] != '\0'; ct ++, ctb ++)
			check_sheebang_file[ctb] = str[ct];
		check_sheebang_file[file_len] = '\0';
		if (script_command(env_st->envp_cpy, env_st,
		check_sheebang_file) != 1) {
			my_printf("%s: «%s»: No such file or directory.\n",
			str, check_sheebang_file);
			return (0);
		}
	}
	return (0);
}