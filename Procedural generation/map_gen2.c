/*
** EPITECH PROJECT, 2022
** Procedural generation test
** File description:
** map_gen2.c
*/

#include "procedural.h"

int reduce_secret_room(int i, int *possible_s_rooms, int count, char **map)
{
    for (int j = 0; j != 10; ++j) {
        (map[i][j] == ' ' && connected_room_fr(map, i, j, 10) >= 2
        && connected_b(map, i, j, 10) == 0)
        ? possible_s_rooms[count] = i * 10 + j : 0;
        (map[i][j] == ' ' && connected_room_fr(map, i, j, 10) >= 2
        && connected_b(map, i, j, 10) == 0) ? ++count : 0;
    }
    return (count);
}

int place_secret_room(char **map, int x, rooms *room)
{
    int count = 0;
    int *possible_s_rooms = malloc(sizeof(int) * 100);
    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x; ++j) {
            (map[i][j] == ' ' && connected_room_fr(map, i, j, x) > 2
            && connected_b(map, i, j, x) == 0)
            ? possible_s_rooms[count] = i * x + j : 0;
            (map[i][j] == ' ' && connected_room_fr(map, i, j, x) > 2
            && connected_b(map, i, j, x) == 0) ? ++count : 0;
        }
    if (count == 0)
        for (int i = 0; i != x; ++i)
            count = reduce_secret_room(i, possible_s_rooms, count, map);
    if (count != 0) {
        int r = rand() % count;
        while (possible_s_rooms[r] == 0)
            r = rand() % count;
        map[possible_s_rooms[r] / x][possible_s_rooms[r] % x] = '?';
    }
    free(possible_s_rooms);
}

void break_walls(char **map, int x)
{
    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x; ++j)
            (map[i][j] == 'X' && entirely_connected(map, i, j, x) == 1)
            ? map[i][j] = ' ' : 0;
}
