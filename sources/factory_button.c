/*
** EPITECH PROJECT, 2021
** menu
** File description:
** factory_button.c
*/

#include "../includes/menu.h"

void factory_button(options *opt, ptr_f fc, sfIntRect old, sfVector2f pos)
{
    button btn;
    btn.sprt = sfSprite_create();
    btn.place = old;
    btn.pos = pos;
    btn.launch = fc;
    btn.event = 0;
    sfSprite_setTexture(btn.sprt, opt->t, sfTrue);
    sfSprite_setTextureRect(btn.sprt, old);
    sfSprite_setPosition(btn.sprt, pos);
    opt->ar_btn[opt->len_button] = btn;
    ++opt->len_button;
}
