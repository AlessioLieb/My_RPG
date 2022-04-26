/*
** EPITECH PROJECT, 2021
** menu
** File description:
** animation_framebuffer.c
*/

#include "../includes/menu.h"

void put_framebuffer(options *sprt)
{
    for (int i = 0; i < WIDTH * HEIGHT * 4; ++i)
        sprt->framebuffer[i] = 255;
}

void func_flash_frame(window *wndw, options *sprt)
{
    for (int i = 3; i < WIDTH * HEIGHT * 4; i += 4)
        (sprt->framebuffer[i] > 1) ? sprt->framebuffer[i] -= 2.5 : 0;
    sfClock_restart(sprt->j);
}

void func_square_frame(window *wndw, options *sprt)
{
    (wndw->radius > 0) ? wndw->radius -= 15 : 0;
    (wndw->radius < 1) ? sprt->begin = 3 : 0;
    sfClock_restart(sprt->j);
}

void display_framebuffer(window *wndw, options *sprt)
{
    (sfClock_getElapsedTime(sprt->j).microseconds > 16666 && sprt->anim == 1)
    ? func_flash_frame(wndw, sprt) : 0;
    (sfClock_getElapsedTime(sprt->j).microseconds > 1 && sprt->anim == 2)
    ? func_square_frame(wndw, sprt) : 0;
    (sprt->anim == 2)
    ? dsquare(wndw->x, wndw->y, wndw->radius, sprt, sfBlue) : 0;
    sfTexture_updateFromPixels(sprt->frame_txt, sprt->framebuffer, WIDTH,
    HEIGHT, 0, 0);
    sfSprite_setTexture(sprt->frame_sprt, sprt->frame_txt, sfTrue);
    sfRenderWindow_drawSprite(wndw->window, sprt->frame_sprt, NULL);
    (sprt->anim != 1) ? restore_framebuffer(sprt) : 0;
}

void end_buffer(options *sprt)
{
    free(sprt->framebuffer);
    sfTexture_destroy(sprt->frame_txt);
    sfSprite_destroy(sprt->frame_sprt);
}
