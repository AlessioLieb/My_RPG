/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** draw_sprites.c
*/

#include "../includes/menu.h"

void draw_spwelcome(window *wndw, options *sprt)
{
    put_framebuffer2(sprt);
    sfRenderWindow_drawSprite(wndw->window, sprt->spwelcome, NULL);
}

void draw_spbarre(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->spbarre, NULL);
}

void draw_spause(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->pause_sprt, NULL);
    for (int i = 0; i < sprt->invent.len; ++i)
        sfRenderWindow_drawSprite(wndw->window, sprt->invent.sprites[i], NULL);
    is_touched_button(wndw, sprt);
}

void draw_loose_scrn(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->loose_sprt, NULL);
}

void init_dlc(window *wndw, options *sprt)
{
    sfIntRect rect = {49, 369, 49, 33};
    sfVector2f scale = {3.5, 3.5};
    sprt->doorlclose = sfSprite_create();
    sfSprite_setTexture(sprt->doorlclose, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->doorlclose, rect);
    sfSprite_setScale(sprt->doorlclose, scale);
}
