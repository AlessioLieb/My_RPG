##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	main.c	\
		tools.c	\
		map_gen.c	\
		reduce_map_gen.c	\
		tools2.c	\
		tools3.c	\
		map_gen2.c 	\
		verif_rooms.c	\
		reduce_boss.c

OBJ	=	$(SRC:.c=.o)

NAME	=	procedural_gen

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) *.o -lm -g

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
