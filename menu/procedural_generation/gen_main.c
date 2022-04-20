/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../includes/procedural.h"

void gen_main(rooms *room)
{
    srand(time(NULL));
    int x = 10;
    char **map = malloc(sizeof(char *) * (x + 1));
    create_rooms(room);
    for (int i = 0; i != x; ++i) {
        map[i] = malloc(x + 1);
        map[i][x] = '\0';
    }
    map[x] = NULL;
    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x; ++j)
            map[i][j] = ' ';
    room->floor_rooms = print_map(map, x, room, room->lvl);
}
