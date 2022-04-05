/*
** EPITECH PROJECT, 2021
** menu
** File description:
** init_all.c
*/

#include "../includes/menu.h"

void init_all(window *wndw, options *sprt, players *perso)
{
    sprt->begin = 1;
    sprt->params = 0;
    sprt->pause = 0;
    sprt->alt = 0;
    sprt->choose = 0;
    sprt->anim = 1;
    params_window(wndw, sprt, perso);
    init_sprites(wndw, sprt);
    init_framebuffer(sprt);
    init_players(wndw, perso);
    linked_button(sprt, wndw);
}
