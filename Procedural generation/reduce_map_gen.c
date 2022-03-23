/*
** EPITECH PROJECT, 2022
** Procedural generation test
** File description:
** reduce_map_gen.c
*/

#include "procedural.h"

int reduce_r_gen(int init_x1, int init_y1, char **map)
{
    ++init_x1;
    if (map[init_x1][init_y1] != 'S')
        map[init_x1][init_y1] = 'X';
    return (init_x1);
}

int reduce_l_gen(int init_x1, int init_y1, char **map)
{
    --init_x1;
    if (map[init_x1][init_y1] != 'S')
        map[init_x1][init_y1] = 'X';
    return (init_x1);
}

int reduce_d_gen(int init_x1, int init_y1, char **map)
{
    ++init_y1;
    if (map[init_x1][init_y1] != 'S')
        map[init_x1][init_y1] = 'X';
    return (init_y1);
}

int reduce_u_gen(int init_x1, int init_y1, char **map)
{
    --init_y1;
    if (map[init_x1][init_y1] != 'S')
        map[init_x1][init_y1] = 'X';
    return (init_y1);
}
