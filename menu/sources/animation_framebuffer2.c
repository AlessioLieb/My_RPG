/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** animation_framebuffer2.c
*/

#include "../includes/menu.h"

void restore_framebuffer(options *sprt)
{
    for (int i = 0; i < WIDTH * HEIGHT * 4; ++i)
        sprt->framebuffer[i] = 0;
}

void init_framebuffer(options *sprt)
{
    sprt->framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    sprt->frame_txt = sfTexture_create(WIDTH, HEIGHT);
    sprt->frame_sprt = sfSprite_create();
    sprt->j = sfClock_create();
    for (int i = 0; i < WIDTH * HEIGHT * 4; ++i)
        sprt->framebuffer[i] = 255;
}
