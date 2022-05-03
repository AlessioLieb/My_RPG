/*
** EPITECH PROJECT, 2021
** menu
** File description:
** reduce_draw_mini_map.c
*/

#include "../includes/motor.h"

static void reduce_draw_normal(sfRenderWindow *wd, rooms *ro, int x, int y)
{
    sfVector2f pos = {1525, 0};

    if (ro->mini_map[x][y] == 'X') {
        pos.x += (y + 1) * (9 * 3.5);
        pos.y += (x + 1) * (8 * 3.5);
        sfSprite_setPosition(ro->n_room_known, pos);
        sfRenderWindow_drawSprite(wd, ro->n_room_known, NULL);
    }
    if (ro->mini_map[x][y] == 'x') {
        pos.x += (y + 1) * (9 * 3.5);
        pos.y += (x + 1) * (8 * 3.5);
        sfSprite_setPosition(ro->n_room_unknown, pos);
        sfRenderWindow_drawSprite(wd, ro->n_room_unknown, NULL);
    }
}

static void reduce_draw_boss(sfRenderWindow *wd, rooms *ro, int x, int y)
{
    sfVector2f pos = {1525, 0};

    if (ro->mini_map[x][y] == 'B') {
        pos.x += (y + 1) * (9 * 3.5);
        pos.y += (x + 1) * (8 * 3.5);
        sfSprite_setPosition(ro->b_room_known, pos);
        sfRenderWindow_drawSprite(wd, ro->b_room_known, NULL);
    }
    if (ro->mini_map[x][y] == 'b') {
        pos.x += (y + 1) * (9 * 3.5);
        pos.y += (x + 1) * (8 * 3.5);
        sfSprite_setPosition(ro->b_room_unknown, pos);
        sfRenderWindow_drawSprite(wd, ro->b_room_unknown, NULL);
    }
}

static void reduce_draw_treasure(sfRenderWindow *wd, rooms *ro, int x, int y)
{
    sfVector2f pos = {1525, 0};

    if (ro->mini_map[x][y] == 'T') {
        pos.x += (y + 1) * (9 * 3.5);
        pos.y += (x + 1) * (8 * 3.5);
        sfSprite_setPosition(ro->t_room_known, pos);
        sfRenderWindow_drawSprite(wd, ro->t_room_known, NULL);
    }
    if (ro->mini_map[x][y] == 't') {
        pos.x += (y + 1) * (9 * 3.5);
        pos.y += (x + 1) * (8 * 3.5);
        sfSprite_setPosition(ro->t_room_unknown, pos);
        sfRenderWindow_drawSprite(wd, ro->t_room_unknown, NULL);
    }
}

static void reduce_draw_shop(sfRenderWindow *wd, rooms *ro, int x, int y)
{
    sfVector2f pos = {1525, 0};

    if (ro->mini_map[x][y] == 'M') {
        pos.x += (y + 1) * (9 * 3.5);
        pos.y += (x + 1) * (8 * 3.5);
        sfSprite_setPosition(ro->s_room_known, pos);
        sfRenderWindow_drawSprite(wd, ro->s_room_known, NULL);
    }
    if (ro->mini_map[x][y] == 'm') {
        pos.x += (y + 1) * (9 * 3.5);
        pos.y += (x + 1) * (8 * 3.5);
        sfSprite_setPosition(ro->s_room_unknown, pos);
        sfRenderWindow_drawSprite(wd, ro->s_room_unknown, NULL);
    }
}

void reduce_draw_mini_map(int x, room *rm, rooms *ro, sfRenderWindow *wd)
{
    sfVector2f pos = {1525, 0};
    for (int y = 0; y != 10; ++y) {
        reduce_draw_normal(wd, ro, x, y);
        reduce_draw_boss(wd, ro, x, y);
        reduce_draw_treasure(wd, ro, x, y);
        reduce_draw_shop(wd, ro, x, y);
        if (x == rm->actual_room[1] && y == rm->actual_room[0]) {
            pos.x = 1525;
            pos.y = 0;
            pos.x += (y + 1) * (9 * 3.5);
            pos.y += (x + 1) * (8 * 3.5);
            sfSprite_setPosition(ro->actual_room_sprite, pos);
            sfRenderWindow_drawSprite(wd, ro->actual_room_sprite, NULL);
        }
        pos.x = 1525;
        pos.y = 0;
    }
}
