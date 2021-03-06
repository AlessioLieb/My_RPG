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
		sources/animation_framebuffer3.c		\
		sources/init_choose_players.c			\
		sources/action_button.c					\
		sources/players_choose.c				\
		sources/framebuffer_play.c				\
		sources/create_sprites5.c				\
		sources/init_all_sprites.c				\
		sources/manage_rooms.c					\
		sources/manage_rooms2.c					\
		sources/create_sprites2.c				\
		sources/create_sprites3.c				\
		sources/create_sprites4.c				\
		sources/draw_doors.c					\
		sources/npc.c							\
		sources/func_button.c					\
		sources/func_button_sec.c				\
		sources/draw_sprites4.c					\
		sources/re_create_window.c				\
		sources/check_txt_player.c				\
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
		motor_s/other/reduce_place_stone.c		\
		motor_s/tears/tears_shooting.c			\
		motor_s/tears/tears_state.c				\
		motor_s/tears/check_tears_collision.c	\
		motor_s/other/recharge_room.c			\
		motor_s/other/item_description.c		\
		enemies/create_enemies.c				\
		enemies/enemies_room.c					\
		enemies/anim_enemies.c					\
		enemies/player_enemies.c				\
		enemies/shoot_enemies.c					\
		enemies/touch_enemy.c					\
		enemies/mov_enemies2.c					\
		enemies/init_specific_boss.c			\
		enemies/reduce_create_boss.c			\
		enemies/mov_enemies.c					\
		enemies/create_specific_boss.c			\
		enemies/anim_boss.c						\
		enemies/create_boss.c					\
		enemies/boss_bar.c						\
		procedural_generation/verif_rooms.c		\
		procedural_generation/gen_main.c		\
		procedural_generation/map_gen.c			\
		procedural_generation/map_gen2.c		\
		procedural_generation/reduce_boss.c		\
		procedural_generation/reduce_map_gen.c	\
		procedural_generation/tools.c			\
		procedural_generation/tools2.c			\
		procedural_generation/tools3.c			\
		collectibles/base_inventory.c			\
		collectibles/collectible_create.c		\
		collectibles/red_hearth.c				\
		collectibles/blue_hearth.c				\
		collectibles/item.c						\
		collectibles/item_fonctions.c			\
		collectibles/reduce_item_fonctions.c	\
		collectibles/all_stat.c					\
		collectibles/item_launching.c			\
		collectibles/reduce_item.c				\
		collectibles/specific_item.c			\
		collectibles/specific_item2.c			\
		collectibles/specific_item3.c			\
		collectibles/specific_item4.c			\
		collectibles/specific_item5.c			\
		collectibles/specific_item6.c			\
		mini_map/mini_map.c						\
		mini_map/reduce_mini_map.c				\
		mini_map/init_mini_map.c				\
		mini_map/reduce_draw_mini_map.c			\
		music/room_music.c						\
		music/play_sounds.c						\
		sources/draw_my_stuff.c	\
		collectibles/key_bombs.c	\
		motor_s/other/npc_actions.c	\
		motor_s/other/saler.c	\
		motor_s/other/clock_gestion.c


OBJ	=    $(SRC:.c=.o)

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS += -g

NAME	=    my_rpg


all:    	$(NAME)

debug:
	gcc -g $(SRC) $(FLAGS)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)
	make -C bonus

target:

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C bonus

re: fclean all
	gcc -o $(NAME) $(OBJ) $(FLAGS)
