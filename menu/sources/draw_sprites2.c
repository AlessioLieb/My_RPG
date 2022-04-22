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

void draw_doors_topo(int lvl, options *sprt, sfRenderWindow *wd, char c)
{
    sfVector2f pos = {1920 / 2 - ((49 * 3.5) / 2), 65};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroopen);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortopen);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlopen);
    if (c == 'T') {
        door = sfSprite_copy(sprt->treasure_do);
        pos.y -= 20;
    }
    if (c == 'B') {
        door = sfSprite_copy(sprt->boss_do);
        pos.x -= 20;
        pos.y -= 20;
    }
    sfSprite_setPosition(door, pos);
    sfRenderWindow_drawSprite(wd, door, NULL);
    sprt->all_doors[0] = door;
    sprt->actual_doors[0] = true;
}

void draw_doors_boto(int lvl, options *sprt, sfRenderWindow *wd, char c)
{
    sfVector2f pos = {1920 / 2 - ((49 * 3.5) / 2) + 170, 1015};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroopen);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortopen);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlopen);
    if (c == 'T') {
        door = sfSprite_copy(sprt->treasure_do);
        pos.y += 20;
    }
    if (c == 'B') {
        door = sfSprite_copy(sprt->boss_do);
        pos.x += 20;
        pos.y += 20;
    }
    sfSprite_setPosition(door, pos);
    sfSprite_setRotation(door, 180);
    sfRenderWindow_drawSprite(wd, door, NULL);
    sprt->all_doors[2] = door;
    sprt->actual_doors[2] = true;
}

void draw_doors_righto(int lvl, options *sprt, sfRenderWindow *wd, char c)
{
    sfVector2f pos = {1820, 1080 / 2 - (49 * 3.5 / 2)};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroopen);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortopen);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlopen);
    if (c == 'T') {
        door = sfSprite_copy(sprt->treasure_do);
        pos.x += 20;
    }
    if (c == 'B') {
        door = sfSprite_copy(sprt->boss_do);
        pos.y -= 20;
        pos.x += 20;
    }
    sfSprite_setPosition(door, pos);
    sfSprite_setRotation(door, 90);
    sfRenderWindow_drawSprite(wd, door, NULL);
    sprt->all_doors[1] = door;
    sprt->actual_doors[1] = true;
}

void draw_doors_lefto(int lvl, options *sprt, sfRenderWindow *wd, char c)
{
    sfVector2f pos = {100, 1080 / 2 - (49 * 3.5 / 2) + 170};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroopen);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortopen);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlopen);
    if (c == 'T') {
        door = sfSprite_copy(sprt->treasure_do);
        pos.x -= 20;
    }
    if (c == 'B') {
        door = sfSprite_copy(sprt->boss_do);
        pos.y -= 20;
        pos.x -= 20;
    }
    sfSprite_setRotation(door, -90);
    sfSprite_setPosition(door, pos);
    sfRenderWindow_drawSprite(wd, door, NULL);
    sprt->all_doors[3] = door;
    sprt->actual_doors[3] = true;
}
