/*
** EPITECH PROJECT, 2022
** Procedural generation test
** File description:
** tools3.c
*/

#include "procedural.h"

void create_verge(char **map, int x, rooms *room)
{
    int count = 0;
    int j;
    int i;
    int last_i;
    int last_j;

    while (count != 2) {
        j = rand() % x;
        i = rand() % x;
        if (connected_b(map, i, j, x) == 0
        && connected_room(map, i, j, x) == 3 && (last_i - i > 1 ||
        i - last_i > 1) && (last_j - j > 1 || j - last_j > 1)
        && map[i][j] != 'B') {
            room->verge[count] = i * x + j;
            map[i][j] = 'X';
            ++count;
        }
        last_i = i;
        last_j = j;
    }
}

void find_verge(char **map, int x, rooms *room)
{
    int count = 0;

    room->verge = malloc(sizeof(int) * 100);
    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x ; ++j) {
            (map[i][j] == 'X' && connected_room(map, i, j, x) == 3)
            ? room->verge[count] = i * x + j : 0;
            (map[i][j] == 'X' && connected_room(map, i, j, x) == 3)
            ? ++count : 0;
        }
    room->verge[count] = '\0';
    if (count < 2)
        create_verge(map, x, room);
}

int entirely_connected(char **map, int x, int y, int len)
{
    if (x == 0 || y == 0 || x == len - 1 || y == len - 1)
        return (0);
    if (map[x + 1][y] == 'X' && map[x][y + 1] == 'X' && map[x - 1][y] == 'X'
    && map[x][y - 1] == 'X' && map[x - 1][y - 1] == 'X'
    && map[x - 1][y + 1] == 'X' && map[x + 1][y - 1] == 'X'
    && map[x + 1][y + 1] == 'X')
        return (1);
    return (0);
}
