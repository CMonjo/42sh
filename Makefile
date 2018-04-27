##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for minishell1
##

CC = gcc

CFLAGS	=	-I./include -W -Wall -Wextra -lcriterion

CFLAGS += -g3

SRC	=	copy_env.c		\
		cd.c		\
		cat.c		\
		echo.c		\
		other.c		\
		main.c		\
		exec.c		\
		pipe.c		\
		repeat.c		\
		pipe_plus.c		\
		exec_red.c		\
		exec_path_red.c		\
		exit.c		\
		prompt.c		\
		cd_path.c		\
		grep.c		\
		unsetenv.c		\
		env_other.c		\
		path.c		\
		main_b_tree.c	\
		set_n_check.c	\
		fill_struct_pars.c		\
		epur_command.c		\
		check_command.c		\
		error_sep.c		\
		error_parent.c		\
		error_quotes.c		\
		error_long_sep.c		\
		start_error_sep.c		\
		right_red.c		\
		left_red.c		\
		start_sep.c		\
		start_double_sep.c		\


OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re:	fclean all
