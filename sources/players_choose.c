/*
** EPITECH PROJECT, 2021
** menu
** File description:
** players_choose.c
*/

#include "../includes/menu.h"

void draw_robhein(window *wndw, players *perso)
{
    sfRenderWindow_drawSprite(wndw->window, perso->sprt_robhein, NULL);
}

void draw_theotitime(window *wndw, players *perso)
{
    sfRenderWindow_drawSprite(wndw->window, perso->sprt_theotitime, NULL);
}

void draw_aliciau(window *wndw, players *perso)
{
    sfRenderWindow_drawSprite(wndw->window, perso->sprt_aliciau, NULL);
}

void draw_osca(window *wndw, players *perso)
{
    sfRenderWindow_drawSprite(wndw->window, perso->sprt_osca, NULL);
}
