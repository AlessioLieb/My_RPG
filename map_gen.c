/*
** EPITECH PROJECT, 2022
** Procedural generation test
** File description:
** map_gen.c
*/

#include "procedural.h"

void procedural_gen(char **map, int x, rooms *room, int lvl)
{
    int init_x1 = x / 2 - 1;
    int init_y1 = x / 2 - 1;
    map[x / 2 - 1][x / 2 - 1] = 'S';
    int r_move1;
    while (count_rooms(map, x) != room->lvl_rooms[lvl]) {
        r_move1 = rand() % 4;
        if (r_move1 == 0 && init_x1 < x - 1)
            init_x1 = reduce_r_gen(init_x1, init_y1, map);
        if (r_move1 == 2 && init_x1 > 0)
            init_x1 = reduce_l_gen(init_x1, init_y1, map);
        if (r_move1 == 1 && init_y1 < x - 1)
            init_y1 = reduce_d_gen(init_x1, init_y1, map);
        if (r_move1 == 3 && init_y1 > 0)
            init_y1 = reduce_u_gen(init_x1, init_y1, map);
    }
}

int place_r_boss(char **map, int x)
{
    for (int i = 0; i != x; ++i)
        if (reduce_place_r_boss(map, i, x) == 0)
            return (0);
    for (int i = 0; i != x; ++i)
        if (deep_reduce_place_boss(x, map, i) == 0)
            return (0);
}

int replace_boss(char **map, int x)
{
    int y = x / 2 - 1;
    if (connected_b(map, y, y, x) == 0)
        return (0);
    if (map[x / 2 - 1][x / 2] == 'B')
        map[x / 2 - 1][x / 2] = 'X';
    if (map[x / 2 - 1][x / 2 - 2] == 'B')
        map[x / 2 - 1][x / 2 - 2] = 'X';
    if (map[x / 2][x / 2 - 1] == 'B')
        map[x / 2][x / 2 - 1] = 'X';
    if (map[x / 2 - 2][x / 2 - 1] == 'B')
        map[x / 2 - 2][x / 2 - 1] = 'X';
    for (int i = x - 1; i != 0; --i)
        if (reduce_replace_boss(map, x, i) == 0)
            return (0);
}

void place_boss(char **map, int x)
{
    int *max = malloc(sizeof(int) * 4);
    max[0] = 0;
    for (int i = 0; i != x; ++i)
        another_boss_reduce(max, i, x, map);
    if (connected_room(map, max[1], max[2], x) == 3)
        map[max[1]][max[2]] = 'B';
    else
        place_r_boss(map, x);
    free(max);
}

void place_treasure_shop(char **map, int x, rooms *room)
{
    int treasure = rand() % my_intarray_len(room->verge);
    int shop = rand() % my_intarray_len(room->verge);

    while (treasure == shop)
        shop = rand() % my_intarray_len(room->verge);
    map[room->verge[treasure] / x][room->verge[treasure] % x] = 'T';
    map[room->verge[shop] / x][room->verge[shop] % x] = 'M';
}
