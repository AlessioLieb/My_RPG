/*
** EPITECH PROJECT, 2022
** Procedural generation test
** File description:
** tools.c
*/

#include "../includes/procedural.h"

int count_rooms(char **map, int x)
{
    int count = 0;

    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x; ++j)
            (map[i][j] == 'X') ? ++count : 0;
    return (count);
}

void create_rooms(rooms *room)
{
    room->lvl_rooms = malloc(sizeof(int) * 5);
    create_lvl(room);
}

int len(int px, int py, int cx, int cy)
{
    int r = pow(px - cx, 2) + pow(py - cy, 2);

    if (r < 0)
        r = -r;
    return (r);
}

int connected_room(char **map, int maxx, int maxy, int x)
{
    int count = 0;

    (maxy == x - 1 || map[maxx][maxy + 1] == ' ') ? ++count : 0;
    (maxy == 0 || map[maxx][maxy - 1] == ' ') ? ++count : 0;
    (maxx == x - 1 || map[maxx + 1][maxy] == ' ') ? ++count : 0;
    (maxx == 0 || map[maxx - 1][maxy] == ' ') ? ++count : 0;
    return (count);
}

void create_lvl(rooms *room)
{
    int count = 1;
    int r = rand() % 2;
    if (r == 0)
        room->lvl_rooms[0] = 6;
    if (r == 1)
        room->lvl_rooms[0] = 7;
    for (int i = 1; i != 5; ++i) {
        r = rand() % 3;
        room->lvl_rooms[count] = room->lvl_rooms[count - 1] + r + 5;
        ++count;
    }
}
