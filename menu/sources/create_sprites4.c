/*
** EPITECH PROJECT, 2021
** menu
** File description:
** create_sprites4.c
*/

#include "../includes/menu.h"

void init_trophy(window *wndw, options *sprt)
{
    sfIntRect rect = {32, 112, 32, 40};
    sfVector2f scale = {4, 4};
    sprt->trophy = sfSprite_create();
    sfSprite_setTexture(sprt->trophy, sprt->pickups, sfTrue);
    sfSprite_setTextureRect(sprt->trophy, rect);
    sfSprite_setScale(sprt->trophy, scale);
}

void init_win(window *wndw, options *sprt)
{
    sfIntRect rect = {368, 0, 32, 71};
    sfVector2f scale = {4, 4};
    sprt->win = sfSprite_create();
    sfSprite_setTexture(sprt->win, sprt->pickups, sfTrue);
    sfSprite_setTextureRect(sprt->win, rect);
    sfSprite_setScale(sprt->win, scale);
}
