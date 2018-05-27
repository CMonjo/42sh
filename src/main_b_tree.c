/*
** EPITECH PROJECT, 2017
** BTREE
** File description:
** main.c
*/

#include "main.h"

char const *tab_name[] = {";", "||", "&&", "<<", ">>", "|", "<", ">", "(", ")"};

void	check_path_pip(char **envp, char *name,
	env_st_t* env_st, char **str_arr)
{
	int ct = 0;
	char *str;

	if (check_val(envp, "PATH", env_st) == 0) {
		check_path_bsc(name, str_arr, env_st, NULL);
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

void	start_fill_tree(tree_t* temp, env_st_t *env_st)
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
		check_gnl(temp->commande_parseur, env_st->envp_cpy,
		env_st, temp);
	if (temp->left != NULL)
		start_fill_tree(temp->left, env_st);
	if (temp->right != NULL)
		start_fill_tree(temp->right, env_st);
}

/*void	my_printf_te(tree_t* temp)
{
	char **arr = NULL;

	arr = word_array(temp->commande_parseur);
	printf(" COMMANDE  '%s'\n", arr[0]);
	if (temp->left != NULL)
		my_printf_te(temp->left);
	if (temp->right != NULL)
		my_printf_te(temp->right);
}*/

int	main_b_tree_check_strat(char *str, env_st_t *info)
{
	char *command;
	char **arr;

	if ((arr = word_array(str)) == NULL)
		return (1);
	if (check_special_case(str) == 1 || check_long_sep(str) == 1) {
		command = check_command(str, 0);
		fill_history(info, command);
		return (1);
	}
	return (0);
}

int	main_b_tree(char *str, env_st_t *info, int fd_in, int fd_out)
{
	tree_t* temp;
	char *command;

	if (main_b_tree_check_strat(str, info) == 1)
		return (0);
	command = check_command(str, 0);
	fill_history(info, command);
	if (word_array(command) == NULL || error_parent(command) == 1)
		return (1);
	command = too_much_parent(command);
	if (error_null_parent(word_array(command)) == 1)
		return (1);
	temp = my_list_command(command, info, fd_in, fd_out);
	/*printf("\n--------------TREEE  ----------\n\n");
	my_printf_te(temp);
	printf("--------------TREEE-------------\n\n");*/
	if (error_main_b_tree(command, info, temp) == 1)
		return (1);
	start_fill_tree(temp, info);
	return (0);
}
