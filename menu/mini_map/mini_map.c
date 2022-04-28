/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-robin.denni
** File description:
** mini_map.c
*/

#include "../includes/motor.h"

void draw_mini_map(rooms *ro, sfRenderWindow *wd, room *rm)
{
    sfVector2f pos = {1525, 0};
    sfRenderWindow_drawSprite(wd, ro->map, NULL);
    for (int x = 0; x != 10; ++x) {
        reduce_draw_mini_map(x, rm, ro, wd);
        pos.x = 1525;
        pos.y = 0;
    }
}

void update_mini_map(rooms *ro, room *rm)
{
    int x = rm->actual_room[1];
    int y = rm->actual_room[0];

    if (ro->floor_rooms[x][y] == 'S' || ro->floor_rooms[x][y] == 'X')
        ro->mini_map[x][y] = 'X';
    if (x != 0 && (ro->floor_rooms[x - 1][y] == 'S'
    || ro->floor_rooms[x - 1][y] == 'X') && ro->mini_map[x - 1][y] != 'X')
        ro->mini_map[x - 1][y] = 'x';
    if (x != 9 && (ro->floor_rooms[x + 1][y] == 'S'
    || ro->floor_rooms[x + 1][y] == 'X') && ro->mini_map[x + 1][y] != 'X')
        ro->mini_map[x + 1][y] = 'x';
    if (y != 0 && (ro->floor_rooms[x][y - 1] == 'S'
    || ro->floor_rooms[x][y - 1] == 'X') && ro->mini_map[x][y - 1] != 'X')
        ro->mini_map[x][y - 1] = 'x';
    if (y != 9 && (ro->floor_rooms[x][y + 1] == 'S'
    || ro->floor_rooms[x][y + 1] == 'X') && ro->mini_map[x][y + 1] != 'X')
        ro->mini_map[x][y + 1] = 'x';
    reduce_boss_minimap(ro, rm);
    reduce_shop_minimap(ro, rm);
    reduce_treasure_minimap(ro, rm);
}

void clear_mini_map(rooms *ro)
{
    for (int i = 0; i != 10; ++i)
        for (int j = 0; j != 10; ++j)
            ro->mini_map[i][j] = ' ';
}

void init_mini_map(rooms *ro)
{
    ro->mini_map = malloc(sizeof(char *) * 11);
    for (int i = 0; i != 10; ++i) {
        ro->mini_map[i] = malloc(11);
        ro->mini_map[i][10] = '\0';
    }
    ro->mini_map[10] = NULL;
    init_minimap_sprites(ro);
    init_nroom_sprites(ro);
    init_broom_sprites(ro);
    init_treasure_sprites(ro);
    init_shop_sprites(ro);
}
