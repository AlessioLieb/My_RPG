/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** draw_sprites3.c
*/

#include "../includes/motor.h"

void draw_doors_topc(int lvl, options *sprt, sfRenderWindow *wd)
{
    sfVector2f pos = {1920 / 2 - ((49 * 3.5) / 2), 65};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroclose);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortclose);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlclose);
    sfSprite_setPosition(door, pos);
    sfRenderWindow_drawSprite(wd, door, NULL);
}

void draw_doors_botc(int lvl, options *sprt, sfRenderWindow *wd)
{
    sfVector2f pos = {1920 / 2 - ((49 * 3.5) / 2) + 170, 1015};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroclose);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortclose);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlclose);
    sfSprite_setPosition(door, pos);
    sfSprite_setRotation(door, 180);
    sfRenderWindow_drawSprite(wd, door, NULL);
}

void draw_doors_rightc(int lvl, options *sprt, sfRenderWindow *wd)
{
    sfVector2f pos = {1820, 1080 / 2 - (49 * 3.5 / 2)};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroclose);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortclose);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlclose);
    sfSprite_setPosition(door, pos);
    sfSprite_setRotation(door, 90);
    sfRenderWindow_drawSprite(wd, door, NULL);
}

void draw_doors_leftc(int lvl, options *sprt, sfRenderWindow *wd)
{
    sfVector2f pos = {100, 1080 / 2 - (49 * 3.5 / 2) + 170};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroclose);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortclose);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlclose);
    sfSprite_setRotation(door, -90);
    sfSprite_setPosition(door, pos);
    sfRenderWindow_drawSprite(wd, door, NULL);
}
