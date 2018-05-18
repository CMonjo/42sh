/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/scripting/scripting_variables.c
*/

#include "main.h"

char	*first_part_str(char *str, int *ctb)
{
	char *str_one;

	for (int ct = 0; str[ct] != '$'; ct ++)
		(*ctb) ++;
	str_one = malloc(sizeof(char) * ((*ctb) + 1));
	for (int ct = 0; str[ct] != '$'; ct ++)
		str_one[ct] = str[ct];
	str_one[*ctb] = '\0';
	(*ctb) ++;
	return (str_one);
}

int	nbr_part_str(char *str, int *ctb)
{
	char *index;
	int nbr = 0;
	int ct_nbr = 0;

	for (int ct = (*ctb); (str[ct] >= '0' && str[ct] <= '9'); ct ++)
		nbr ++;
	index = malloc(sizeof(char) * (nbr + 1));
	for (int ct = (*ctb); (str[ct] >= '0' && str[ct] <= '9'); ct ++, ct_nbr ++)
		index[ct_nbr] = str[ct];
	index[nbr] = '\0';
	(*ctb) = (*ctb) + nbr;
	return (my_getnbr(index));
}

char	*load_variable(char *str, char **arr)
{
	char *str_one;
	int len_one = 0;
	int nbr = 0;
	int ct_nbr = 0;
	char *str_three;
	int len_three = 0;

	str_one = first_part_str(str, &len_one);
	nbr = nbr_part_str(str, &len_one);
	//printf("INDEX   : '%s'   LEN  : %d\n", index, len_one);
	for (int ct = len_one; str[ct] != '\0'; ct ++)
		len_three ++;
	str_three = malloc(sizeof(char) * (len_three + 1));
	for (int ct = len_one; str[ct] != '\0'; ct ++, ct_nbr ++)
		str_three[ct_nbr] = str[ct];
	str_three[len_three] = '\0';
	free(str);
	return (replace_variable_arr(str_one, str_three, arr, nbr));
}

char	*replace_variable(char *str, char **arr)
{
	for (int ct = 0; str[ct] != '\0';ct ++) {
		if (str[ct] == '$' && str[ct + 1] >= '0' && str[ct + 1] <= '9') {
			str = replace_variable(load_variable(str, arr), arr);
			ct = 0;
		}
	}
	return (str);
}

char	*replace_variable_arr(char *str_one, char *str_two,
char **arr, int index_arg)
{
	int nb_arg = 0;

	for (int ct = 0; arr[ct] != NULL; ct ++)
		nb_arg ++;
	if (index_arg >= nb_arg || arr[index_arg][0] == '$')
		return (my_strcat(str_one, str_two, 0));
	str_one = my_strcat(str_one, arr[index_arg], 0);
	return (my_strcat(str_one, str_two, 0));
}