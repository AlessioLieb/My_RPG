/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** func_button.c
*/

#include "../includes/menu.h"

int continue_button(window *wndw, options *opt)
{
    opt->begin = 2;
    return 0;
}

int resume_button(window *wndw, options *opt)
{
    opt->begin = 3;
    return 0;
}

int print_win(window *wndw, options *opt)
{
    opt->begin = 8;
    return 0;
}

int quitgame(window *wndw, options *opt)
{
    sfRenderWindow_close(wndw->window);
    return 0;
}

int open_opt(window *wndw, options *opt)
{
    opt->begin = 9;
    return 0;
}
