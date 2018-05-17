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
		src/error_alias.c		\
		src/exec.c		\
		src/pipe.c		\
		src/pipe_plus.c		\
		src/exec_red.c		\
		src/exec_path_red.c	\
		src/prompt.c		\
		src/path.c		\
		src/main_b_tree.c	\
		src/set_n_check.c	\
		src/fill_struct_pars.c	\
		src/epur_command.c	\
		src/check_command.c	\
		src/right_red.c		\
		src/left_red.c		\
		src/start_sep.c		\
		src/start_double_sep.c	\
		src/star.c	\
		src/builtins/env/copy_env.c		\
		src/builtins/env/unsetenv.c		\
		src/builtins/env/env_other.c		\
		src/builtins/cd/cd.c			\
		src/builtins/cd/cd_path.c		\
		src/builtins/cat/cat.c			\
		src/builtins/end/end.c			\
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
		src/builtins/set/set_display.c		\
		src/builtins/set/set_parsing.c		\
		src/builtins/grep/grep.c		\
		src/builtins/alias/alias.c		\
		src/builtins/alias/alias_parsing.c	\
		src/builtins/alias/alias_display.c	\
		src/builtins/exit/exit.c		\
		src/error/error_sep.c			\
		src/error/error_parent.c		\
		src/error/error_quotes.c		\
		src/error/error_long_sep.c		\
		src/error/start_error_sep.c		\
		src/scripting/scripting.c		\

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
