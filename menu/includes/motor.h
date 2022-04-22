/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** run
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/System/Export.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
    #include <math.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <stddef.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #define HEIGHT 1080
    #define WIDTH 1920
    #include "../includes/menu.h"
    #include "procedural.h"

typedef struct {
    unsigned long timer_total;
    unsigned long timer;
}timer;

typedef struct {
    int total_life;
    int red_hearth;
    int blue_hearth;
    sfSprite *h_sp;
}life;

typedef struct {
    int money;
    int bomb;
    int key;
}inventory;

typedef struct {
    int speed;
    int shot_speed;
    int damages;
    int freq_tears;
    int luck;
}stats;

typedef struct {
    bool key_q;
    bool key_z;
    bool key_s;
    bool key_d;
    bool key_left;
    bool key_up;
    bool key_right;
    bool key_down;
}event_key;

typedef struct player_s{
    event_key player_key;
    sfSprite *sp;
    sfTexture *tx;
    life lf;
    inventory invent;
    stats st;
    int x;
    int y;
    int as_moved;
    int speed;
    int actual_sp;
    int invulnerability;
    sfVector2f actual_speed;
    sfImage *collision_box;
    timer move_timer;
    timer anim_timer;
    timer tears_timer;
    sfClock *time;
}player;

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
    int nb_stone;
}stone;

typedef struct {
    sfSprite *sp;
    sfIntRect pos_collision;
    int (*change)(player *py);
}collectible;

typedef struct {
    sfSprite *fo;
    sfSprite *ft;
    sfSprite *fl;
    int *actual_room;
    int len_stone;
    bool open;
    stone *st;
    sfImage *room_col;
    collectible *red_hearth;
    collectible *blue_hearth;
    collectible *piece;
}room;

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
    bool is_shooting;
    bool is_flying;
    int pv;
    int speed;
}adv_t;

typedef struct {
    timer ti;
    timer move_ti;
    sfClock *total_clock;
    adv_t *no_moving_adv;
    adv_t *big_adv;
    adv_t *flying_adv;
    adv_t *little_adv;
    adv_t *wall_adv;
}enemies_t;

typedef struct {
    sfSprite *t_sp;
    sfTexture *t_tx;
    int x;
    int y;
    bool is_shot;
    bool move;
    float speed;
    int actual_sp;
    int direction;
}tears;

typedef struct {
    player *py;
    room *rm;
    tears *te;
    enemies_t *enem_t;
    rooms *ro;
}reduce;

void reduce_move_player_check(reduce *red);
void init_player(player *py);
void key_action_pressed(sfEvent event, reduce *red);
void draw_room(sfRenderWindow *wd, reduce *red, rooms *ro);
void player_room(sfRenderWindow *wd, reduce *red, options *sprt);
int move_sprite(player *py, int top, room *rm);
void move_event(sfEvent event, reduce *red);
void move_player_check(reduce *red);
void floor_pass(rooms *ro, reduce *red, options *sprt);
void doors_colisions(options *sprt, room *rm, player *py);
void init_rm_sprt(room *rm, options *sprt);
void move_player_check(reduce *red);
int check_move_right(player *py, room *rm);
void draw_doors_topo(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_righto(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_lefto(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_boto(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_topc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_rightc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_leftc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_botc(int lvl, options *sprt, sfRenderWindow *wd, char c);
bool touched_enemy(reduce *red, int i, char c);
bool touch_enemy(sfVector2f tears_pos, reduce *red);
void nb_time_hud(long time, sfRenderWindow *wd);
void nb_bomb_hud(int bomb, sfRenderWindow *wd);
void nb_key_hud(int key, sfRenderWindow *wd);
int str_len(char const *str);
char *str_concat(char *str, char *concat);
void nb_piece_hud(int piece, sfRenderWindow *wd);
char *my_int_str(unsigned long long nb);
void launch_piece(player *py, room *rm, int i);
inventory create_inventory(void);
collectible *create_piece(sfTexture *text);
void got_blue_hearth(room *rm, int i, player *py);
collectible *create_blue_hearth(sfTexture *text);
void got_hearth(room *rm, int i, player *py);
void draw_life(player *py, sfRenderWindow *rd);
void draw_bonus(room *rm, sfRenderWindow *wd, player *py);
void place_bonus(room *rm);
collectible *create_red_hearth(sfTexture *text);
life create_life(void);
void touch_player_enemy(adv_t adv, sfVector2f player_pos, player *py);
void move_enemies(enemies_t *enem_t, player *py, room *rm);
void reduce_init_fly(int i, adv_t *adv);
void reduce_init_big(int i, adv_t *adv);
void reduce_init_nomov(int i, adv_t *no_mov, sfVector2f scale, sfIntRect place);
bool collision_stone_tears(reduce *red, int x, int y, int nb);
void move_enemies(enemies_t *enem_t, player *py, room *rm);
enemies_t *create_enemies(void);
void place_enemies(char *str, enemies_t *enem_t);
void draw_enemies(enemies_t *enem_t, sfRenderWindow *wndw,
player *py, room *rm);
void anim_enemies(enemies_t *enem_t);
int event_window(window *wndw, options *sprt, reduce *red);
void player_room(sfRenderWindow *wd, reduce *red, options *sprt);
player *creation_player(void);
room *create_room(char *str);
void move_event(sfEvent event, reduce *red);
bool collision_stone(room *rm, player *py, int x, int y);
void draw_stone(room *rm, sfRenderWindow *wd);
void place_stone(room *rm, player *py, char *str);
stone *create_stone(char *str);
int move_sp_top(player *py, int top, room *rm);

tears *create_tears(player *py);
tears *init_st_array(tears *te, sfIntRect r, player *py);
int event_tears(window *win, options *sprt, room *rm, tears *te);
void shoot_tears(int id, reduce *red);
void move_tears(int id, reduce *red, sfRenderWindow *wd);

int verif_moving(reduce *red, int nb_tears);
int verif_shooting(reduce *red, int nb_tears);
void disp_tears(reduce *red, sfRenderWindow *wd);
int check_collisions(int id, reduce *red, int nb);

void draw_doors(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt);

stats create_stats(void);
void disp_stat_hud(reduce *red, sfRenderWindow *wd);

#endif
