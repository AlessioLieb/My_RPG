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
		sources/draw_sprites2.c					\
		sources/draw_sprites3.c					\
		sources/factory_button.c				\
		sources/states_button.c					\
		sources/button.c						\
		sources/animation_framebuffer.c			\
		sources/animation_framebuffer2.c		\
		sources/init_choose_players.c			\
		sources/action_button.c					\
		sources/players_choose.c				\
		sources/framebuffer_play.c				\
		sources/manage_rooms.c					\
		sources/manage_rooms2.c					\
		sources/create_sprites2.c				\
		sources/create_sprites3.c				\
		motor_s/move.c	\
		motor_s/move2.c	\
		motor_s/basic_move.c	\
		motor_s/stone_base.c	\
		motor_s/reduce.c		\
		enemies/create_enemies.c	\
		enemies/enemies_room.c	\
		enemies/anim_enemies.c	\
		enemies/mov_enemies.c	\
		motor_s/tears_shooting.c	\
		motor_s/tears_state.c	\
		motor_s/check_tears_collision.c	\
		procedural_generation/gen_main.c	\
		procedural_generation/map_gen.c	\
		procedural_generation/map_gen2.c	\
		procedural_generation/reduce_boss.c	\
		procedural_generation/reduce_map_gen.c	\
		procedural_generation/tools.c	\
		procedural_generation/tools2.c	\
		procedural_generation/tools3.c	\
		procedural_generation/verif_rooms.c	\
		motor_s/life_gestion.c	\
		enemies/player_enemies.c	\
		collectibles/collectible_create.c	\
		collectibles/red_hearth.c	\
		collectibles/blue_hearth.c	\
		collectibles/base_inventory.c	\
		motor_s/int_str.c	\
		motor_s/base_hud.c	\
		enemies/shoot_enemies.c	\
		enemies/touch_enemy.c	\
		motor_s/stat_hud.c

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