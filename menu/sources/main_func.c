/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main_func.c
*/

#include "../includes/motor.h"

int my_game(window *wndw, player *py, sfEvent event, room *rm, enemies_t *enem_t)
{
    // sfRenderWindow_clear(wndw->window, sfBlack);
    // while (sfRenderWindow_pollEvent(wndw->window, &event))
    //     move_event(py, event, rm);
    player_room(py, wndw->window, rm);
    draw_enemies(enem_t, wndw->window);
    //sfRenderWindow_display(wndw->window);
    return 0;
}

void screen_choose_player(window *wndw, options *sprt, players *perso)
{
    draw_spbarre(wndw, sprt);
    (sprt->choose == 0) ? draw_robhein(wndw, perso) : 0;
    (sprt->choose == 1) ? draw_theotitime(wndw, perso) : 0;
    (sprt->choose == 2) ? draw_aliciau(wndw, perso) : 0;
    (sprt->choose == 3) ? draw_osca(wndw, perso) : 0;
}

int main_func(window *wndw, options *sprt, players *perso)
{
    char *buff = malloc(1000);
    int file = open("rooms/1.room", O_RDONLY);
    int size = read(file, buff, 1000);
    buff[size] = '\0';
    // sfRenderWindow *wd = sfRenderWindow_create((sfVideoMode)
    //         {1920, 1080, 32},  "isaac", sfFullscreen | sfClose, NULL);
    player *py = creation_player();
    room *rm = create_room(buff);
    sfEvent event;
    enemies_t *enem_t = create_enemies();
    place_enemies(buff, enem_t);
    place_stone(rm, py, buff);
    init_all(wndw, sprt, perso);
    while (sfRenderWindow_isOpen(wndw->window)) {
        event_window(wndw, sprt, rm, py);
        (sprt->begin == 1) ? draw_spwelcome(wndw, sprt) : 0;
        (sprt->begin == 2 || sprt->begin == 3)
        ? screen_choose_player(wndw, sprt, perso) : 0;
        is_touched_button(wndw, sprt);
        (sprt->begin == 2) ? display_framebuffer(wndw, sprt) : 0;
        (sprt->begin == 3) ? my_game(wndw, py, event, rm, enem_t) : 0;
        (sprt->begin == 4) ? draw_spause(wndw, sprt) : 0;
        sfRenderWindow_display(wndw->window);
        sfRenderWindow_clear(wndw->window, sfBlack);
    }
    end_buffer(sprt);
}
