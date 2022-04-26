/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** manage_rooms.c
*/

#include "../includes/motor.h"

void reduce_draw_doors(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt)
{
    int x = rm->actual_room[0];
    int y = rm->actual_room[1];
    if (x != 0 && ro->floor_rooms[y][x - 1] != ' '
    && ro->floor_rooms[y][x - 1] != '?' && rm->open == false)
        draw_doors_leftc(ro->lvl, sprt, wd, ro->floor_rooms[y][x - 1]);
    if (x != 9 && ro->floor_rooms[y][x + 1] != ' '
    && ro->floor_rooms[y][x + 1] != '?' && rm->open == false)
        draw_doors_rightc(ro->lvl, sprt, wd, ro->floor_rooms[y][x + 1]);
    if (y != 0 && ro->floor_rooms[y - 1][x] != ' '
    && ro->floor_rooms[y - 1][x] != '?' && rm->open == false)
        draw_doors_topc(ro->lvl, sprt, wd, ro->floor_rooms[y - 1][x]);
    if (y != 9 && ro->floor_rooms[y + 1][x] != ' '
    && ro->floor_rooms[y + 1][x] != '?' && rm->open == false)
        draw_doors_botc(ro->lvl, sprt, wd, ro->floor_rooms[y + 1][x]);
}

void reduce_draw_traps(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt)
{
    int y = rm->actual_room[0];
    int x = rm->actual_room[1];
    sfVector2f pos = {1920 / 2 - ((32 * 3.5) / 2), 265};
    if (ro->floor_rooms[x][y] == 'B' && rm->open == true && ro->lvl != 4) {
        sprt->actual_doors[4] = true;
        sfSprite_setPosition(sprt->trap, pos);
        sfRenderWindow_drawSprite(wd, sprt->trap, NULL);
    } else
        sprt->actual_doors[4] = false;
    if (ro->floor_rooms[x][y] == 'B' && rm->open == true && ro->lvl == 4
    && sprt->win_cond == false) {
        sfSprite_setPosition(sprt->trophy, pos);
        sfRenderWindow_drawSprite(wd, sprt->trophy, NULL);
        sprt->actual_doors[5] = true;
    } else
        sprt->actual_doors[5] = false;
}

void draw_doors(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt)
{
    int x = rm->actual_room[0];
    int y = rm->actual_room[1];
    if (rm->actual_room[0] == 4 && rm->actual_room[1] == 4)
        draw_tuto(wd, sprt);
    if (x != 0 && ro->floor_rooms[y][x - 1] != ' '
    && ro->floor_rooms[y][x - 1] != '?' && rm->open == true)
        draw_doors_lefto(ro->lvl, sprt, wd, ro->floor_rooms[y][x - 1]);
    if (x != 9 && ro->floor_rooms[y][x + 1] != ' '
    && ro->floor_rooms[y][x + 1] != '?' && rm->open == true)
        draw_doors_righto(ro->lvl, sprt, wd, ro->floor_rooms[y][x + 1]);
    if (y != 0 && ro->floor_rooms[y - 1][x] != ' '
    && ro->floor_rooms[y - 1][x] != '?' && rm->open == true)
        draw_doors_topo(ro->lvl, sprt, wd, ro->floor_rooms[y - 1][x]);
    if (y != 9 && ro->floor_rooms[y + 1][x] != ' '
    && ro->floor_rooms[y + 1][x] != '?' && rm->open == true)
        draw_doors_boto(ro->lvl, sprt, wd, ro->floor_rooms[y + 1][x]);
    reduce_draw_doors(rm, ro, wd, sprt);
    reduce_draw_tb(rm, ro, wd, sprt);
    close_door(ro, sprt, x, y);
    reduce_draw_traps(rm, ro, wd, sprt);
}

static void reduce_doors_colisions(options *sprt, room *rm, player *py)
{
    sfIntRect overlap = {1, 1, 1, 1};
    sfIntRect doorthree = {916, 799, 30, 10};
    sfIntRect doorfour = {210, 468, 10, 30};
    sfIntRect player = sfSprite_getTextureRect(py->sp);
    sfVector2f p_pos = sfSprite_getPosition(py->sp);
    player.left = p_pos.x;
    player.top = p_pos.y;
    if (sfIntRect_intersects(&doorthree, &player, &overlap) == true
    && sprt->actual_doors[2] == true) {
        ++rm->actual_room[1];
        sfSprite_setPosition(py->sp, (sfVector2f) {912, 160});
    }
    if (sfIntRect_intersects(&doorfour, &player, &overlap) == true
    && sprt->actual_doors[3] == true) {
        --rm->actual_room[0];
        sfSprite_setPosition(py->sp, (sfVector2f) {1585, 452});
    }
}

void doors_colisions(options *sprt, room *rm, player *py)
{
    sfIntRect overlap = {1, 1, 1, 1};
    sfIntRect doorone = {912, 110, 30, 10};
    sfIntRect doortwo = {1635, 452, 10, 30};
    sfIntRect player = sfSprite_getTextureRect(py->sp);
    sfVector2f p_pos = sfSprite_getPosition(py->sp);
    player.left = p_pos.x;
    player.top = p_pos.y;
    if (sfIntRect_intersects(&doorone, &player, &overlap) == true
    && sprt->actual_doors[0] == true) {
        --rm->actual_room[1];
        sfSprite_setPosition(py->sp, (sfVector2f) {916, 749});
    }
    if (sfIntRect_intersects(&doortwo, &player, &overlap) == true
    && sprt->actual_doors[1] == true) {
        ++rm->actual_room[0];
        sfSprite_setPosition(py->sp, (sfVector2f) {260, 468});
    }
    reduce_doors_colisions(sprt, rm, py);
    trap_colisions(sprt, rm, py);
    trophy_colisions(sprt, rm, py);
}
