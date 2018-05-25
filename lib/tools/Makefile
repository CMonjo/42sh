##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Library my
##

CC	=	gcc

CFLAGS	=	-g3 -Wall -Wextra -W -I ../../include/

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libtools.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
