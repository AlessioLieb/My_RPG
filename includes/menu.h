/*
** EPITECH PROJECT, 2022
** ouais
** File description:
** world
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <stddef.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <stddef.h>
    #include "stdbool.h"
    #include "enemies.h"
    #include "procedural.h"
    #define WIDTH 1920
    #define HEIGHT 1080
    #define nb_buttons 2

enum {
    MONEY_S,
    BOMBS_S,
    KEYS_S,
    LEN_SALER
};

typedef struct {
    sfRenderWindow *window;
    struct sfTexture *texture;
    struct sfSprite *sprite;
    int x;
    int y;
    int radius;
    long *last_time;
    int full;
}window;

typedef struct objects_s {
    sfSprite **sprites;
    char **object;
    int len;
    sfVector2f last_pos;
}objects_t;

typedef struct saler_s {
    sfSprite *sp;
    sfIntRect place_touch;
}saler_t;

typedef struct ch_music_s {
    bool mouv_music;
    bool mouv_sound;
}ch_music_t;

typedef struct {
    ch_music_t mus_t;
    saler_t *sal;
    int mv;
    int params;
    int begin;
    int len_button;
    int pause;
    int alt;
    sfTexture *welcome;
    sfSprite *spwelcome;
    sfTexture *barre;
    sfSprite *spbarre;
    sfTexture *pause_txt;
    sfSprite *pause_sprt;
    sfTexture *tuto;
    sfSprite *tutorial;
    sfTexture *doors;
    sfSprite *dooroopen;
    sfSprite *dooroclose;
    sfSprite *doortopen;
    sfSprite *doortclose;
    sfSprite *doorlopen;
    sfSprite *doorlclose;
    sfSprite *treasure_do;
    sfSprite *treasure_dc;
    sfSprite *boss_do;
    sfSprite *boss_dc;
    sfSprite *trap;
    sfSprite *trophy;
    sfSprite *win;
    sfTexture *pickups;
    sfTexture *t;
    bool *actual_doors;
    bool plus_lvl;
    struct button *ar_btn;
    sfUint8 *framebuffer;
    struct sfTexture *frame_txt;
    struct sfSprite *frame_sprt;
    sfClock *j;
    int choose;
    int anim;
    bool win_cond;
    sfTexture *text_npc;
    sfSprite *npc;
    sfSprite *spbulle_npc;
    sfText *text_for_npc;
    objects_t invent;
    sfTexture *loose_txt;
    sfSprite *loose_sprt;
    sfTexture *win_txt;
    sfSprite *win_sprt;
    sfTexture *opt_txt;
    sfSprite *opt_sprt;
    sfTexture *lvl_m_txt;
    sfSprite *lvl_m_sprt;
    sfSprite *head_music;
}options;

typedef enum button_name {
    CONTINUE_FIRST,
    HOME_SCREEN_TWO,
    PLAY_SCREEN_TWO,
    TURN_RIGHT_WHEEL_PERSO,
    TURN_LEFT_WHEEL_PERSO,
    RESUME_GAME_PAUSE,
    QUIT_PAUSE,
    NEXT,
    OPTIONS,
    QUIT_GAME,
    BACK_OPT,
    FULLSCREEN,
    ENABLED,
    UNENABLED,
    HEAD_MUSIC,
    HEAD_SOUND,
}buttton_name;

typedef struct button {
    int params;
    int screen;
    int event;
    sfSprite *sprt;
    sfIntRect place;
    sfVector2f pos;
    int (*launch)(window *wndw, options *opt);
}button;

typedef struct {
    sfTexture *txt_perso_wheel;
    sfSprite *sprt_osca;
    sfSprite *sprt_robhein;
    sfSprite *sprt_theotitime;
    sfSprite *sprt_aliciau;
}players;

void init_all(window *wndw, options *sprt, players *perso);
void restore_framebuffer(options *sprt);
void params_window(window *wndw, options *sprt, players *perso);
void init_welcome(window *wndw, options *sprt);
void init_barre(window *wndw, options *sprt);
void init_pause(window *wndw, options *sprt);
void init_sprites(window *wndw, options *sprt);
void init_doo(window *wndw, options *sprt);
void init_doc(window *wndw, options *sprt);
void init_dto(window *wndw, options *sprt);
void init_dtc(window *wndw, options *sprt);
void init_dlo(window *wndw, options *sprt);
void init_dlc(window *wndw, options *sprt);
void init_tdo(window *wndw, options *sprt);
void init_tdc(window *wndw, options *sprt);
void init_bdo(window *wndw, options *sprt);
void init_bdc(window *wndw, options *sprt);
void init_trap(window *wndw, options *sprt);
void init_trophy(window *wndw, options *sprt);
void init_win(window *wndw, options *sprt);
void draw_spwelcome(window *wndw, options *sprt);
void draw_spbarre(window *wndw, options *sprt);
void draw_tuto(sfRenderWindow *wd, options *sprt);
typedef int (*ptr_f)(window *wndw, options *opt);
void factory_button(options *opt, ptr_f fc, sfIntRect old, sfVector2f pos);
void touch_button(window *wndw, options *opt, int i, sfVector2i pos);
void is_touched_button(window *wndw, options *opt);
void move_rect_pressed(options *opt, int i);
void catch_button(window *wndw, options *opt, sfEvent event);
void click_button(window *wndw, options *opt, sfEvent event);
void linked_button(options *opt, window *wndw);
void init_framebuffer(options *sprt);
void put_framebuffer(options *sprt);
void display_framebuffer(window *wndw, options *sprt);
void end_buffer(options *sprt);
int home_button(window *wndw, options *opt);
int play_button(window *wndw, options *opt);
int quit_game(window *wndw, options *opt);
int plus_choose(window *wndw, options *opt);
int mines_choose(window *wndw, options *opt);
void init_players(window *wndw, players *perso);
void draw_osca(window *wndw, players *perso);
void draw_aliciau(window *wndw, players *perso);
void draw_theotitime(window *wndw, players *perso);
void draw_robhein(window *wndw, players *perso);
void init_framebuffer_play(options *sprt);
void put_framebuffer_play(options *sprt);
void display_framebuffer_play(window *wndw, options *sprt);
void end_buffer_play(options *sprt);
void dsquare(int x, int y, int radius, options *sprt);
void put_framebuffer2(options *sprt);
void init_loose_scrn(window *wndw, options *sprt);
void draw_loose_scrn(window *wndw, options *sprt);
void init_win_scrn(window *wndw, options *sprt);
int continue_button(window *wndw, options *opt);
int resume_button(window *wndw, options *opt);
int print_win(window *wndw, options *opt);
int quitgame(window *wndw, options *opt);
int open_opt(window *wndw, options *opt);
void init_opt_screen(window *wndw, options *sprt);
int back_opt(window *wndw, options *opt);
void dwin_sprt(window *wndw, options *sprt);
void init_lvl_m(window *wndw, options *sprt);
void init_tuto(window *wndw, options *sprt);
void put_framebuffer3(options *sprt);
void func_flash_frame_rev(window *wndw, options *sprt);
void re_create_window(window *wndw, options *sprt);
int full_screen(window *wndw, options *opt);

void init_npc(window *wndw, options *sprt);
int update_my_stuff(options *opt, char **new_array, int new_len);
void screen_choose_player(window *wndw, options *sprt, players *perso);
int none(window *wndw, options *opt);
int music_but(window *wndw, options *opt);
int sound_but(window *wndw, options *opt);
#endif
