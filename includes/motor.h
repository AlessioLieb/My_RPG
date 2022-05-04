/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** run
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
    #include <math.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #define HEIGHT 1080
    #define WIDTH 1920
    #include "menu.h"
    #include "procedural.h"
    #define LEN_MAP 219
    #define NB_MAPS 21

enum {
    NB_ALL_STATS = 6,
    NB_BOMBS = 3,
    NB_DMG = 26,
    NB_FLY_I = 2,
    N_HEALTH = 19,
    NB_KEYS = 4,
    NB_MONEY = 4,
    NB_SPEED = 9,
    NB_TEARS = 9,
    NB_LUCK = 4,
    LEN_FOLDERS = 10,
    NB_ITEMS = 93
};

enum {
    ALL_STATS,
    BOMBS,
    DMG,
    FLY_I,
    HEALTH,
    KEYS,
    MONEY,
    SPEED,
    TEARS,
    LUCK
};

typedef struct saler_red_s {
    sfVector2f player_pos;
    int i;
} saler_red_t;

typedef struct {
    long timer_total;
    long timer;
}timer;

typedef struct boss_spawning_s {
    char *file_spawn;
    int delay;
    int actual;
    bool is_spawning;
}boss_spawning_t;

typedef struct boss_s {
    sfSprite *sp;
    sfVector2f pos;
    float pv;
    int speed;
    bool is_flying;
    int decal_texture;
    int max_decal;
    boss_spawning_t bospt;
    float total_life;
}boss_t;

typedef struct {
    int total_life;
    int red_hearth;
    int blue_hearth;
    sfSprite *hsp;
}life;

typedef struct {
    int money;
    int bomb;
    int key;
}inventory;

typedef struct {
    int speed;
    int shot_speed;
    float damages;
    int freq_tears;
    int luck;
}stats;

typedef struct {
    bool key_a;
    bool key_e;
    bool key_q;
    bool key_z;
    bool key_s;
    bool key_d;
    bool key_left;
    bool key_up;
    bool key_right;
    bool key_down;
}event_key;

typedef struct {
    sfSprite *des;
    sfFont *font;
    sfText *main_d;
    sfText *sec_d;
    sfText *l_hud;
    bool active;
    bool l_h_active;
    bool all_st_active;
    sfClock *des_clock;
}item_desc;

typedef struct player_s {
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
    item_desc *it_des;
    int change_texture;
    bool new_item;
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
    sfTexture *altar_text;
    sfSprite *altar;
}collectible;

typedef struct old_item_s {
    char **old;
    int cp;
}old_item_t;

typedef struct {
    sfSprite *fo;
    sfSprite *ft;
    sfSprite *fl;
    int *actual_room;
    sfSprite *shop_room;
    int len_stone;
    bool open;
    stone *st;
    sfImage *room_col;
    collectible *red_hearth;
    collectible *blue_hearth;
    collectible *piece;
    collectible *item;
    collectible *bombs;
    collectible *keys;
    bool change_room;
    int luck;
    old_item_t old_i;
    timer timer_tears;
}room;

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
    bool is_shooting;
    bool is_flying;
    float pv;
    int speed;
}adv_t;

typedef struct reduce_adv_s {
    int i;
    sfVector2f player_pos;
    int type;
}reduce_adv_t;

typedef struct boss_life_s {
    sfSprite *end_start;
    sfSprite *life_bar;
    sfUint8 *framebuffer;
    sfTexture *text_framebuffer;
    int active;
}boss_life_t;

typedef struct {
    timer ti;
    timer move_ti;
    sfClock *total_clock;
    adv_t *no_moving_adv;
    adv_t *big_adv;
    adv_t *flying_adv;
    adv_t *little_adv;
    boss_t *boss_adv;
    boss_life_t boss_life;
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
    sfSound *p_hurt;
    sfSound *tr_room;
    sfSound *p_die;
    sfClock *sound_clock;
}sounds;

typedef struct {
    player *py;
    room *rm;
    tears *te;
    enemies_t *enem_t;
    rooms *ro;
    sounds *so;
}reduce;

//////// motor_s ////////

//// hud ////

// base_hud.c //
char *str_concat(char *str, char *concat);
void nb_time_hud(long time, sfRenderWindow *wd);
void nb_bomb_hud(int bomb, sfRenderWindow *wd);
void nb_key_hud(int key, sfRenderWindow *wd);
void nb_piece_hud(int piece, sfRenderWindow *wd);

// stat_hud.c //
void disp_speed(reduce *red, sfRenderWindow *wd);
void disp_freq_tears(reduce *red, sfRenderWindow *wd);
void disp_sp_tears(reduce *red, sfRenderWindow *wd);
void disp_damages(reduce *red, sfRenderWindow *wd);
void disp_luck(reduce *red, sfRenderWindow *wd);

//// moves ////

// basic_moves.c //
int check_move_right(player *py, room *rm);
int move_sp_top(player *py, int top, room *rm);

// move.c //
player *creation_player(void);
void draw_room(sfRenderWindow *wd, reduce *red, rooms *ro);
int move_sprite(player *py, int top, room *rm);
void key_action_pressed(sfEvent event, reduce *red);

// move2.c //
void move_player_check(reduce *red, int div);
void move_event(sfEvent event, reduce *red);
room *create_room(void);

//// other ////

// int_str.c //
char *my_int_str(unsigned long long nb);
int str_len(char const *str);

// life_gestion.c //
life create_life(void);
void draw_life(player *py, sfRenderWindow *rd);
void init_player(player *py);

// reduce.c //
bool collision_stone_tears(reduce *red, int x, int y, int nb);
tears *create_tears(player *py);
void reduce_move_player_check(reduce *red);
void disp_stat_hud(reduce *red, sfRenderWindow *wd);
stats create_stats(void);

// stone_base.c //
stone *create_stone(char *str, rooms *ro);
void place_stone(room *rm, player *py, char *str, rooms *ro);
void draw_stone(room *rm, sfRenderWindow *wd);
bool collision_stone(room *rm, player *py, int x, int y);
void reduce_place_f(sfImage *f_stone, room *rm, int i);
void reduce_place_s(sfImage *s_stone, room *rm, int i);
void reduce_place_t(sfImage *t_stone, room *rm, int i);

//recharge_room.c //
void recharge_room(reduce *red, bool is_empty, bool is_boss);

// item_description.c //
item_desc *init_description(void);
void disp_description(reduce *red, sfRenderWindow *wd);
void disp_fly_hud(player *py, char c);

//// tears ////

// check_tears_collision.c //
int check_collisions(int id, reduce *red, int nb);

// tears_shooting.c //
void shoot_tears(int id, reduce *red);
void move_tears(int id, reduce *red, sfRenderWindow *wd);
tears *init_st_array(tears *te, sfIntRect r, player *py);

// tears_state.c //
void clear_tears(reduce *red);
int verif_moving(reduce *red, int nb_tears);
void change_tears_aspect(reduce *red);

//////// enemies ////////

// anim_enemies.c //
void anim_enemies(enemies_t *enem_t);
void reduce_init_big(int i, adv_t *adv);
void reduce_init_fly(int i, adv_t *adv);

// create_enemies.c //
enemies_t *create_enemies(void);

// enemies_room.c //
void place_enemies(char *str, enemies_t *enem_t);
void draw_enemies(reduce *red, sfRenderWindow *wndw);

// mov_enemies.c //
void move_enemies(reduce *red);
void reduce_init_nomov(int i, adv_t *no_mov, sfVector2f scale,
sfIntRect place);

// player_enemies.c //
void touch_player_enemy(adv_t adv, sfVector2f player_pos, reduce *red);
void touch_player_boss(boss_t adv, sfVector2f player_pos, reduce *red);

// shoot_enemies.c //
bool touched_enemy(reduce *red, int i, char c);

// touch_enemy.c //7
bool touch_enemy(sfVector2f tears_pos, reduce *red);

//create_boss.c //

boss_t *create_boss(void);
void place_boss_level(enemies_t *enemy, bool final_boss);

//create_specific_boss.c //

void create_monstro_diggle(boss_t *boss);
sfTexture *init_mdg(sfTexture *text_m, sfTexture *text_d);
sfTexture *init_hgd(sfTexture *t_greed, sfTexture *t_husk);
void create_husk(boss_t *boss);

//anim_boss //

void anim_boss_loop(enemies_t *enemy);
void draw_boss(boss_t *bst, sfRenderWindow *wd);
char *create_map_str(char *to_read);

//boss_bar.c//
void display_boss_life(enemies_t *enemy, int i, sfRenderWindow *wd);
boss_life_t create_boss_bar(void);

//////// collectibles ////////

// base_inventory.c //
collectible *create_piece(sfTexture *text);
inventory create_inventory(void);

// blue_hearth.c //
collectible *create_blue_hearth(sfTexture *text);
void got_blue_hearth(room *rm, int i, player *py);

// collectible_create.c //
void draw_bonus(room *rm, sfRenderWindow *wd, player *py, rooms *ro);
void place_bonus(room *rm);

// red_hearth.c //
collectible *create_red_hearth(sfTexture *text);
void got_hearth(room *rm, int i, player *py);

//item.c//
void place_item(room *rm);
void launch_item(player *py, room *rm);

//item_fonctions.c//
int item_life_augmentation(player *py);
int item_speed(player *py);
int all_stats_up(player *py);
int my_str_compare(char const *str_one, char const *str_two);
int bombs_up(player *py);
int fate(player *py);
int item_damage(player *py);
int keys_up(player *py);
int item_freq(player *py);
int money_up(player *py);
int item_speed_tears(player *py);
int luck_up(player *py);
int god_head(player *py);
int mushroom(player *py);
int cricket(player *py);
int polyphemus(player *py);
int abaddon(player *py);
int masc(player *py);
int death(player *py);
int arrow(player *py);
int stigmata(player *py);
int cat(player *py);
int brimstone(player *py);
int ipecac(player *py);
int mind(player *py);
int demon(player *py);
int bandage(player *py);
int body(player *py);
int soul(player *py);
int fat(player *py);
int scab(player *py);
int meat(player *py);
int screw(player *py);
int pyj(player *py);
int binky(player *py);
int speed_ball(player *py);
int tooth(player *py);
int odd(player *py);
int dolly(player *py);
int squeezy(player *py);
int torn(player *py);
int strcomp(char *str, char *str1);
void reduce_choose_effect(collectible *item, int choose, char *tmp);

//item_launching.c //

bool already_got(char *tmp, old_item_t old_t);
char *item_selected(char *path, int nb);
///////////// minimap ////////////

void update_mini_map(rooms *ro, room *rm);
void clear_mini_map(rooms *ro);
void init_mini_map(rooms *ro);
void reduce_shop_minimap(rooms *ro, room *rm);
void reduce_boss_minimap(rooms *ro, room *rm);
void reduce_treasure_minimap(rooms *ro, room *rm);
void draw_mini_map(rooms *ro, sfRenderWindow *wd, room *rm);
void init_minimap_sprites(rooms *ro);
void init_shop_sprites(rooms *ro);
void init_treasure_sprites(rooms *ro);
void init_broom_sprites(rooms *ro);
void init_nroom_sprites(rooms *ro);
void reduce_draw_mini_map(int x, room *rm, rooms *ro, sfRenderWindow *wd);

void reduce_draw_tb(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt);
void close_door(rooms *ro, options *sprt, int x, int y);
void trophy_colisions(options *sprt, room *rm, player *py);
void trap_colisions(options *sprt, room *ry, player *py);
void player_room(sfRenderWindow *wd, reduce *red, options *sprt);
//void floor_pass(rooms *ro, reduce *red, options *sprt, window *wndw);
void doors_colisions(options *sprt, room *rm, player *py);
void init_rm_sprt(room *rm, options *sprt);
void draw_doors_topo(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_righto(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_lefto(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_boto(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_topc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_rightc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_leftc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_doors_botc(int lvl, options *sprt, sfRenderWindow *wd, char c);
void draw_all(sfRenderWindow *wd, reduce *red, options *sprt);
void launch_piece(player *py, room *rm, int i);
int event_window(window *wndw, options *sprt, reduce *red);
void player_room(sfRenderWindow *wd, reduce *red, options *sprt);
void draw_doors(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt);
void stats_player(reduce *red);
int check_move_right(player *py, room *rm);
int check_move_left(player *py, room *rm);
int check_move_down(player *py, room *rm);
int check_move_up(player *py, room *rm);

void mov_all(adv_t *all, sfVector2f player_pos, int type, reduce *red);
void mov_all_boss(boss_t *all, sfVector2f player_pos, reduce *red);
void draw_npc(window *wndw, options *sprt, reduce *red);
collectible *create_bomb_key(sfTexture *text, sfIntRect place,
int (*change)(player *py));
int add_bomb(player *py);
int add_key(player *py);
void launch_bombs(player *py, room *rm, int i);
void launch_key(player *py, room *rm, int i);
void other_keys_pressed(reduce *red, sfEvent event);
void other_keys_released(reduce *red, sfEvent event);
char *choose_string(int lvl);
void talking_npc( options *sprt, window *wndw, int level);
char get_actual_room_char(reduce *red);
void touch_saler(saler_red_t rt, options *sprt, window *wndw, reduce *red);
void draw_spause(window *wndw, options *sprt, reduce *red);
void stop_all_clocks(reduce *red);
#endif
