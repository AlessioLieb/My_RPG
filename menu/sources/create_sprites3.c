/*
** EPITECH PROJECT, 2021
** menu
** File description:
** create_sprites3.c
*/

#include "../includes/menu.h"

void init_tdc(window *wndw, options *sprt)
{
    sfIntRect rect = {0, 0, 49, 38};
    sfVector2f scale = {3.5, 3.5};
    sprt->treasure_dc = sfSprite_create();
    sfSprite_setTexture(sprt->treasure_dc, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->treasure_dc, rect);
    sfSprite_setScale(sprt->treasure_dc, scale);
}

void init_tdo(window *wndw, options *sprt)
{
    sfIntRect rect = {49, 0, 49, 38};
    sfVector2f scale = {3.5, 3.5};
    sprt->treasure_do = sfSprite_create();
    sfSprite_setTexture(sprt->treasure_do, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->treasure_do, rect);
    sfSprite_setScale(sprt->treasure_do, scale);
}

void init_bdc(window *wndw, options *sprt)
{
    sfIntRect rect = {0, 171, 61, 39};
    sfVector2f scale = {3.5, 3.5};
    sprt->boss_dc = sfSprite_create();
    sfSprite_setTexture(sprt->boss_dc, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->boss_dc, rect);
    sfSprite_setScale(sprt->boss_dc, scale);
}

void init_bdo(window *wndw, options *sprt)
{
    sfIntRect rect = {61, 171, 61, 76};
    sfVector2f scale = {3.5, 3.5};
    sprt->boss_do = sfSprite_create();
    sfSprite_setTexture(sprt->boss_do, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->boss_do, rect);
    sfSprite_setScale(sprt->boss_do, scale);
}

void init_trap(window *wndw, options *sprt)
{
    sfIntRect rect = {14, 261, 32, 32};
    sfVector2f scale = {3.5, 3.5};
    sprt->trap = sfSprite_create();
    sfSprite_setTexture(sprt->trap, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->trap, rect);
    sfSprite_setScale(sprt->trap, scale);
}
