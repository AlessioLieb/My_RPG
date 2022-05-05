/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** func_button_sec.c
*/

#include "../includes/menu.h"

int back_opt(window *wndw, options *opt)
{
    opt->begin = 4;
    return 0;
}

int full_screen(window *wndw, options *opt)
{
    re_create_window(wndw, opt);
    return 0;
}
