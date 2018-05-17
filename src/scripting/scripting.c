/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/scripting/scripting.c
*/

#include "main.h"

int	script_check_path_bsc(char **envp, char *name, UNUSED char **str_arr,
env_st_t* env_st)
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

int	script_path(char *str, env_st_t *env_st)
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

int	check_sheebang_file(char **arr, char *str, int sheebang_len, env_st_t* env_st)
{
	int arr_sheebang = 0;
	int file_len = 0;
	char *check_sheebang_file;
	int ctb = 0;
	int fd = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		arr_sheebang ++;
	if (arr_sheebang > 1) {
		for (int ct = sheebang_len; str[ct] == '\t' || str[ct] == ' '; ct ++)
			sheebang_len ++;
		for (int ct = sheebang_len; str[ct] != '\0'; ct ++)
			file_len ++;
		check_sheebang_file = malloc(sizeof(char) * (file_len + 1));
		for (int ct = sheebang_len; str[ct] != '\0'; ct ++, ctb ++)
			check_sheebang_file[ctb] = str[ct];
		check_sheebang_file[file_len] = '\0';
		if (script_command(env_st->envp_cpy, env_st, check_sheebang_file) != 1) {
			my_printf("%s: «%s»: No such file or directory.\n",
			str, check_sheebang_file);
			return (0);
		}
		/*if ((fd = open(check_sheebang_file, O_RDWR, 0666)) == -1) {
			my_printf("%s: «%s»: No such file or directory.\n",
			str, check_sheebang_file);
			return (0);
		}*/
	}
	return (0);
}

int	check_sheebang(char *str, char *file, env_st_t* env_st)
{
	int len_sheebang = 0;
	char *sheebang;
	int ctb = 0;
	int start = 1;
	//char *sheebang = malloc(sizeof(char) * (my_strlen(str) - 2));

	if (my_strlen(str) > 2 && str[1] == '!')
		start ++;
	for (int ct = start; str[ct] != '\0' && str[ct] != ' '; ct ++)
		len_sheebang ++;
	sheebang = malloc(sizeof(char) * (len_sheebang + 1));
	for (int ct = start; str[ct] != '\0' && str[ct] != ' '; ct ++, ctb ++) {
		sheebang[ctb] = str[ct];
	}
	sheebang[len_sheebang] = '\0';
	if (access(sheebang, F_OK) == -1) {
		my_printf("%s: Command not found.\n", file);
		return (1);
	}
	if (check_sheebang_file(word_array(str), str, len_sheebang + start, env_st) == 1)
		return (1);
	return (0);
}

char	*replace_variable_arr(char *str_one, char *str_two, char **arr, int index_arg)
{
	int nb_arg = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		nb_arg ++;
	if (index_arg >= nb_arg || arr[index_arg][0] == '$')
		return (my_strcat(str_one, str_two, 0));
	str_one = my_strcat(str_one, arr[index_arg], 0);
	return (my_strcat(str_one, str_two, 0));
}

char	*load_variable(char *str, char **arr, int ct)
{
	char *str_one;
	int len_one = 0;
	char *index;
	int nbr = 0;
	int ct_nbr = 0;
	char *str_two;
	int len_two = 0;
	char *str_three;
	int len_three = 0;

	for (int ct = 0; str[ct] != '$'; ct ++)
		len_one ++;
	str_one = malloc(sizeof(char) * (len_one + 1));
	for (int ct = 0; str[ct] != '$'; ct ++)
		str_one[ct] = str[ct];
	str_one[len_one] = '\0';
	//printf("ONE   : '%s'\n", str_one);
	len_one ++;
	for (int ct = len_one; (str[ct] > '0' && str[ct] < '9'); ct ++)
		nbr ++;
	index = malloc(sizeof(char) * (nbr + 1));
	for (int ct = len_one; (str[ct] > '0' && str[ct] < '9'); ct ++, ct_nbr ++)
		index[ct_nbr] = str[ct];
	index[nbr] = '\0';
	nbr = my_getnbr(index);
	len_one = len_one + nbr;
	ct_nbr = 0;
	//printf("INDEX   : '%s'   LEN  : %d\n", index, len_one);
	for (int ct = len_one; str[ct] != '\0'; ct ++)
		len_three ++;
	str_three = malloc(sizeof(char) * (len_three + 1));
	for (int ct = len_one; str[ct] != '\0'; ct ++, ct_nbr ++)
		str_three[ct_nbr] = str[ct];
	str_three[len_three] = '\0';
	//printf("THREE   : '%s'\n", str_three);
	free(str);
	//printf("STR ONE :  '%s'    NBR  : %d     STR TWO   :   '%s'\n", str_one, nbr, str_three);
	//str= my_strcat(str_one, arr[nbr], 0);
	//str = my_strcat(str, str_three, 0);
	//printf("COMMANDE :  %s\n", str);
	return (replace_variable_arr(str_one, str_three, arr, nbr));
}

char	*replace_variable(char *str, char **arr)
{
	for (int ct = 0; str[ct] != '\0';ct ++) {
		if (str[ct] == '$' && str[ct + 1] > '0' && str[ct + 1] < '9') {
			//printf("-----------  '%s'  -----------\n", str);
			str = replace_variable(load_variable(str, arr, ct), arr);
			//printf("----------------------\n");
			ct = 0;
		}
	}
	return (str);
}

void	start_exec_script(char **arr, FILE *fd, env_st_t* env_st)
{
	int line = 0;
	size_t size = 0;
	char *str = NULL;
	int readed = 0;

	while ((readed = getline(&str, &size, fd)) > 0) {
		str[readed] = '\0';
		if (my_strlen(str) > 1) {
			str = replace_variable(str, arr);
			printf("STR  '%s\n", str);
			main_b_tree(str, env_st, 0, 1);
		}
		line ++;
	}
}

int	check_elf(char *str, char **arr, FILE *fd, env_st_t* env_st)
{
	int len_sheebang = 0;
	char *sheebang;
	int ctb = 0;
	//char *sheebang = malloc(sizeof(char) * (my_strlen(str) - 2));

	if (my_strlen(str) >= 4 && str[1] == 'E'
	&& str[2] == 'L' && str[3] == 'F')
		return (0);
	else if (str[0] == '#' && check_sheebang(str, arr[0], env_st) == 1)
		return (1);
	start_exec_script(arr, fd, env_st);
	return (1);
}

int	scripting(char **arr, char **arr_val, char **envp, env_st_t* env_st)
{
	int fd = 0;
	size_t size = 0;
	char *str = NULL;
	int readed = 0;
	FILE *fd_script = 0;

	fd = open(arr[0], O_RDONLY);
	if (fd == -1)
		return (1);
	fd_script = fdopen(fd, "rw");
	readed = getline(&str, &size, fd_script);
	str[readed - 1] = '\0';
	if (readed > 1 && check_elf(str, arr_val, fd_script, env_st) == 1)
		return (1);
	return (0);
}