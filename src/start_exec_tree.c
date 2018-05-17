/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** src/start_exec_tree.c
*/

#include "main.h"

tree_exe_t const tab_sep_ex_b[] = {{"cd", cd}, {"env", env},
			{"exit", exit_env}, {"setenv", set_env},
			{"unsetenv", unset_env}, {"alias", alias},
			{"echo", echo}, {"repeat", repeat}, {"which", which},
			{"where", where}, {"foreach", foreach}, {"end", end},
			{"cat", cat}, {"grep", grep}};

int	 start_exec_tree_try(char **arr,
tree_t* temp, env_st_t *env_st)
{

}