##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for 42sh
##

CC	=	gcc

CFLAGS	=	-I./include -W -Wall -Wextra

CFLAGS +=	-g3

SRC	=	src/main.c		\
		src/error/error_alias.c		\
		src/exec.c		\
		src/exec_status.c		\
		src/pipe.c		\
		src/pipe_plus.c		\
		src/exec_red.c		\
		src/exec_path_red.c	\
		src/check_exec.c		\
		src/path.c		\
		src/main_b_tree.c	\
		src/set_n_check.c	\
		src/fill_struct_pars.c	\
		src/epur_command.c	\
		src/check_command.c	\
		src/check_command_bis.c	\
		src/right_red.c		\
		src/left_red.c		\
		src/my_getline.c		\
		src/start_sep.c		\
		src/start_double_sep.c	\
		src/start_double_sep_and_or.c	\
		src/remove_parent.c	\
		src/exit.c	\
		src/inib.c	\
		src/check_alias.c	\
		src/is_there_star.c	\
		src/error_main_b_tree.c	\
		src/variables/variables.c	\
		src/variables/variables_spe.c	\
		src/variables/variables_string.c	\
		src/error/error_variables.c	\
		src/my_arraydup.c	\
		src/builtins/builtins/builtins.c				\
		src/builtins/history/history_struct.c		\
		src/builtins/jobs/jobs.c		\
		src/builtins/if/if.c		\
		src/builtins/if/then.c		\
		src/builtins/if/if_comp.c		\
		src/builtins/if/if_comp_next.c		\
		src/builtins/if/if_next.c		\
		src/builtins/env/copy_env.c		\
		src/builtins/env/unsetenv.c		\
		src/builtins/env/env_other.c		\
		src/builtins/cd/cd.c			\
		src/builtins/cd/cd_path.c		\
		src/builtins/cat/cat.c			\
		src/builtins/end/end.c			\
		src/builtins/endif/endif.c			\
		src/builtins/which/which.c			\
		src/builtins/which/which_bis.c			\
		src/builtins/where/where.c			\
		src/builtins/where/where_bis.c			\
		src/builtins/foreach/foreach.c			\
		src/builtins/foreach/error_foreach.c			\
		src/builtins/foreach/foreach_bis.c			\
		src/builtins/echo/echo.c		\
		src/builtins/repeat/repeat.c		\
		src/builtins/set/set.c		\
		src/builtins/set/set_parsing.c		\
		src/builtins/set/set_display.c		\
		src/builtins/set/set_utils.c		\
		src/builtins/set/set_sort.c		\
		src/builtins/set/set_spaced.c		\
		src/builtins/set/unset.c		\
		src/builtins/grep/grep.c		\
		src/builtins/grep/grep_bis.c		\
		src/builtins/alias/unalias.c		\
		src/builtins/alias/alias.c		\
		src/builtins/alias/alias_parsing.c	\
		src/builtins/alias/alias_display.c	\
		src/builtins/exit/exit.c		\
		src/error/error_sep.c			\
		src/error/error_sep_bis.c			\
		src/error/error_parent.c		\
		src/error/error_quotes.c		\
		src/error/error_long_sep.c		\
		src/error/start_error_sep.c		\
		src/scripting/scripting.c		\
		src/scripting/scripting_variables.c		\
		src/builtins/alias/alias_sort.c		\
		src/verif_parent.c			\
		src/verif_parent_next.c			\
		src/select_env.c			\
		src/globbing/glob_execution.c	\
		src/globbing/bracket.c	\
		src/globbing/inter.c	\
		src/globbing/star.c	\
		src/builtins/yes/yes.c				\
		src/rm_first_arr.c			\
		src/check_built_pass.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/tools
	$(CC) -o $(NAME) $(OBJ) -L./lib/tools -ltools

clean:
	rm -f $(OBJ)
	make clean -C ./lib/tools

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/tools

re:	fclean all
