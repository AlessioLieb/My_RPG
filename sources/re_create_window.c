/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** re_create_window.c
*/

#include "../includes/menu.h"

void re_create_window(window *wndw, options *sprt)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow_close(wndw->window);
    sfRenderWindow_destroy(wndw->window);
    if (wndw->full == 1) {
        wndw->window = sfRenderWindow_create(mode, "MyRPG", sfResize
        | sfClose | sfFullscreen, NULL);
        wndw->full = 0;
        sprt->ar_btn[ENABLED].params = 1;
        sprt->ar_btn[UNENABLED].params = 0;
    } else {
        wndw->window = sfRenderWindow_create(mode, "MyRPG", sfResize
        | sfClose, NULL);
        wndw->full = 1;
        sprt->ar_btn[ENABLED].params = 0;
        sprt->ar_btn[UNENABLED].params = 1;
    }
}
