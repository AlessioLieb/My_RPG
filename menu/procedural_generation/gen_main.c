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
    create_rooms(room);
    if (room->init == false) {
        room->floor_rooms = malloc(sizeof(char *) * (x + 1));
        for (int i = 0; i != x; ++i) {
            room->floor_rooms[i] = malloc(x + 1);
            room->floor_rooms[i][x] = '\0';
        }
        room->floor_rooms[x] = NULL;
        room->init = true;
    }
    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x; ++j)
            room->floor_rooms[i][j] = ' ';
    room->floor_rooms = print_map(room->floor_rooms, x, room, room->lvl);
}
