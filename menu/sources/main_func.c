/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main_func.c
*/

#include "../includes/motor.h"

int my_game(window *wndw, sfEvent event, reduce *red, options *sprt)
{
    player_room(wndw->window, red, sprt);
    draw_enemies(red->enem_t, wndw->window, red->py, red->rm);
    draw_life(red->py, wndw->window);
    draw_bonus(red->rm, wndw->window, red->py);
    nb_piece_hud(red->py->invent.money, wndw->window);
    nb_bomb_hud(red->py->invent.bomb, wndw->window);
    nb_key_hud(red->py->invent.key, wndw->window);
    nb_time_hud(sfClock_getElapsedTime(red->py->time).microseconds / 1000000,
    wndw->window);
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

int main_func(window *wndw, options *sprt, players *perso, rooms *ro)
{
    char *buff = malloc(1000);
    int file = open("rooms/1.room", O_RDONLY);
    int size = read(file, buff, 1000);
    buff[size] = '\0';
    player *py = creation_player();
    room *rm = create_room(buff);
    rm->actual_room = malloc(sizeof(int) * 2);
    rm->actual_room[0] = 4;
    rm->actual_room[1] = 4;
    sfEvent event;
    tears *te = create_tears(py);
    enemies_t *enem_t = create_enemies();
    place_enemies(buff, enem_t);
    place_stone(rm, py, buff);
    init_all(wndw, sprt, perso);
    place_bonus(rm);
    while (sfRenderWindow_isOpen(wndw->window)) {
        event_window(wndw, sprt, &(reduce) {py, rm, te, enem_t});
        (sprt->begin == 1) ? draw_spwelcome(wndw, sprt) : 0;
        (sprt->begin == 2 || sprt->begin == 3)
        ? screen_choose_player(wndw, sprt, perso) : 0;
        is_touched_button(wndw, sprt);
        (sprt->begin == 2) ? display_framebuffer(wndw, sprt) : 0;
        (sprt->begin == 3)
        ? my_game(wndw, event, &(reduce) {py, rm, te, enem_t, ro}, sprt) : 0;
        (sprt->begin == 4) ? draw_spause(wndw, sprt) : 0;
        sfRenderWindow_display(wndw->window);
        sfRenderWindow_clear(wndw->window, sfBlack);
    }
    end_buffer(sprt);
}
