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
        for (int y = 0; y != 10; ++y) {
            if (ro->mini_map[x][y] == 'X') {
                pos.x += (y + 1) * (9 * 3.5);
                pos.y += (x + 1) * (8 * 3.5);
                sfSprite_setPosition(ro->n_room_known, pos);
                sfRenderWindow_drawSprite(wd, ro->n_room_known, NULL);
            }
            if (ro->mini_map[x][y] == 'x') {
                pos.x += (y + 1) * (9 * 3.5);
                pos.y += (x + 1) * (8 * 3.5);
                sfSprite_setPosition(ro->n_room_unknown, pos);
                sfRenderWindow_drawSprite(wd, ro->n_room_unknown, NULL);
            }
            if (ro->mini_map[x][y] == 'B') {
                pos.x += (y + 1) * (9 * 3.5);
                pos.y += (x + 1) * (8 * 3.5);
                sfSprite_setPosition(ro->b_room_known, pos);
                sfRenderWindow_drawSprite(wd, ro->b_room_known, NULL);
            }
            if (ro->mini_map[x][y] == 'b') {
                pos.x += (y + 1) * (9 * 3.5);
                pos.y += (x + 1) * (8 * 3.5);
                sfSprite_setPosition(ro->b_room_unknown, pos);
                sfRenderWindow_drawSprite(wd, ro->b_room_unknown, NULL);
            }
            if (ro->mini_map[x][y] == 'T') {
                pos.x += (y + 1) * (9 * 3.5);
                pos.y += (x + 1) * (8 * 3.5);
                sfSprite_setPosition(ro->t_room_known, pos);
                sfRenderWindow_drawSprite(wd, ro->t_room_known, NULL);
            }
            if (ro->mini_map[x][y] == 't') {
                pos.x += (y + 1) * (9 * 3.5);
                pos.y += (x + 1) * (8 * 3.5);
                sfSprite_setPosition(ro->t_room_unknown, pos);
                sfRenderWindow_drawSprite(wd, ro->t_room_unknown, NULL);
            }
            if (ro->mini_map[x][y] == 'M') {
                pos.x += (y + 1) * (9 * 3.5);
                pos.y += (x + 1) * (8 * 3.5);
                sfSprite_setPosition(ro->s_room_known, pos);
                sfRenderWindow_drawSprite(wd, ro->s_room_known, NULL);
            }
            if (ro->mini_map[x][y] == 'm') {
                pos.x += (y + 1) * (9 * 3.5);
                pos.y += (x + 1) * (8 * 3.5);
                sfSprite_setPosition(ro->s_room_unknown, pos);
                sfRenderWindow_drawSprite(wd, ro->s_room_unknown, NULL);
            }
            if (x == rm->actual_room[1] && y == rm->actual_room[0]) {
                pos.x = 1525;
                pos.y = 0;
                pos.x += (y + 1) * (9 * 3.5);
                pos.y += (x + 1) * (8 * 3.5);
                sfSprite_setPosition(ro->actual_room_sprite, pos);
                sfRenderWindow_drawSprite(wd, ro->actual_room_sprite, NULL);
            }
            pos.x = 1525;
            pos.y = 0;
        }
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

void init_nroom_sprites(rooms *ro)
{
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {64, 0, 9, 8};
    sfIntRect rect2 = {55, 0, 9, 8};
    ro->n_room_known = sfSprite_create();
    sfSprite_setTexture(ro->n_room_known, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->n_room_known, rect1);
    sfSprite_setScale(ro->n_room_known, room_scale);
    ro->n_room_unknown = sfSprite_create();
    sfSprite_setTexture(ro->n_room_unknown, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->n_room_unknown, rect2);
    sfSprite_setScale(ro->n_room_unknown, room_scale);
}

void init_broom_sprites(rooms *ro)
{
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {64, 16, 9, 8};
    sfIntRect rect2 = {55, 16, 9, 8};
    ro->b_room_known = sfSprite_create();
    sfSprite_setTexture(ro->b_room_known, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->b_room_known, rect1);
    sfSprite_setScale(ro->b_room_known, room_scale);
    ro->b_room_unknown = sfSprite_create();
    sfSprite_setTexture(ro->b_room_unknown, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->b_room_unknown, rect2);
    sfSprite_setScale(ro->b_room_unknown, room_scale);
}

void init_treasure_sprites(rooms *ro)
{
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {64, 8, 9, 8};
    sfIntRect rect2 = {55, 8, 9, 8};
    ro->t_room_known = sfSprite_create();
    sfSprite_setTexture(ro->t_room_known, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->t_room_known, rect1);
    sfSprite_setScale(ro->t_room_known, room_scale);
    ro->t_room_unknown = sfSprite_create();
    sfSprite_setTexture(ro->t_room_unknown, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->t_room_unknown, rect2);
    sfSprite_setScale(ro->t_room_unknown, room_scale);
}

void init_shop_sprites(rooms *ro)
{
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {64, 24, 9, 8};
    sfIntRect rect2 = {55, 24, 9, 8};
    ro->s_room_known = sfSprite_create();
    sfSprite_setTexture(ro->s_room_known, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->s_room_known, rect1);
    sfSprite_setScale(ro->s_room_known, room_scale);
    ro->s_room_unknown = sfSprite_create();
    sfSprite_setTexture(ro->s_room_unknown, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->s_room_unknown, rect2);
    sfSprite_setScale(ro->s_room_unknown, room_scale);
}

static void init_minimap_sprites(rooms *ro)
{
    sfIntRect rect = {0, 0, 55, 55};
    sfVector2f scale = {6, 6};
    sfVector2f pos = {1550, 0};
    sfVector2f room_scale = {3.5, 3.5};
    sfIntRect rect1 = {55, 40, 9, 8};

    ro->text = sfTexture_createFromFile("../Sprites/minimap.png", NULL);
    ro->map = sfSprite_create();
    sfSprite_setTexture(ro->map, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->map, rect);
    sfSprite_setScale(ro->map, scale);
    sfSprite_setPosition(ro->map, pos);
    ro->actual_room_sprite = sfSprite_create();
    sfSprite_setTexture(ro->actual_room_sprite, ro->text, sfTrue);
    sfSprite_setTextureRect(ro->actual_room_sprite, rect1);
    sfSprite_setScale(ro->actual_room_sprite, room_scale);
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
