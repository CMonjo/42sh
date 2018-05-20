/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/builtins/if/if.c
*/

#include "main.h"

if_t const tab_if_sep[] = {
	{"==", if_equal},
	{">=", if_equal_sup},
	{"<=", if_equal_inf},
	{"<", if_inf},
	{">", if_sup},
};

char	*if_command(char **arr)
{
	char *command;
	int ct = 0;

	while (arr[ct][0] != ')')
		ct ++;
	command = my_strdup(arr[ct + 1]);
	for (int ctb = ct + 2; arr[ctb] != NULL; ctb ++) {
		command = my_strcat(command, " ",0);
		command = my_strcat(command, arr[ctb], 0);
	}
	//printf("COMMANDE  :%s\n", command);
	return (command);
}

int	error_if_syntax(char **arr, env_st_t *env_st)
{
	int b = 0;

	for (int ct = 2; arr[ct][0] != ')'; ct ++)
		b ++;
	if (b == 0)
		return (1);
	if (b == 1) {
		if (arr[2][0] >= '0' && arr[2][0] <= '9') {
			for (int ct = 0; arr[2][ct] != '\0'; ct ++)
				if (arr[2][ct] < '0' || arr[2][ct] > '9') {
					env_st->status = 1;
					my_printf("if: Badly formed number.\n");
					return (1);
				}
			main_b_tree(if_command(arr), env_st, 0, 1);
		} else {
			env_st->status = 1;
			my_printf("if: Expression Syntax.\n");
			return (1);
		}
		//LANCER LA FUNC MAIN_B_TREE
		return (1);
	}
	if (b == 2) {
		env_st->status = 1;
		my_printf("if: Expression Syntax.\n");
		return (1);
	}
	return (0);
}

int	error_if(char **arr, env_st_t *env_st)
{
	int ct = 0;

	if (arr[1] == NULL) {
		env_st->status = 1;
		my_printf("if: Too few arguments.\n");
		return (1);
	}
	while (arr[ct][0] != ')')
		ct ++;
	if (arr[ct + 1] == NULL) {
		env_st->status = 1;
		my_printf("if: Empty if.\n");
		return (1);
	}
	return (0);
}

int	if_build(char **arr, char **envp, env_st_t *env_st)
{
	int b = 0;
	char *sep = malloc(sizeof(char) * 1);
	int ct = 3;

	if (error_if(arr, env_st) == 1 || error_if_syntax(arr, env_st) == 1)
		return (1);
	if (arr[1][0] != '(')
		return (0);
	sep[0] = '\0';
	while (arr[ct + 1][0] != ')') {
		sep = my_strcat(sep, arr[ct], 0);
		ct ++;
	}
	//printf("no error    ARR   :   %s\n", sep);
	for (int ct = 0; ct != 5; ct ++)
		if (my_strcmp(sep, tab_if_sep[ct].name) == 0) {
			if ((tab_if_sep[ct].name_str)(arr[2], arr[ct]) == 0)
				main_b_tree(if_command(arr), env_st, 0, 1);
			b ++;
		}
	if (b == 0) {
		env_st->status = 1;
		my_printf("if: Expression Syntax.\n");
		return (1);
	}
	return (0);
}