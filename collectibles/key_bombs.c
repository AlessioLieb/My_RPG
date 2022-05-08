/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** keys_bombs
*/

#include "../includes/motor.h"

void launch_key(player *py, room *rm, int i)
{
    if ((*(rm->keys[i].change))(py)) {
        rm->keys[i].pos_collision.left = -1;
        rm->keys[i].pos_collision.top = -1;
    }
}

void launch_bombs(player *py, room *rm, int i)
{
    if ((*(rm->bombs[i].change))(py)) {
        rm->bombs[i].pos_collision.left = -1;
        rm->bombs[i].pos_collision.top = -1;
    }
}

int add_bomb(player *py)
{
    py->invent.bomb++;
    return 1;
}

int add_key(player *py)
{
    py->invent.key++;
    return 1;
}

collectible *create_bomb_key(sfTexture *text, sfIntRect place,
int (*change)(player *py))
{
    collectible *bomb = malloc(sizeof(collectible) * 12);
    for (int i = 0; i < 10; ++i) {
        bomb[i].sp = sfSprite_create();
        sfSprite_setTexture(bomb[i].sp, text, sfTrue);
        sfSprite_setTextureRect(bomb[i].sp, place);
        bomb[i].change = change;
        bomb[i].pos_collision = (sfIntRect)
        {-1, -1, place.width * 3, place.height * 3};
        sfSprite_setScale(bomb[i].sp, (sfVector2f){3, 3});
    }
    return bomb;
}
