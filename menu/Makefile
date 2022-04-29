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
		sources/create_sprites4.c				\
		sources/draw_doors.c					\
		sources/npc.c							\
		motor_s/hud/base_hud.c					\
		motor_s/hud/stat_hud.c					\
		motor_s/moves/move.c					\
		motor_s/moves/move2.c					\
		motor_s/moves/basic_move.c				\
		motor_s/moves/reduce_basic_move.c		\
		motor_s/other/stone_base.c				\
		motor_s/other/reduce.c					\
		motor_s/other/int_str.c					\
		motor_s/other/life_gestion.c			\
		motor_s/tears/tears_shooting.c			\
		motor_s/tears/tears_state.c				\
		motor_s/tears/check_tears_collision.c	\
		enemies/create_enemies.c				\
		enemies/enemies_room.c					\
		enemies/anim_enemies.c					\
		enemies/mov_enemies.c					\
		procedural_generation/gen_main.c		\
		procedural_generation/map_gen.c			\
		procedural_generation/map_gen2.c		\
		procedural_generation/reduce_boss.c		\
		procedural_generation/reduce_map_gen.c	\
		procedural_generation/tools.c			\
		procedural_generation/tools2.c			\
		procedural_generation/tools3.c			\
		procedural_generation/verif_rooms.c		\
		enemies/player_enemies.c				\
		enemies/shoot_enemies.c					\
		enemies/touch_enemy.c					\
		enemies/mov_enemies2.c					\
		enemies/init_specific_boss.c			\
		collectibles/collectible_create.c		\
		collectibles/red_hearth.c				\
		collectibles/blue_hearth.c				\
		collectibles/base_inventory.c			\
		enemies/create_specific_boss.c			\
		enemies/anim_boss.c						\
		enemies/create_boss.c					\
		enemies/boss_bar.c						\
		motor_s/other/recharge_room.c			\
		mini_map/mini_map.c						\
		mini_map/reduce_mini_map.c				\
		mini_map/init_mini_map.c				\
		mini_map/reduce_draw_mini_map.c			\
		collectibles/item.c						\
		collectibles/item_fonctions.c			\
		collectibles/reduce_item_fonctions.c	\
		collectibles/all_stat.c					\
		music/room_music.c	\
		collectibles/item_launching.c


OBJ	=    $(SRC:.c=.o)

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS += -g -Wall -Wextra

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
