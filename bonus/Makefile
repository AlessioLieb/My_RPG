##
## EPITECH PROJECT, 2021
## sokoban
## File description:
## Makefile
##

SRC	=	sources/main.c	\
		sources/reduce.c

OBJ	=    $(SRC:.c=.o)

FLAGS = -lncurses

CFLAGS += -Wall -g

NAME	=    map_editor_isaac

all:    	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)
clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f sources/*~
	rm -f unit_tests*

fclean: clean
	rm -f $(NAME)

re: fclean all
	gcc -o $(NAME) $(OBJ) $(FLAGS)
