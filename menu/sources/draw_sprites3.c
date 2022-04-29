/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** draw_sprites3.c
*/

#include "../includes/motor.h"

void draw_doors_topc(int lvl, options *sprt, sfRenderWindow *wd, char c)
{
    sfVector2f pos = {1920 / 2 - ((49 * 3.5) / 2), 65};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroclose);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortclose);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlclose);
    if (c == 'T') {
        door = sfSprite_copy(sprt->treasure_dc);
        pos.y -= 20;
    }
    if (c == 'B') {
        door = sfSprite_copy(sprt->boss_dc);
        pos.x -= 20;
        pos.y -= 20;
    }
    sfSprite_setPosition(door, pos);
    sfRenderWindow_drawSprite(wd, door, NULL);
    sprt->actual_doors[0] = false;
}

void draw_doors_botc(int lvl, options *sprt, sfRenderWindow *wd, char c)
{
    sfVector2f pos = {1920 / 2 - ((49 * 3.5) / 2) + 170, 1015};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroclose);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortclose);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlclose);
    if (c == 'T') {
        door = sfSprite_copy(sprt->treasure_dc);
        pos.y += 20;
    }
    if (c == 'B')
        door = sfSprite_copy(sprt->boss_dc);
    c == 'B' ? pos.x += 20 : 0;
    c == 'B' ? pos.y += 20 : 0;
    sfSprite_setPosition(door, pos);
    sfSprite_setRotation(door, 180);
    sfRenderWindow_drawSprite(wd, door, NULL);
    sprt->actual_doors[2] = false;
}

void draw_doors_rightc(int lvl, options *sprt, sfRenderWindow *wd, char c)
{
    sfVector2f pos = {1820, 1080 / 2 - (49 * 3.5 / 2)};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroclose);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortclose);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlclose);
    if (c == 'T') {
        door = sfSprite_copy(sprt->treasure_dc);
        pos.x += 20;
    }
    if (c == 'B')
        door = sfSprite_copy(sprt->boss_dc);
    c == 'B' ? pos.y -= 20 : 0;
    c == 'B' ? pos.x += 20 : 0;
    sfSprite_setPosition(door, pos);
    sfSprite_setRotation(door, 90);
    sfRenderWindow_drawSprite(wd, door, NULL);
    sprt->actual_doors[1] = false;
}

void draw_doors_leftc(int lvl, options *sprt, sfRenderWindow *wd, char c)
{
    sfVector2f pos = {100, 1080 / 2 - (49 * 3.5 / 2) + 170};
    sfSprite *door;
    if (lvl == 0 || lvl == 1)
        door = sfSprite_copy(sprt->dooroclose);
    if (lvl == 2 || lvl == 3)
        door = sfSprite_copy(sprt->doortclose);
    if (lvl == 4)
        door = sfSprite_copy(sprt->doorlclose);
    if (c == 'T') {
        door = sfSprite_copy(sprt->treasure_dc);
        pos.x -= 20;
    }
    if (c == 'B') {
        door = sfSprite_copy(sprt->boss_dc);
        pos.x -= 20;
    }
    sfSprite_setRotation(door, -90);
    sfSprite_setPosition(door, pos);
    sfRenderWindow_drawSprite(wd, door, NULL);
    sprt->actual_doors[3] = false;
}

void draw_all(sfRenderWindow *wd, reduce *red, options *sprt)
{
    draw_room(wd, red, red->ro);
    draw_doors(red->rm, red->ro, wd, sprt);
    draw_stone(red->rm, wd);
}
