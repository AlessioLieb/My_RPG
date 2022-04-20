/*
** EPITECH PROJECT, 2022
** ouais
** File description:
** world
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <stddef.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include "../includes/enemies.h"
    #define WIDTH 1920
    #define HEIGHT 1080
    #define nb_buttons 2

typedef struct {
    sfRenderWindow *window;
    struct sfTexture *texture;
    struct sfSprite *sprite;
    int x;
    int y;
    int radius;
}window;

typedef struct {
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
    sfTexture *t;
    struct button *ar_btn;
    sfUint8 *framebuffer;
    struct sfTexture *frame_txt;
    struct sfSprite *frame_sprt;
    sfClock *j;
    int choose;
    int anim;
}options;

typedef enum button_name {
    CONTINUE_FIRST,
    HOME_SCREEN_TWO,
    PLAY_SCREEN_TWO,
    TURN_RIGHT_WHEEL_PERSO,
    TURN_LEFT_WHEEL_PERSO,
    RESUME_GAME_PAUSE,
    QUIT_PAUSE,
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

void params_window(window *wndw, options *sprt, players *perso);
// int event_window(window *wndw, options *sprt, room *rm, player *py);
int call_main_func(char *str);
int main_func(window *wndw, options *sprt, players *perso);
int my_game();
void init_welcome(window *wndw, options *sprt);
void init_barre(window *wndw, options *sprt);
void init_pause(window *wndw, options *sprt);
void init_sprites(window *wndw, options *sprt);
void draw_spwelcome(window *wndw, options *sprt);
void draw_spbarre(window *wndw, options *sprt);
void draw_spause(window *wndw, options *sprt);
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
void dsquare(int x, int y, int radius, options *sprt, sfColor color);
#endif
