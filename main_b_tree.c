/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** main.c
*/

#include "my.h"

char const *tab_name[] = {";", "||", "&&", "<<", ">>", "|", "<", ">", "(", ")"};

void	check_path_pip(char **envp, char *name,
	env_st_t* env_st, char **str_arr)
{
	int ct = 0;
	char *str;

	if (check_val(envp, "PATH", env_st) == 0) {
		check_path_bsc(env_st->envp_bsc, name, str_arr, env_st);
		return;
	}
	ct = check_same(envp, env_st);
	for (int ctb = ct; envp[env_st->ind][ctb] != '\0'; ctb ++) {
		str = my_strcat(pathing(envp, &ctb, env_st->ind), name, 0);
		if (envp[env_st->ind][ctb] == '\0')
			ctb --;
		if (access(str, F_OK) != -1) {
			return;
		}
	}
	if (check_bult_in(name) == -1) {
		my_putstr_err(str_arr[0], ": Command not found.\n");
		env_st->status = 1;
	}
}

int	exit_value(char *command_in, char *command_out)
{
	char **arr = word_array(command_in);
	char **arr_two = word_array(command_out);
	int val = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++) {
		if (my_strcmp(arr[ct], "exit") == 0 && arr[ct + 1] == NULL)
			val = 0;
		if (my_strcmp(arr[ct], "exit") == 0 && arr[ct + 1] != NULL)
			val = my_getnbr(arr[ct + 1]);
	}
	for (int ct = 0; arr_two[ct] != NULL; ct ++) {
		if (my_strcmp(arr[ct], "exit") == 0 && arr[ct + 1] == NULL)
			val = 0;
		if (my_strcmp(arr[ct], "exit") == 0 && arr[ct + 1] != NULL)
			val = my_getnbr(arr[ct + 1]);
	}
	return (val);
}

void	my_printf_tree(tree_t* temp, env_st_t *env_st)
{
	char **arr;
	int boul = 0;
	int b = 0;

	arr = word_array(temp->commande_parseur);
	for (int ct = 0; tab_name[ct] != NULL; ct ++)
		if (my_strcmp_c(arr[0], tab_name[ct]) == 0)
			boul = 1;
	first_simple_or_sep(arr, temp, env_st, &b);
	if (b != 0)
		return;
	if (boul == 0)
		check_gnl(temp->commande_parseur, env_st->envp_cpy, env_st);
	if (temp->left != NULL)
		my_printf_tree(temp->left, env_st);
	if (temp->right != NULL)
		my_printf_tree(temp->right, env_st);
}

void	my_printf_te(tree_t* temp)
{
	char **arr;

	arr = word_array(temp->commande_parseur);
	//printf(" COMMANDE  '%s'\n", arr[0]);
	if (temp->left != NULL)
		my_printf_te(temp->left);
	if (temp->right != NULL)
		my_printf_te(temp->right);
}

void	my_printf_history(history_t* temp)
{
	while (temp != NULL) {
		printf("HISTORY : %s\n", temp->command);
		temp = temp->next;
	}
}

void	fill_history(env_st_t *info, char *str)
{
	//history_t *temp = info->history;
	history_t* new_ele = malloc(sizeof(history_t));

	new_ele->command = my_strdup(str);
	new_ele->next = info->history;
	info->history = new_ele;
}

int	check_special_case(str)
{
	char **arr = word_array(str);
	int str_arr = 0;

	while (arr[str_arr] != NULL)
		str_arr ++;
	if (str_arr != 1)
		return (0);
	for (int ct = 0; arr[0][ct] != '\0'; ct ++)
		if (arr[0][ct] != ';' && arr[0][ct] != '&')
			return (0);
	exit(0);
	return (0);
}

int	main_b_tree(char *str, env_st_t *info)
{
	tree_t* temp;
	char *command;
	char **arr;

	if ((arr = word_array(str)) == NULL)
		return (0);
	check_special_case(str);
	command = check_command(str, 0);
	error_parent(command);
	fill_history(info, command);
	/*printf("\n--------------HISTORY----------\n\n");
	my_printf_history(info->history);
	printf("\n--------------HISTORY----------\n\n");*/
	temp = my_list_command(command, info);
	/*printf("\n--------------TREEE----------\n\n");
	my_printf_te(temp);
	printf("--------------TREEE-------------\n\n");*/
	if (start_error_tree(temp, 0) == 1) {
		info->status = 1;
		return (1);
	}
	if (start_error_tree(temp, 1) == 1) {
		info->status = 1;
		return (1);
	}
	my_printf_tree(temp, info);
	return (0);
}
