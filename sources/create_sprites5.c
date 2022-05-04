/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** create_sprites5.c
*/

#include "../includes/menu.h"

void init_lvl_m(window *wndw, options *sprt)
{
    sprt->lvl_m_sprt = sfSprite_create();
    sfSprite_setTexture(sprt->lvl_m_sprt, sprt->lvl_m_txt, sfTrue);
}

void init_dlc(window *wndw, options *sprt)
{
    sfIntRect rect = {49, 369, 49, 33};
    sfVector2f scale = {3.5, 3.5};
    sprt->doorlclose = sfSprite_create();
    sfSprite_setTexture(sprt->doorlclose, sprt->doors, sfTrue);
    sfSprite_setTextureRect(sprt->doorlclose, rect);
    sfSprite_setScale(sprt->doorlclose, scale);
}
