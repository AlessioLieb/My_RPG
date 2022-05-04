/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** animation_framebuffer3.c
*/

#include "../includes/menu.h"

void func_flash_frame_rev(window *wndw, options *sprt)
{
    for (int i = 3; i < WIDTH * HEIGHT * 4; i += 4) {
        (sprt->framebuffer[i] < 255) ? sprt->framebuffer[i] += 2.5 : 0;
        (sprt->framebuffer[i] >= 250) ? sprt->begin = 8 : 0;
    }
    sfClock_restart(sprt->j);
}
