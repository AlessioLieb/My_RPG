/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main_func.c
*/

#include "../includes/menu.h"

int my_game(window *wndw, options *sprt)
{
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
    init_all(wndw, sprt, perso);
    while (sfRenderWindow_isOpen(wndw->window)) {
        event_window(wndw, sprt);
        (sprt->begin == 1) ? draw_spwelcome(wndw, sprt) : 0;
        (sprt->begin == 2 || sprt->begin == 3) ? screen_choose_player(wndw, sprt, perso) : 0;
        is_touched_button(wndw, sprt);
        (sprt->begin == 2) ? display_framebuffer(wndw, sprt) : 0;
        (sprt->begin == 3) ? my_game(wndw, sprt) : 0;
        (sprt->begin == 4) ? draw_spause(wndw, sprt) : 0;
        sfRenderWindow_display(wndw->window);
        sfRenderWindow_clear(wndw->window, sfBlack);
    }
    end_buffer(sprt);
}
