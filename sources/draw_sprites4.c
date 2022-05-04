/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** draw_sprites4.c
*/

#include "../includes/menu.h"

void dopt_sprt(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->opt_sprt, NULL);
}

void dwin_sprt(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->win_sprt, NULL);
}
