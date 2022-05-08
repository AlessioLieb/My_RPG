/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** draw_sprites4.c
*/

#include "../includes/music.h"

void is_pressed(window *wndw, options *opt, reduce *red, slide_bar *s_bar)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    for (int i = 0; i < opt->len_button; ++i)
        touch_button(wndw, opt, i, pos);
}

void dopt_sprt(window *wndw, options *sprt, reduce *red, slide_bar *s_bar)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->opt_sprt, NULL);
    sound_bar_handling(red, s_bar, wndw->window);
}

void dwin_sprt(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->win_sprt, NULL);
}
