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
        draw_doors_leftc(ro->lvl, sprt, wd);
    if (x != 9 && ro->floor_rooms[y][x + 1] != ' '
    && ro->floor_rooms[y][x + 1] != '?' && rm->open == false)
        draw_doors_rightc(ro->lvl, sprt, wd);
    if (y != 0 && ro->floor_rooms[y - 1][x] != ' '
    && ro->floor_rooms[y - 1][x] != '?' && rm->open == false)
        draw_doors_topc(ro->lvl, sprt, wd);
    if (y != 9 && ro->floor_rooms[y + 1][x] != ' '
    && ro->floor_rooms[y + 1][x] != '?' && rm->open == false)
        draw_doors_botc(ro->lvl, sprt, wd);
}

void draw_doors(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt)
{
    int x = rm->actual_room[0];
    int y = rm->actual_room[1];
    if (rm->actual_room[0] == 4 && rm->actual_room[1] == 4)
        draw_tuto(wd, sprt);
    if (x != 0 && ro->floor_rooms[y][x - 1] != ' '
    && ro->floor_rooms[y][x - 1] != '?' && rm->open == true)
        draw_doors_lefto(ro->lvl, sprt, wd);
    if (x != 9 && ro->floor_rooms[y][x + 1] != ' '
    && ro->floor_rooms[y][x + 1] != '?' && rm->open == true)
        draw_doors_righto(ro->lvl, sprt, wd);
    if (y != 0 && ro->floor_rooms[y - 1][x] != ' '
    && ro->floor_rooms[y - 1][x] != '?' && rm->open == true)
        draw_doors_topo(ro->lvl, sprt, wd);
    if (y != 9 && ro->floor_rooms[y + 1][x] != ' '
    && ro->floor_rooms[y + 1][x] != '?' && rm->open == true)
        draw_doors_boto(ro->lvl, sprt, wd);
    reduce_draw_doors(rm, ro, wd, sprt);
}

void floor_pass(rooms *ro, reduce *red)
{
    ++ro->lvl;
    gen_main(ro);
    red->rm->actual_room[0] = 4;
    red->rm->actual_room[1] = 4;
}

static void reduce_doors_colisions(options *sprt, room *rm, player *py)
{
    sfIntRect overlap = {1, 1, 1, 1};
    sfIntRect doorthree = {916, 799, 10, 10};
    sfIntRect doorfour = {210, 468, 10, 10};
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
    sfIntRect doorone = {912, 110, 10, 10};
    sfIntRect doortwo = {1635, 452, 10, 10};
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
}