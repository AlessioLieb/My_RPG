##
## EPITECH PROJECT, 2021
## runner
## File description:
## runner
##

SRC	=	sources/init_base.c						\
		sources/window.c 						\
		sources/main.c							\
		sources/main_func.c						\
		sources/create_sprites.c 				\
		sources/draw_sprites.c					\
		sources/factory_button.c				\
		sources/states_button.c					\
		sources/button.c						\
		sources/animation_framebuffer.c			\
		sources/init_choose_players.c			\
		sources/action_button.c					\
		sources/players_choose.c				\
		sources/framebuffer_play.c

OBJ	=    $(SRC:.c=.o)

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS += -g

NAME	=    my_rpg

all:    	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	gcc -o $(NAME) $(OBJ) $(FLAGS)