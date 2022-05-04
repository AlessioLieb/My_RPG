/*
** EPITECH PROJECT, 2021
** menu
** File description:
** action_button.c
*/

#include "../includes/menu.h"

int home_button(window *wndw, options *opt)
{
    opt->begin = 1;
    opt->anim = 1;
    return 0;
}

int play_button(window *wndw, options *opt)
{
    opt->anim = 2;
    wndw->x = 960;
    wndw->y = 540;
    wndw->radius = 1100;
    dsquare(wndw->x, wndw->y, wndw->radius, opt);
    return 0;
}

int quit_game(window *wndw, options *opt)
{
    sfRenderWindow_close(wndw->window);
    return 0;
}

int plus_choose(window *wndw, options *opt)
{
    if (opt->choose == 3)
        opt->choose = 0;
    else
        ++opt->choose;
    return 0;
}

int mines_choose(window *wndw, options *opt)
{
    if (opt->choose == 0)
        opt->choose = 3;
    else
        --opt->choose;
    return 0;
}
