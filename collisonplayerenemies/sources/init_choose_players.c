/*
** EPITECH PROJECT, 2021
** menu
** File description:
** wheel_players.c
*/

#include "../includes/menu.h"

void init_robhein(window *wndw, players *perso)
{
    sfVector2f prems = {590, 340};
    sfIntRect first = {0, 0, 1662, 411};
    sfVector2f scale = {0.45, 0.45};
    perso->sprt_robhein = sfSprite_create();
    sfSprite_setTexture(perso->sprt_robhein, perso->txt_perso_wheel, sfTrue);
    sfSprite_setTextureRect(perso->sprt_robhein, first);
    sfSprite_setScale(perso->sprt_robhein, scale);
    sfSprite_setPosition(perso->sprt_robhein, prems);
}

void init_theotitime(window *wndw, players *perso)
{
    sfVector2f prems = {590, 340};
    sfIntRect first = {0, 408, 1659, 414};
    sfVector2f scale = {0.45, 0.45};
    perso->sprt_theotitime = sfSprite_create();
    sfSprite_setTexture(perso->sprt_theotitime,
    perso->txt_perso_wheel, sfTrue);
    sfSprite_setTextureRect(perso->sprt_theotitime, first);
    sfSprite_setScale(perso->sprt_theotitime, scale);
    sfSprite_setPosition(perso->sprt_theotitime, prems);
}

void init_aliciau(window *wndw, players *perso)
{
    sfVector2f prems = {590, 340};
    sfIntRect first = {0, 813, 1659, 414};
    sfVector2f scale = {0.45, 0.45};
    perso->sprt_aliciau = sfSprite_create();
    sfSprite_setTexture(perso->sprt_aliciau, perso->txt_perso_wheel, sfTrue);
    sfSprite_setTextureRect(perso->sprt_aliciau, first);
    sfSprite_setScale(perso->sprt_aliciau, scale);
    sfSprite_setPosition(perso->sprt_aliciau, prems);
}

void init_osca(window *wndw, players *perso)
{
    sfVector2f prems = {590, 340};
    sfIntRect first = {0, 1239, 1659, 414};
    sfVector2f scale = {0.45, 0.45};
    perso->sprt_osca = sfSprite_create();
    sfSprite_setTexture(perso->sprt_osca, perso->txt_perso_wheel, sfTrue);
    sfSprite_setTextureRect(perso->sprt_osca, first);
    sfSprite_setScale(perso->sprt_osca, scale);
    sfSprite_setPosition(perso->sprt_osca, prems);
}

void init_players(window *wndw, players *perso)
{
    init_robhein(wndw, perso);
    init_theotitime(wndw, perso);
    init_aliciau(wndw, perso);
    init_osca(wndw, perso);
}
