/*
** EPITECH PROJECT, 2022
** item
** File description:
** item for the tresor room
*/

#include "../includes/motor.h"

void launch_item(player *py, room *rm)
{
    if ((*(rm->item->change))(py)) {
        sfSprite_destroy(rm->item->sp);
        rm->item = NULL;
    }
}

void place_item(room *rm)
{
    sfTexture *text = sfTexture_createFromFile("../Sprites/Items/all_stats_up/1.png", NULL);
    collectible *item = malloc(sizeof(collectible));
    int choose = 0;
    srand(time(NULL));
    item->sp = sfSprite_create();
    sfSprite_setPosition(item->sp, (sfVector2f) {200, 200});
    sfSprite_setScale(item->sp, (sfVector2f) {3, 3});
    sfSprite_setTexture(item->sp, text, sfTrue);
    item->pos_collision = (sfIntRect) {200, 200, 75, 66};
    item->change = &item_speed;
    rm->item = item;
}