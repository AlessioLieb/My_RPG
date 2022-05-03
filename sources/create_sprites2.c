/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** create_sprites2.c
*/

#include "../includes/menu.h"

void init_doo(window *wndw, options *sprt)
{
    sfIntRect rect = {0, 303, 49, 33};
    sfVector2f scale = {3.5, 3.5};
    sprt->dooroopen = sfSprite_create();
    sfSprite_setTexture(sprt->dooroopen, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->dooroopen, rect);
    sfSprite_setScale(sprt->dooroopen, scale);
}

void init_doc(window *wndw, options *sprt)
{
    sfIntRect rect = {49, 303, 49, 33};
    sfVector2f scale = {3.5, 3.5};
    sprt->dooroclose = sfSprite_create();
    sfSprite_setTexture(sprt->dooroclose, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->dooroclose, rect);
    sfSprite_setScale(sprt->dooroclose, scale);
}

void init_dto(window *wndw, options *sprt)
{
    sfIntRect rect = {0, 336, 49, 33};
    sfVector2f scale = {3.5, 3.5};
    sprt->doortopen = sfSprite_create();
    sfSprite_setTexture(sprt->doortopen, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->doortopen, rect);
    sfSprite_setScale(sprt->doortopen, scale);
}

void init_dtc(window *wndw, options *sprt)
{
    sfIntRect rect = {49, 336, 49, 33};
    sfVector2f scale = {3.5, 3.5};
    sprt->doortclose = sfSprite_create();
    sfSprite_setTexture(sprt->doortclose, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->doortclose, rect);
    sfSprite_setScale(sprt->doortclose, scale);
}

void init_dlo(window *wndw, options *sprt)
{
    sfIntRect rect = {0, 369, 49, 33};
    sfVector2f scale = {3.5, 3.5};
    sprt->doorlopen = sfSprite_create();
    sfSprite_setTexture(sprt->doorlopen, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->doorlopen, rect);
    sfSprite_setScale(sprt->doorlopen, scale);
}
