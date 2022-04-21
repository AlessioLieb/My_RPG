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
