/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** interface.c
*/

#include "../includes/menu.h"

void init_welcome(window *wndw, options *sprt)
{
    sfVector2f prems = {0, 0};
    sfIntRect first = {0, 0, 1920, 1080};
    sprt->spwelcome = sfSprite_create();
    sfSprite_setTexture(sprt->spwelcome, sprt->welcome, sfTrue);
    sfSprite_setPosition(sprt->spwelcome, prems);
}

void init_barre(window *wndw, options *sprt)
{
    sfVector2f prems = {0, 0};
    sfIntRect first = {0, 0, 1920, 1080};
    sprt->spbarre = sfSprite_create();
    sfSprite_setTexture(sprt->spbarre, sprt->barre, sfTrue);
    sfSprite_setPosition(sprt->spbarre, prems);
}

void init_pause(window *wndw, options *sprt)
{
    sfVector2f prems = {0, 0};
    sfIntRect first = {0, 0, 1920, 1080};
    sprt->pause_sprt = sfSprite_create();
    sfSprite_setTexture(sprt->pause_sprt, sprt->pause_txt, sfTrue);
    sfSprite_setPosition(sprt->pause_sprt, prems);
}

void init_sprites(window *wndw, options *sprt)
{
    init_welcome(wndw, sprt);
    init_barre(wndw, sprt);
    init_pause(wndw, sprt);
}
