/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** draw_sprites2.c
*/

#include "../includes/motor.h"

void draw_tuto(sfRenderWindow *wd, options *sprt)
{
    sfRenderWindow_drawSprite(wd, sprt->tutorial, NULL);
}

void draw_doors_top(int lvl, options *sprt, sfRenderWindow *wd)
{
    sfVector2f pos = {1920 / 2 - ((49 * 3.5) / 2), 65};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroopen);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortopen);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlopen);
    sfSprite_setPosition(door, pos);
    sfRenderWindow_drawSprite(wd, door, NULL);

}

void draw_doors_bot(int lvl, options *sprt, sfRenderWindow *wd)
{
    sfVector2f pos = {1920 / 2 - ((49 * 3.5) / 2) + 170, 1015};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroopen);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortopen);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlopen);
    sfSprite_setPosition(door, pos);
    sfSprite_setRotation(door, 180);
    sfRenderWindow_drawSprite(wd, door, NULL);

}

void draw_doors_right(int lvl, options *sprt, sfRenderWindow *wd)
{
    sfVector2f pos = {1820, 1080 / 2 - (49 * 3.5 / 2)};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroopen);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortopen);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlopen);
    sfSprite_setPosition(door, pos);
    sfSprite_setRotation(door, 90);
    sfRenderWindow_drawSprite(wd, door, NULL);

}

void draw_doors_left(int lvl, options *sprt, sfRenderWindow *wd)
{
    sfVector2f pos = {100, 1080 / 2 - (49 * 3.5 / 2) + 170};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroopen);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortopen);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlopen);
    sfSprite_setRotation(door, -90);
    sfSprite_setPosition(door, pos);
    sfRenderWindow_drawSprite(wd, door, NULL);

}
