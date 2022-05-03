/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** inventory
*/

#include "../includes/motor.h"

int add_one_piece(player *py)
{
    ++py->invent.money;
    return 0;
}

int add_five_piece(player *py)
{
    py->invent.money += 5;
    return 0;
}

int add_ten_piece(player *py)
{
    py->invent.money += 10;
    return 0;
}

void launch_piece(player *py, room *rm, int i)
{
    if (!(*(rm->piece[i].change))(py)) {
        rm->piece[i].pos_collision.left = -1;
        rm->piece[i].pos_collision.top = -1;
    }
}

collectible *create_piece(sfTexture *text)
{
    collectible *piece = malloc(sizeof(collectible) * 12);
    for (int i = 0; i < 10; ++i) {
        piece[i].sp = sfSprite_create();
        sfSprite_setTexture(piece[i].sp, text, sfTrue);
        if (rand() % 2 == 0) {
            sfSprite_setTextureRect(piece[i].sp, (sfIntRect) {32, 0, 18, 13});
            piece[i].change = &add_one_piece;
        } else if (rand() % 5 == 0) {
            sfSprite_setTextureRect(piece[i].sp, (sfIntRect) {68, 0, 18, 13});
            piece[i].change = &add_ten_piece;
        } else {
            sfSprite_setTextureRect(piece[i].sp, (sfIntRect) {50, 0, 18, 13});
            piece[i].change = &add_five_piece;
        }
        piece[i].pos_collision = (sfIntRect) {-1, -1, 18 * 3, 13 * 3};
        sfSprite_setScale(piece[i].sp, (sfVector2f) {3, 3});
    }
    return piece;
}
