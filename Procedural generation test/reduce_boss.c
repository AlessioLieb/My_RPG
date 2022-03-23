/*
** EPITECH PROJECT, 2022
** Procedural generation test
** File description:
** reduce_boss.c
*/

#include "procedural.h"

int reduce_place_r_boss(char **map, int i, int x)
{
    for (int j = 0; j != x; ++j)
        if (map[i][j] == 'X' && connected_room(map, i, j, x) == 3) {
            map[i][j] = 'B';
            return (0);
        }
    return (1);
}

int deep_reduce_place_boss(int x, char **map, int i)
{
    for (int j = 0; j != x; ++j) {
        if (i > 0 && map[i][j] == 'X' &&
        connected_room(map, i - 1, j, x) == 3) {
            map[i - 1][j] = 'B';
            return (0);
        }
        if (j > 0 && map[i][j] == 'X' &&
        connected_room(map, i, j - 1, x) == 3) {
            map[i][j - 1] = 'B';
            return (0);
        }
    }
    return (1);
}

int reduce_replace_boss(char **map, int x, int i)
{
    for (int j = x - 1; j != 0; --j)
        if (map[i][j] == 'X' && connected_room(map, i, j, x) == 3) {
            map[i][j] = 'B';
            return (0);
        }
    return (1);
}

void another_boss_reduce(int *max, int i, int x, char **map)
{
    for (int j = 0; j != x; ++j)
        if (map[i][j] == 'X') {
            max[3] = len((x / 2 - 1), (x / 2 - 1), i, j);
            (max[0] < max[3]) ? max[0] = max[3] : 0;
            (max[0] < max[3]) ? max[1] = i : 0;
            (max[0] < max[3]) ? max[2] = j : 0;
    }
}
