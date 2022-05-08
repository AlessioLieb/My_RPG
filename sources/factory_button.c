/*
** EPITECH PROJECT, 2021
** menu
** File description:
** factory_button.c
*/

#include "../includes/menu.h"

int none(window *wndw, options *opt)
{
    return 0;
}

int music_but(window *wndw, options *opt)
{
    if (!opt->mus_t.mouv_music)
        opt->mus_t.mouv_music = true;
    else
        opt->mus_t.mouv_music = false;
}

int sound_but(window *wndw, options *opt)
{
    if (!opt->mus_t.mouv_sound)
        opt->mus_t.mouv_sound = true;
    else
        opt->mus_t.mouv_sound = false;
}

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
