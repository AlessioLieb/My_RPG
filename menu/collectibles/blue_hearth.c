/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** blue hearth
*/

#include "../includes/motor.h"

int add_blue_hearth(player *py)
{
    if (py->lf.blue_hearth >= 12)
        return 0;
    py->lf.blue_hearth += 2;
    return 1;
}

collectible *create_blue_hearth(sfTexture *text)
{
    collectible *b_hearth = malloc(sizeof(collectible) * 3);
    sfIntRect complete = (sfIntRect) {0, 14, 16, 13};
    for (int i = 0; i < 2; ++i) {
        b_hearth[i].sp = sfSprite_create();
        sfSprite_setTexture(b_hearth[i].sp, text, sfTrue);
        sfSprite_setTextureRect(b_hearth[i].sp, complete);
        b_hearth[i].change = &add_blue_hearth;
        b_hearth[i].pos_collision = (sfIntRect) {-1, -1, 16 * 3, 13 * 3};
        sfSprite_setScale(b_hearth[i].sp, (sfVector2f) {3, 3});
    }
    return b_hearth;
}

void got_blue_hearth(room *rm, int i, player *py)
{
    if ((*(rm->blue_hearth[i].change))(py)) {
        rm->blue_hearth[i].pos_collision.left = -1;
        rm->blue_hearth[i].pos_collision.top = -1;
    }
}