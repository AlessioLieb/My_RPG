/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** draw_sprites.c
*/

#include "../includes/menu.h"

void draw_spwelcome(window *wndw, options *sprt)
{
    put_framebuffer(sprt);
    sfRenderWindow_drawSprite(wndw->window, sprt->spwelcome, NULL);
}

void draw_spbarre(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->spbarre, NULL);
}

void draw_spause(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->pause_sprt, NULL);
    is_touched_button(wndw, sprt);
}
