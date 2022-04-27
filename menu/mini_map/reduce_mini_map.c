/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** reduce_mini_map.c
*/

#include "../includes/motor.h"

void reduce_shop_minimap(rooms *ro, room *rm)
{
    int x = rm->actual_room[1];
    int y = rm->actual_room[0];

    if (ro->floor_rooms[x][y] == 'M')
        ro->mini_map[x][y] = 'M';
    if (x != 0 && ro->floor_rooms[x - 1][y] == 'M'
    && ro->mini_map[x - 1][y] != 'M')
        ro->mini_map[x - 1][y] = 'm';
    if (x != 9 && ro->floor_rooms[x + 1][y] == 'M'
    && ro->mini_map[x + 1][y] != 'M')
        ro->mini_map[x + 1][y] = 'm';
    if (y != 0 && ro->floor_rooms[x][y - 1] == 'M'
    && ro->mini_map[x][y - 1] != 'M')
        ro->mini_map[x][y - 1] = 'm';
    if (y != 9 && ro->floor_rooms[x][y + 1] == 'M'
    && ro->mini_map[x][y + 1] != 'M')
        ro->mini_map[x][y + 1] = 'm';
}

void reduce_boss_minimap(rooms *ro, room *rm)
{
    int x = rm->actual_room[1];
    int y = rm->actual_room[0];

    if (ro->floor_rooms[x][y] == 'B')
        ro->mini_map[x][y] = 'B';
    if (x != 0 && ro->floor_rooms[x - 1][y] == 'B'
    && ro->mini_map[x - 1][y] != 'B')
        ro->mini_map[x - 1][y] = 'b';
    if (x != 9 && ro->floor_rooms[x + 1][y] == 'B'
    && ro->mini_map[x + 1][y] != 'B')
        ro->mini_map[x + 1][y] = 'b';
    if (y != 0 && ro->floor_rooms[x][y - 1] == 'B'
    && ro->mini_map[x][y - 1] != 'B')
        ro->mini_map[x][y - 1] = 'b';
    if (y != 9 && ro->floor_rooms[x][y + 1] == 'B'
    && ro->mini_map[x][y + 1] != 'B')
        ro->mini_map[x][y + 1] = 'b';
}

void reduce_treasure_minimap(rooms *ro, room *rm)
{
    int x = rm->actual_room[1];
    int y = rm->actual_room[0];

    if (ro->floor_rooms[x][y] == 'T')
        ro->mini_map[x][y] = 'T';
    if (x != 0 && ro->floor_rooms[x - 1][y] == 'T'
    && ro->mini_map[x - 1][y] != 'T')
        ro->mini_map[x - 1][y] = 't';
    if (x != 9 && ro->floor_rooms[x + 1][y] == 'T'
    && ro->mini_map[x + 1][y] != 'T')
        ro->mini_map[x + 1][y] = 't';
    if (y != 0 && ro->floor_rooms[x][y - 1] == 'T'
    && ro->mini_map[x][y - 1] != 'T')
        ro->mini_map[x][y - 1] = 't';
    if (y != 9 && ro->floor_rooms[x][y + 1] == 'T'
    && ro->mini_map[x][y + 1] != 'T')
        ro->mini_map[x][y + 1] = 't';
}
