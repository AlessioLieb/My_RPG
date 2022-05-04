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

void reduce_draw_spause(window *wndw, options *sprt, rooms *ro)
{
    sfIntRect third = {0, 209, 774, 47};
    sfIntRect four = {0, 313, 774, 47};
    sfIntRect last = {0, 417, 774, 47};
    if (ro->lvl == 2) {
        sfSprite_setTextureRect(sprt->lvl_m_sprt, third);
        sfSprite_setPosition(sprt->lvl_m_sprt, (sfVector2f) {845, 430});
        sfRenderWindow_drawSprite(wndw->window, sprt->lvl_m_sprt, NULL);
    }
    if (ro->lvl == 3) {
        sfSprite_setTextureRect(sprt->lvl_m_sprt, four);
        sfSprite_setPosition(sprt->lvl_m_sprt, (sfVector2f) {830, 430});
        sfRenderWindow_drawSprite(wndw->window, sprt->lvl_m_sprt, NULL);
    }
    if (ro->lvl == 4) {
        sfSprite_setTextureRect(sprt->lvl_m_sprt, last);
        sfSprite_setPosition(sprt->lvl_m_sprt, (sfVector2f) {790, 430});
        sfRenderWindow_drawSprite(wndw->window, sprt->lvl_m_sprt, NULL);
    }
}

void draw_spause(window *wndw, options *sprt, rooms *ro)
{
    sfIntRect first = {0, 0, 774, 47};
    sfIntRect sec = {0, 103, 774, 47};
    sfRenderWindow_drawSprite(wndw->window, sprt->pause_sprt, NULL);
    for (int i = 0; i < sprt->invent.len; ++i)
        sfRenderWindow_drawSprite(wndw->window, sprt->invent.sprites[i], NULL);
    if (ro->lvl == 0) {
        sfSprite_setTextureRect(sprt->lvl_m_sprt, first);
        sfSprite_setPosition(sprt->lvl_m_sprt, (sfVector2f) {800, 430});
        sfRenderWindow_drawSprite(wndw->window, sprt->lvl_m_sprt, NULL);
    }
    if (ro->lvl == 1) {
        sfSprite_setTextureRect(sprt->lvl_m_sprt, sec);
        sfSprite_setPosition(sprt->lvl_m_sprt, (sfVector2f) {785, 430});
        sfRenderWindow_drawSprite(wndw->window, sprt->lvl_m_sprt, NULL);
    }
    is_touched_button(wndw, sprt);
    reduce_draw_spause(wndw, sprt, ro);
}

void draw_loose_scrn(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->loose_sprt, NULL);
}
