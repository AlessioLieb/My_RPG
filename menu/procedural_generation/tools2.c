/*
** EPITECH PROJECT, 2022
** Procedural generation test
** File description:
** tools2.c
*/

#include "../includes/procedural.h"

int my_intarray_len(int *array)
{
    int count = 0;

    for (int i = 0; array[i] != '\0'; ++i)
        ++count;
    return (count);
}

void create_map(char **map, int j, int x, rooms *room)
{
    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x; ++j)
            map[i][j] = ' ';
    procedural_gen(map, x, room, j);
    place_boss(map, x);
    replace_boss(map, x);
    find_verge(map, x, room);
    break_walls(map, x);
    place_secret_room(map, x, room);
    place_treasure_shop(map, x, room);
    map[x / 2 - 1][x / 2 - 1] = 'S';
}

char **print_map(char **map, int x, rooms *room, int j)
{
    create_map(map, j, x, room);
    while (wrong_map(map, x) == 1)
        create_map(map, j, x, room);
    return (map);
}

int connected_room_fr(char **map, int x, int y, int len)
{
    int count = 0;

    if (y != len - 1 && map[x][y + 1] == 'X')
        ++count;
    if (y != 0 && map[x][y - 1] == 'X')
        ++count;
    if (x != len - 1 && map[x + 1][y] == 'X')
        ++count;
    if (x != 0 && map[x - 1][y] == 'X')
        ++count;
    return (count);
}

int connected_b(char **map, int x, int y, int len)
{
    if (y != len - 1 && map[x][y + 1] == 'B')
        return (1);
    if (y != 0 && map[x][y - 1] == 'B')
        return (1);
    if (x != len - 1 && map[x + 1][y] == 'B')
        return (1);
    if (x != 0 && map[x - 1][y] == 'B')
        return (1);
    return (0);
}
