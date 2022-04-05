/*
** EPITECH PROJECT, 2021
** menu
** File description:
** states_button.c
*/

#include "../includes/menu.h"

void touch_button(window *wndw, options *opt, int i, sfVector2i pos)
{
    sfVector2f yes = sfSprite_getPosition(opt->ar_btn[i].sprt);
    sfIntRect tmp = {yes.x, yes.y, opt->ar_btn[i].place.width,
    opt->ar_btn[i].place.height};
    sfIntRect new = {opt->ar_btn[i].place.left, opt->ar_btn[i].place.height,
    opt->ar_btn[i].place.width, opt->ar_btn[i].place.height};
    if (sfIntRect_contains(&tmp, pos.x, pos.y) && opt->ar_btn[i].event != 3) {
        sfSprite_setTextureRect(opt->ar_btn[i].sprt, new);
        opt->ar_btn[i].event = 0;
        } else if (opt->ar_btn[i].event != 3)
        sfSprite_setTextureRect(opt->ar_btn[i].sprt, opt->ar_btn[i].place);
    if (opt->ar_btn[i].screen == opt->begin && opt->ar_btn[i].params)
        sfRenderWindow_drawSprite(wndw->window, opt->ar_btn[i].sprt, NULL);
}

void is_touched_button(window *wndw, options *opt)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    for (int i = 0; i < opt->len_button; ++i)
        touch_button(wndw, opt, i, pos);
}

void move_rect_pressed(options *opt, int i)
{
    sfIntRect new = {opt->ar_btn[i].place.left, opt->ar_btn[i].place.height * 2,
    opt->ar_btn[i].place.width, opt->ar_btn[i].place.height};
    sfSprite_setTextureRect(opt->ar_btn[i].sprt, new);
    opt->ar_btn[i].event = 3;
}

void catch_button(window *wndw, options *opt, sfEvent event)
{
    for (int i = 0; i < opt->len_button; ++i) {
        if (opt->ar_btn[i].params == 1 && ((event.mouseButton.x >=
        opt->ar_btn[i].pos.x) &&
        (event.mouseButton.x <= (opt->ar_btn[i].pos.x +
        opt->ar_btn[i].place.width))) && ((event.mouseButton.y >=
        opt->ar_btn[i].pos.y) && (event.mouseButton.y <=
        (opt->ar_btn[i].pos.y + opt->ar_btn[i].place.height) &&
        opt->ar_btn[i].screen == opt->begin)))
            (*(opt->ar_btn[i].launch))(wndw, opt);
        opt->ar_btn[i].event = 0;
    }
}

void click_button(window *wndw, options *opt, sfEvent event)
{
        for (int i = 0; i < opt->len_button; ++i) {
        if (((event.mouseButton.x >= opt->ar_btn[i].pos.x) &&
        (event.mouseButton.x <= (opt->ar_btn[i].pos.x +
        opt->ar_btn[i].place.width))) && ((event.mouseButton.y >=
        opt->ar_btn[i].pos.y) && (event.mouseButton.y <=
        (opt->ar_btn[i].pos.y + opt->ar_btn[i].place.height) &&
        opt->ar_btn[i].screen == opt->begin)))
            move_rect_pressed(opt, i);
    }
}
