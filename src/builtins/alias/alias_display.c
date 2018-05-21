/*
** EPITECH PROJECT, 2018
** alias.c
** File description:
** set alias in the sheel
*/

#include "main.h"

void	alias_display_arr(char **arr_bind, char **arr_dis, int ct, int ctb)
{
	if (ct == 1)
		my_printf("%s\t%s\n", arr_bind[ctb], arr_dis[ctb]);

}

void	alias_displaying(alias_t *tmp, int ct)
{
	//alias_t *tmp = env_st->alias;
	/*char *str_dis = malloc(sizeof(char) * 1);
	char *str_bind = malloc(sizeof(char) * 1);
	char **arr_dis;
	char **arr_bind;
	int ct = 0;*/

	//str_dis[0] = '\0';
	//str_bind[0] = '\0';
	while (tmp != NULL) {
		if (tmp->bind[0] == ct) {
			/*str_dis = my_strcat(str_dis, tmp->command_display);
			str_dis = my_strcat(str_dis, " ");
			str_bind = my_strcat(str_bind, tmp->bind);
			str_bind = my_strcat(str_bind, " ");*/
			my_printf("%s\t%s\n", tmp->bind, tmp->command_display);
			//my_printf("%s\n", tmp->command_display);
			//ct ++;
		}
		tmp = tmp->next;
	}
	/*if (str_dis[0] == '\0')
		return;
	arr_dis = word_array(str_dis);
	arr_bind = word_array(str_bind);
	if (ct > 1) {

	} else
		printf("%s")
	tmp = env_st->alias;*/
}

void alias_display(env_st_t *env_st)
{
	alias_t *tmp = env_st->alias;

	if (tmp != NULL)
		my_bubble(tmp);
	for (int ct = 0; ct != 126; ct ++)
		alias_displaying(tmp, ct);
}

void alias_compare(env_st_t *env_st, char *str)
{
	alias_t *tmp = env_st->alias;

	while (tmp != NULL) {
		if (my_strcmp(tmp->bind, str) == 0) {
			my_printf("%s\n", tmp->command_display);
			break;
		}
		tmp = tmp->next;
	}
}
