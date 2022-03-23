/*
** EPITECH PROJECT, 2022
** Procedural generation test
** File description:
** verif_rooms.c
*/

#include "procedural.h"

int ver_start(char **map, int x)
{
    int start = x / 2 - 1;
    if (map[start][start] != 'S' || connected_b(map, start, start, x) == 1)
        return (1);
}

int ver_shop(char **map, int len)
{
    int x;
    int y;

    for (int i = 0; i != len; ++i)
        for (int j = 0; j != len; ++j) {
            map[i][j] == 'M' ? x = i : 0;
            map[i][j] == 'M' ? y = j : 0;
        }
    if ((x != 0 && map[x - 1][y] == 'T') || (y != 0 && map[x][y - 1] == 'T')
    || (x != len - 1 && map[x + 1][y] == 'T')
    || (y != len - 1 && map[x][y + 1] == 'T'))
        return (1);
}

int wrong_map(char **map, int x)
{
    int start = 0;
    int treasure = 0;
    int boss = 0;
    int shop = 0;
    int secret = 0;
    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x; ++j) {
            (map[i][j] == 'B') ? ++boss : 0;
            (map[i][j] == 'S') ? ++start : 0;
            (map[i][j] == '?') ? ++secret : 0;
            (map[i][j] == 'M') ? ++shop : 0;
            (map[i][j] == 'T') ? ++treasure : 0;
        }
    if (start != 1 || treasure != 1 || boss != 1 || shop != 1 || secret != 1)
        return (1);
    if (ver_start(map, x) == 1 || ver_shop(map, x) == 1)
        return (1);
    return (0);
}
