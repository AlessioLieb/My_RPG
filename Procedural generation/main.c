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
    char **map = malloc(sizeof(char *) * x + 1);
    rooms room;
    create_rooms(&room);
    for (int i = 0; i != x; ++i) {
        map[i] = malloc(x + 1);
        map[i][x] = '\0';
    }
    map[x] = NULL;
    for (int i = 0; i != x; ++i)
        for (int j = 0; j != x; ++j)
            map[i][j] = ' ';
    for (int j = 0; j != 5; ++j)
        print_map(map, x, &room, j);
    for (int i = 0; map[i] != NULL; ++i)
        free(map[i]);
    free(map);
    free(room.lvl_rooms);
    free(room.verge);
}
