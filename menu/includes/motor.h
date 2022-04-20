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
    int total_life;
    int red_hearth;
    int blue_hearth;
    sfSprite *h_sp;
}life;

typedef struct player_s{
    sfSprite *sp;
    sfTexture *tx;
    life lf;
    int x;
    int y;
    int as_moved;
    int speed;
    int actual_sp;
    int invulnerability;
    sfVector2f actual_speed;
    sfImage *collision_box;
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
    sfSprite *sp;
    int actual_room;
    int len_stone;
    stone *st;
    sfImage *room_col;
    collectible *red_hearth;
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
    unsigned long timer_total;
    unsigned long timer;
}timer;

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
}reduce;

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
void player_room(sfRenderWindow *wd, reduce *red);
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
#endif
