/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "procedural.h"

int main(int ac, char **av)
{
    srand(time(NULL));
    int x = 10;
    char **map = malloc(sizeof(char *) * x);
    rooms room;
    create_rooms(&room);
    for (int i = 0; i != x; ++i)
        map[i] = malloc(x);
    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x; ++j)
            map[i][j] = ' ';
    for (int j = 0; j != 5; ++j)
        print_map(map, x, &room, j);
    for (int i = 0; i != x; ++i)
        free(map[i]);
    free(map);
    free(room.lvl_rooms);
    free(room.verge);
}
