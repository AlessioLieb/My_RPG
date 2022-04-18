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
		sources/framebuffer_play.c				\
		motor_s/move.c	\
		motor_s/basic_move.c	\
		motor_s/stone_base.c	\
		enemies/create_enemies.c	\
		enemies/enemies_room.c

OBJ	=    $(SRC:.c=.o)

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS += -g

NAME	=    my_rpg

all:    	$(NAME)

debug:
	gcc -g $(SRC) $(FLAGS)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	gcc -o $(NAME) $(OBJ) $(FLAGS)