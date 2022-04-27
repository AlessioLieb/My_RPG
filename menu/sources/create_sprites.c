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

void init_tuto(window *wndw, options *sprt)
{
    sfIntRect rect = {469, 627, 468, 312};
    sfVector2f scale = {1920.0 / 468.0, 1080.0 / 312.0};
    sprt->tutorial = sfSprite_create();
    sfSprite_setTexture(sprt->tutorial, sprt->tuto, sfTrue);
    sfSprite_setTextureRect(sprt->tutorial, rect);
    sfSprite_setScale(sprt->tutorial, scale);
}

void init_sprites(window *wndw, options *sprt)
{
    init_welcome(wndw, sprt);
    init_barre(wndw, sprt);
    init_pause(wndw, sprt);
    init_tuto(wndw, sprt);
    init_doo(wndw, sprt);
    init_doc(wndw, sprt);
    init_dto(wndw, sprt);
    init_dtc(wndw, sprt);
    init_dlo(wndw, sprt);
    init_dlc(wndw, sprt);
    init_tdo(wndw, sprt);
    init_tdc(wndw, sprt);
    init_bdo(wndw, sprt);
    init_bdc(wndw, sprt);
    init_trap(wndw, sprt);
    init_trophy(wndw, sprt);
    init_win(wndw, sprt);
    init_npc(wndw, sprt);
}
