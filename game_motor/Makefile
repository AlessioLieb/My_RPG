##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile for world
##

SRC	=	motor_s/move.c	\
		motor_s/basic_move.c	\
		motor_s/stone_base.c

LIB = -l csfml-graphics -O2 -lm -l csfml-audio	\
		-l csfml-system -l csfml-window -Wall

NAME	=	my_rpg

OBJ	=	$(SRC:.c=.o)

all: ${NAME}

$(NAME): $(OBJ)
	gcc  -o $(NAME) motor_s/*.o $(LIB)

debug :
	gcc -g motor_s/*.c $(LIB)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

git : fclean
	git add *
	git commit -m "norme and little fix"
	git push

re:	fclean all
