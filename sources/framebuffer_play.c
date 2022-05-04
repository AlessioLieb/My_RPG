/*
** EPITECH PROJECT, 2021
** menu
** File description:
** framebuffer_play.c
*/

#include "../includes/menu.h"

void my_put_pixel_circle(options *sprt, int x, int y, sfColor color)
{
    int r = 4 * (y * WIDTH + x);
    if (y < HEIGHT && x < WIDTH && r > 0) {
        sprt->framebuffer[r] = color.r;
        sprt->framebuffer[r + 1] = color.g;
        sprt->framebuffer[r + 2] = color.b;
        sprt->framebuffer[r + 3] = color.a;
    }
}

void dsquare(int x, int y, int radius, options *sprt)
{
    for (int i = 0; i <= WIDTH; ++i)
        for (int j = 0; j <= HEIGHT; ++j)
            (i < x + radius && i > x - radius && j < y + radius && j > y -
            radius) ? 0 : my_put_pixel_circle(sprt, i, j, sfBlack);
}
