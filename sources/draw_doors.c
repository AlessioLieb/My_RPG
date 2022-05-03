/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** draw_doors.c
*/

#include "../includes/motor.h"

void deep_reduce_boss(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt)
{
    int x = rm->actual_room[0];
    int y = rm->actual_room[1];
    if (x != 0 && ro->floor_rooms[y][x - 1] != ' '
    && ro->floor_rooms[y][x - 1] != '?' && rm->open == false)
        draw_doors_leftc(ro->lvl, sprt, wd, 'B');
    if (x != 9 && ro->floor_rooms[y][x + 1] != ' '
    && ro->floor_rooms[y][x + 1] != '?' && rm->open == false)
        draw_doors_rightc(ro->lvl, sprt, wd, 'B');
    if (y != 0 && ro->floor_rooms[y - 1][x] != ' '
    && ro->floor_rooms[y - 1][x] != '?' && rm->open == false)
        draw_doors_topc(ro->lvl, sprt, wd, 'B');
    if (y != 9 && ro->floor_rooms[y + 1][x] != ' '
    && ro->floor_rooms[y + 1][x] != '?' && rm->open == false)
        draw_doors_botc(ro->lvl, sprt, wd, 'B');
}

void reduce_boss_doors(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt)
{
    int x = rm->actual_room[0];
    int y = rm->actual_room[1];
    if (ro->floor_rooms[y][x] == 'B') {
        if (x != 0 && ro->floor_rooms[y][x - 1] != ' '
        && ro->floor_rooms[y][x - 1] != '?' && rm->open == true)
            draw_doors_lefto(ro->lvl, sprt, wd, 'B');
        if (x != 9 && ro->floor_rooms[y][x + 1] != ' '
        && ro->floor_rooms[y][x + 1] != '?' && rm->open == true)
            draw_doors_righto(ro->lvl, sprt, wd, 'B');
        if (y != 0 && ro->floor_rooms[y - 1][x] != ' '
        && ro->floor_rooms[y - 1][x] != '?' && rm->open == true)
            draw_doors_topo(ro->lvl, sprt, wd, 'B');
        if (y != 9 && ro->floor_rooms[y + 1][x] != ' '
        && ro->floor_rooms[y + 1][x] != '?' && rm->open == true)
            draw_doors_boto(ro->lvl, sprt, wd, 'B');
        deep_reduce_boss(rm, ro, wd, sprt);
    }
}

void reduce_draw_tb(room *rm, rooms *ro, sfRenderWindow *wd, options *sprt)
{
    int x = rm->actual_room[0];
    int y = rm->actual_room[1];
    if (ro->floor_rooms[y][x] == 'T') {
        if (x != 0 && ro->floor_rooms[y][x - 1] != ' '
        && ro->floor_rooms[y][x - 1] != '?' && rm->open == true)
            draw_doors_lefto(ro->lvl, sprt, wd, 'T');
        if (x != 9 && ro->floor_rooms[y][x + 1] != ' '
        && ro->floor_rooms[y][x + 1] != '?' && rm->open == true)
            draw_doors_righto(ro->lvl, sprt, wd, 'T');
        if (y != 0 && ro->floor_rooms[y - 1][x] != ' '
        && ro->floor_rooms[y - 1][x] != '?' && rm->open == true)
            draw_doors_topo(ro->lvl, sprt, wd, 'T');
        if (y != 9 && ro->floor_rooms[y + 1][x] != ' '
        && ro->floor_rooms[y + 1][x] != '?' && rm->open == true)
            draw_doors_boto(ro->lvl, sprt, wd, 'T');
    }
    reduce_boss_doors(rm, ro, wd, sprt);
}
